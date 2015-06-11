#pragma once
#include "Casella.h"
#include <iostream>
#include <math.h>
using namespace std;

const int N_FILAS_I_COL = 5;



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


	bool marcaCasella(int fila, int columna);
	bool destaparCasella(int fila, int columna);

	
	void comprobarCasella(int x, int y);
	void pintaTauler();
	void pintaTaulerTest();
	void pintaTaulerJocAcabat();

private:

	//// VARIABLES DE JOC ////
	int m_mines;
	int m_files;
	int m_columnes;
	int m_nivell;
	int m_casellesDestapades;
	int m_puntuacio;
	bool m_jocFinalitzat;
	bool m_jocGuanyat;
	void destapaRecursiu(int x, int y);
	int m_casellaExplotadaX;
	int m_casellaExplotadaY;
	/////////////////////////

	///// Necesitem una matriu dinámica per tal de crear-la en temps d'execució depenent del nivell de joc escollit.///////
	Casella** m_tauler;
	void creaTauler();
	void ompleTauler();


};