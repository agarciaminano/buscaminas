#pragma once
#include "Casella.h"
#include <iostream>
#include <math.h>
using namespace std;

const int N_FILAS_I_COL = 5;

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

	Tauler(int nivell);
	void destrueixTauler();

	void inicialitza();
	void afegirMines();
	/////GETTERS I SETTERS/////////
	int getNumMines(Casella clicada);
	bool getVeines(Casella casella);
	bool jocGuanyat();
	bool jocPerdut();
	void setNivell(int nivell);
	//////////////////////////////


	void marcaCasella(int fila, int columna);
	bool destaparCasella(int fila, int columna);

	
	void comprobarCasella(int x, int y);
	void pintaTauler();

private:

	//// VARIABLES DE JOC ////
	int m_mines;
	int m_files;
	int m_columnes;
	int m_nivell;
	bool m_jocFinalitzat;
	bool m_jocGuanyat;
	/////////////////////////

	///// Necesitem una matriu dinámica per tal de crear-la en temps d'execució depenent del nivell de joc escollit.///////
	Casella** m_tauler;
	void creaTauler();
	void ompleTauler();


};