#include "Tauler.h"

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
	 ///Inicialització del tauler depenent del nivell de joc escollit
	switch (nivell)
	{
	case 1: m_files = FILES_NIVELL_1;
			m_columnes = COL_NIVELL_1;
			m_mines = MINES_NIVELL_1;
			break;
	case 2: m_files = FILES_NIVELL_2;
			m_columnes = COL_NIVELL_2;
			m_mines = MINES_NIVELL_2;
			break;
	case 3: m_files = FILES_NIVELL_3;
			m_columnes = COL_NIVELL_3;
			m_mines = MINES_NIVELL_3;
			break;

	default:
		break;
	}


}

Tauler::~Tauler()
{
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

void Tauler::inicialitza(int nivell){

	//while(mines > 0 ){
//	random casella per posar les mines mentres mines > 0
	//mines--:

}
/*metode per obtenir el nombre de mines que te a voltant de la casella clicada "visible"

hem de recorre si es posible tot el voltant de les casella clicada. El total maxim per recorre es 8 i el minim 3


*/
int Tauler::getNumMines(Casella casellaClicada){
	int nombreMines;

	//hem de recorre el voltant de la casella


	return nombreMines;
}