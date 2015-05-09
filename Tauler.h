#include "Casella.h"
////Constants per al NIVELL 1///

const int FILES_NIVELL_1 = 9;
const int COL_NIVELL_1 = 9;
const int MINES_NIVELL_1 = 10;

////Constants per al NIVELL 2///

const int FILES_NIVELL_2 = 16;
const int COL_NIVELL_2 = 16;
const int MINES_NIVELL_2 = 40;

////Constants per al NIVELL 3///

const int FILES_NIVELL_3 = 16;
const int COL_NIVELL_3 = 30;
const int MINES_NIVELL_3 = 99;


/*
Creacio de la clase Tauler amb el constructor i la funcio obtenir el numero de mines
*/
class Tauler {
public:
	Tauler();
	~Tauler();
	Tauler(int files, int columnes, int nivell);
	void inicialitza(int mines);
	int getNumMines(Casella clicada) ;
private:
	int m_mines;
	int m_files;
	int m_columnes;
	///// Necesitem una matriu dinámica per tal de crear-la en temps d'execució depenent del nivell de joc escollit.///////
	Casella** m_tauler;
	Casella** creaTauler();
	void eliminaTauler(Casella**, int files);
	void ompleTauler(Casella**, int files, int col);

};