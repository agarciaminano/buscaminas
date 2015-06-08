#include "Tauler.h"
#include "time.h"
#include <stdlib.h>  
#include <stdio.h> 
/**
* Constructor per defecte, necessitem com a mínim una dada de nivell per poder inicialitzar el tauler!
*/
Tauler::Tauler() {
	Tauler(1);
}
/**
* Crea el tauler a partir del nivell que rep com a parametre
* @param nivell nivell de dificultat del joc.
*/
Tauler::Tauler(int nivell){
	m_nivell = nivell;
	 ///Inicialització del tauler depenent del nivell de joc escollit
	inicialitza();

}

Tauler::~Tauler()
{
	destrueixTauler();
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
	destrueixTauler();
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
	while (contador <= m_mines){
		fila = rand() % m_files;
		columna = rand() % m_columnes;
		casellaMina = m_tauler[fila][columna];

		if (!casellaMina.getMina()){
			casellaMina.setMina();
			contador++;
		}
		//caso centro
		casellaMina = m_tauler[fila - 1][columna - 1];
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				casellaMina = m_tauler[fila + j][columna + i];
				casellaMina.incrementaValor();
			}

		}
	}


}

/*metode per obtenir el nombre de mines que te a voltant de la casella clicada "visible"

hem de recorre si es posible tot el voltant de les casella clicada. El total maxim per recorre es 8 i el minim 3


*/
int Tauler::getNumMines(Casella casellaClicada){
	int nombreMines;

	//hem de recorre el voltant de la casella


	return nombreMines;
}

void Tauler::marcaCasella(int fila, int columna)
{


}


bool Tauler::destaparCasella(int fila, int columna){
	m_tauler[fila][columna].setVisible(true);
}

/**
* Comproba si una casella conté una mina o bé conté un valor.
* Per fer-ho haura de comprobar que no estigui visible actualment.
* També verificarà si ja hem guanyat la partida.
*
*/
void Tauler::comprobarCasella(int x, int y){
	Casella casella;
	casella = m_tauler[x, y];
	if (!casella.getVisible()){
		if (casella.getMina()){
			//fi partida
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
		for (int j = 0; j < m_columnes; i++)
		{
		if (m_tauler[i][j].getMina())
			cout << "X";
		else if (m_tauler[i][j].getValor() == 0)
			cout << "[	]";
		else if (!m_tauler[i][j].getVisible())
			cout << "[]";
		else
			cout << "[" << m_tauler[i][j].getValor() << "]";
		}
	cout << endl;
}