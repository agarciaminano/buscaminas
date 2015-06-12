#include "Tauler.h"
#include "time.h"
#include <stdlib.h>  
#include <stdio.h> 
/**
* Constructor per defecte, necessitem com a mínim una dada de nivell per poder inicialitzar el tauler!
* Per tant aquest constructor NO ES POT UTILITZAR!
*/
Tauler::Tauler() {
	m_files = 0;
	m_columnes = 0;
	m_tauler = NULL;
}
/**
* Crea el tauler a partir del nivell que rep com a parametre
* @param nivell nivell de dificultat del joc.
*/
Tauler::Tauler(int nivell){
	m_nivell = nivell;
	 ///Inicialització del tauler depenent del nivell de joc escollit
	

}

Tauler::~Tauler()
{
	
}

/*
* Destruccio de matriu dinàmica!
*
*/
void Tauler::destrueixTauler() {

	for (int i = 0; i < m_files; i++)
	{
		delete[] m_tauler[i];
	}
	delete[] m_tauler;
}



/*
* Creació de matriu dinàmica!
*
*/
void Tauler::creaTauler() {
	Casella** matriu;

	matriu = new Casella*[m_files];
	for (int i = 0; i < m_files; i++)
	{
		matriu[i] = new Casella[m_columnes];
	}
	m_tauler = matriu;
}




/*
*
* Inicialitza el tauler amb les dades per defecte (segons el nivell de joc escollit.
* També col·loca les mines de forma aleatòria.
*
*/

void Tauler::inicialitza(){

	//Destrueix tauler
	m_casellesDestapades = 0;
	m_casellaExplotadaX = -1; //Guardem la posició de la casella explotada perque es més eficient guardar dues coordenades
	m_casellaExplotadaY = -1; //a crear un nou atribut a la classe casella. (nomès una casella podrà explotar)
	m_files = N_FILAS_I_COL * m_nivell;
	m_columnes = N_FILAS_I_COL * m_nivell;
	m_mines = N_FILAS_I_COL * m_nivell;
	m_jocFinalitzat = false;
	m_jocGuanyat = false;
	creaTauler();
	
	//Afegim les mines
	afegirMines();

}





/*
Metode per afegir mines al inicialitzar la partida
*/
void Tauler::afegirMines(){

	int fila, columna;
	srand(time(NULL));

	int contador = 0;
	
	do {
		fila = rand() % m_files;
		columna = rand() % m_columnes;
		if (!m_tauler[fila][columna].getMina()){
			m_tauler[fila][columna].setMina();
			contador++;
			/// Sempre agafem el máxim entre 0 i la fila actual -1 per no sortir-nos mai de la matriu.
			// Fem el mateix amb la columna
			int filNova = fmax(fila - 1, 0);
			int colNova = fmax(columna - 1, 0);		//Amb la part superior dreta tenim el mateix problema, per tant agafem el mínim
			int filMaxNova = fmin(fila + 1, m_files - 1);  // entre els dos valors per tal de no sortir-nos dels limits
			int colMaxNova = fmin(columna + 1, m_columnes - 1);

			for (int i = filNova; i <= filMaxNova; i++){
				for (int j = colNova; j <= colMaxNova; j++){
					m_tauler[i][j].incrementaValor();

				}

			}
		}
		
		
	
	} while (contador < m_mines);


}

/*
*
* Mètode per obtenir el nombre de mines veines.
* @param casellaClicada: casella sobre la que volem consultar
* @return nombre total de mines veines.
*/
int Tauler::getNumMines(Casella casellaClicada){


	return casellaClicada.getValor();
}
/**
*
* Permet marcar una casella, si la casella ja es troba marcada la desmarcarà, tambè comproba que la casella
* escollida no es trobi fora dels limits de la matriu.
* @param fila: fila que es vol marcar
* @param columna: columna que es vol marcar
* @return false si no s'ha pogut marcar la casella, true en cas contrari.
*/
bool Tauler::marcaCasella(int fila, int columna)
{
	bool pot = true;
	if ((m_tauler[fila][columna].getVisible()) || (columna >= m_columnes)
		|| (fila >= m_files) || (columna < 0) || (fila < 0))
		pot = false;
	else
		if (m_tauler[fila][columna].getMarcada())
			m_tauler[fila][columna].setMarcada(false);
		else
			m_tauler[fila][columna].setMarcada(true);
	return pot;

}
/*
* Mètode per destapar les caselles sense mines veines de forma recursiva
*
*/
void Tauler::destapaRecursiu(int x, int y)
{

	int filNova = fmax(x - 1, 0);
	int colNova = fmax(y - 1, 0);		//Amb la part superior dreta tenim el mateix problema, per tant agafem el mínim
	int filMaxNova = fmin(x + 1, m_files - 1);  // entre els dos valors per tal de no sortir-nos dels limits
	int colMaxNova = fmin(y + 1, m_columnes - 1);
	m_tauler[x][y].descobreixCasella(); // Descobrim la casella i incrementem el comptador, però no la puntuació.
	m_casellesDestapades++;
	if (!getVeines(m_tauler[x][y]))    // Si la casella no té mines veines començem el mateix procès recursiu per a totes les caselles 
		for (int i = filNova; i <= filMaxNova; i++) //	adjacents. En cas de que tingui mines veines no fem res.
			for (int j = colNova; j <= colMaxNova; j++)
				if (!m_tauler[i][j].getVisible()) //També ens assegurem que la casella no sigui visible, 
					destapaRecursiu(i, j);			//ja que sinò mai acabaria la recursivitat.
									

			
		
	
}

/*
* Destapa una casella del tauler, però no sempre es podrà fer, per tant comprova si
* la casella es trova actualment destapada, després de destapar-la comprova els atributs
* de la casella en concret.
*@return True si la casella s'ha pogut destapar, false en cas contrari.
*/
bool Tauler::destaparCasella(int fila, int columna){
	bool pot = true;
	if ((m_tauler[fila][columna].getVisible()) || (columna >= m_columnes) 
		|| (fila >= m_files) || (columna < 0) || (fila < 0) || (m_tauler[fila][columna].getMarcada()))
			pot = false;
	else{
		m_tauler[fila][columna].descobreixCasella();
		comprobarCasella(fila, columna);
	}
	return pot;
}

/**
* Comproba si una casella conté una mina o bé conté un valor.
* Per fer-ho haura de comprobar que no estigui visible actualment.
* També verificarà si ja hem guanyat la partida.
*
*/
void Tauler::comprobarCasella(int x, int y){
	Casella casella;
	casella = m_tauler[x][y];
		if (casella.getMina()){
			m_jocFinalitzat = true;
			m_casellaExplotadaX = x;
			m_casellaExplotadaY = y;
		}
		else{
			///Si ja hem destapat totes les caselles possibles guanyem el joc
		
			 if (!getVeines(casella))
			{
				destapaRecursiu(x, y); //Si la casella no té cap mina veina començem el procès recursiu.
			}
			else
				m_casellesDestapades++;
			if (m_casellesDestapades == ((m_files*m_columnes) - m_mines))
			{
				m_jocGuanyat = true;
			}
		}
	
}

/*
* Dibuixa el tauler en pantalla, segons l'element que hi hagi dibuixarà diferents caràcters.
* Si la casella no es visible dibuixarà []
* Si la casella es visible pero no té mines adjacents dibuixara [	]
* Si la casella té una mina dibuixarà X
* Si la casella està marcada dibuixara [?]
*/
void Tauler::pintaTauler(int puntuacio){
	cout << "    ";
	for (int i = 0; i < m_files; i++)
		if (i < 9)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << " ";
	cout << endl;
	for (int i = 0; i < m_files; i++)
	{
		if (i < 9)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << " ";
		
		for (int j = 0; j < m_columnes; j++)
		{
			if (m_tauler[i][j].getMarcada())
				cout << "[?]";
			 else if (!m_tauler[i][j].getVisible())
				cout << "[ ]";
			 else if (m_tauler[i][j].getMina())
					cout << " X ";
			 else if (getVeines(m_tauler[i][j]))
				 cout << "[" << m_tauler[i][j].getValor() << "]";
			else  
				cout << "   ";
			
		}
		cout << endl;
		
	}
	cout << "Puntuacio: " << puntuacio << endl;
}

/**
* Mètode encarregat de pintar el tauler un cop acabat el joc, es diferencia de pintarTauler bàsicament
* per que hem de mostrar totes les caselles i les seves mines, com que aquesta situació nomès es produirà
* un cop en tot el joc (al acabar) es més eficient fer-ho en un mètode apartat.
*/
void Tauler::pintaTaulerJocAcabat(int puntuacio)
{
	cout << "    ";
	for (int i = 0; i < m_files; i++)
		if (i < 9)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << " ";
	cout << endl;
	for (int i = 0; i < m_files; i++)
	{
		if (i < 9)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << " ";
		for (int j = 0; j < m_columnes; j++)
		{

			if (i == m_casellaExplotadaX && j == m_casellaExplotadaY)
				cout << " X ";
			else if (m_tauler[i][j].getMina())
				cout << "[*]";
			else if (!m_tauler[i][j].getVisible())
				cout << "[ ]";
			else if (getVeines(m_tauler[i][j]))
				cout << "[" << m_tauler[i][j].getValor() << "]";
		
			else
				cout << "   ";

		}
		cout << endl;
	
	}
	cout << "Puntuacio: " << puntuacio << endl;
}

/*
*@return True en cas d'haver guanyat el joc, false en cas contrari.
*/
bool Tauler::jocGuanyat()
{
	return m_jocGuanyat;
}



/*
*@return True en cas d'haver perdut el joc, false en cas contrari.
*/
bool Tauler::jocPerdut(){
	return m_jocFinalitzat;
}

/**
* Retorna si la casella passada com a argument té alguna mina veina.
*
*/
bool Tauler::getVeines(Casella c) {
	return (c.getValor() > 0);
}