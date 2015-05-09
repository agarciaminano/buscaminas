#include "Casella.h"
////NIVELL 1///

const int FILES_NIVELL_1 = 9;
const int COL_NIVELL_1 = 9;
const int MINES_NIVELL_1 = 10;

////NIVELL 2///

const int FILES_NIVELL_2 = 16;
const int COL_NIVELL_2 = 16;
const int MINES_NIVELL_2 = 40;

////NIVELL 3///

const int FILES_NIVELL_3 = 16;
const int COL_NIVELL_3 = 30;
const int MINES_NIVELL_3 = 99;

class Tauler {
public:
	Tauler();
	~Tauler();
	Tauler(int files, int columnes, int mines);
	void inicialitza();
	int getNumMines() const;
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