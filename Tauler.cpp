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
* Destruccio de matriu dinámica!
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
* Creació de matriu dinámica!
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


void Tauler::setNivell(int nivell)
{
	m_nivell = nivell;
}

void Tauler::inicialitza(){

	//Destrueix tauler
	m_files = N_FILAS_I_COL * m_nivell;
	m_columnes = N_FILAS_I_COL * m_nivell;
	m_mines = 5 * m_nivell;
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
	Casella casellaMina;
	do {
		fila = rand() % m_files;
		columna = rand() % m_columnes;
		casellaMina = m_tauler[fila][columna];

		if (!casellaMina.getMina()){
			casellaMina.setMina();
			contador++;
		}
		/// Sempre agafem el máxim entre 0 i la fila actual -1 per no sortir-nos mai de la matriu.
		// Fem el mateix amb la columna
		int filNova = fmax(fila - 1, 0);
		int colNova = fmax(columna - 1, 0);		//Amb la part superior dreta tenim el mateix problema, per tant agafem el mínim
		int filMaxNova = fmin(fila + 1, m_files -1 );  // entre els dos valors per tal de no sortir-nos dels limits
		int colMaxNova = fmin(columna + 1, m_columnes - 1);
		casellaMina = m_tauler[filNova][colNova];
		for (int i = filNova; i < fmin(fila + 1, m_files); i++){
			for (int j = colNova; j < fmin(columna + 1, m_columnes); j++){
				casellaMina = m_tauler[i][j];
				casellaMina.incrementaValor();
			}

		} 
	} while (contador <= m_mines);


}

/*metode per obtenir el nombre de mines que te a voltant de la casella clicada "visible"

hem de recorre si es posible tot el voltant de les casella clicada. El total maxim per recorre es 8 i el minim 3


*/
int Tauler::getNumMines(Casella casellaClicada){
	int nombreMines = 1;

	//hem de recorre el voltant de la casella


	return nombreMines;
}

void Tauler::marcaCasella(int fila, int columna)
{


}

/*
* Destapa una casella del tauler, però no sempre es podrà fer, per tant comprova si
* la casella es trova actualment destapada, després de destapar-la comprova els atributs
* de la casella en concret.
*@return True si la casella s'ha pogut destapar, false en cas contrari.
*/
bool Tauler::destaparCasella(int fila, int columna){
	bool pot = true;
	if (m_tauler[fila][columna].getVisible())
		pot = false;
	else
		m_tauler[fila][columna].descobreixCasella();
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
	if (!casella.getVisible()){
		if (casella.getMina()){
			m_jocFinalitzat = true;
		}
		else{
			//sumar un punto
			if (getVeines(casella))
			{
				//pintar nombre veines
			}
			else{
			
				
			}//hem guanyat?
		}
	}
}

void Tauler::pintaTauler(){
	for (int i = 0; i < m_files; i++)
	{
		for (int j = 0; j < m_columnes; j++)
		{
			if (m_tauler[i][j].getMina())
				cout << "X";
			else if (!m_tauler[i][j].getVisible())
				cout << "[]";
			else if (m_tauler[i][j].getValor() == 0)
				cout << "[	]";
			else
				cout << "[" << m_tauler[i][j].getValor() << "]";
		}
		cout << endl;
	}
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

bool Tauler::getVeines(Casella c) {
	return NULL;
}