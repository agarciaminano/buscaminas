#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <conio.h>
/*
 * iomanip:
 * cout << setw(4) << "h"; // fixa l'amplada de camp a 4. Imprimeix "   h"
 * cout << left << setw(4) << "h"; // left alinia a l'esquerra. Imprimeix "h   "
 * cout << right << setw(4) << "h"; // right alinia a la dreta. Imprimeix "   h"
 */
using namespace std;

// Nom de l'arxiu
const string ARXIU_RESULTATS = "resultats.txt";

// Estructura que representa una entrada del llistat
typedef struct{
	string nom;
	int nivell;
	int puntuacio;
} tResultat; 

// Criteris d'ordenació
typedef enum {ORDRE_NOM, ORDRE_NIVELL, ORDRE_PUNTUACIO} CriteriOrdenacio;

/**
 * Class Puntuacions
 * 
 * Permet gestionar un conjunt de puntuacions i ordenar les entrades segons
 * diversos criteris.
 * L'ordenació es realitza amb l'algorisme QuickSort
 */
class Puntuacions
{
public:
	Puntuacions(void);
	~Puntuacions(void);
	void desaResultat(tResultat);
	void veureOrdenatPerNom(void);
	void veureOrdenatPerNivell(void);
	void veureOrdenatPerPuntuacio(void);
	void mostrar(void);
private:
	tResultat* m_llistat;
	int m_numElements;
	CriteriOrdenacio m_criteri;
	void m_llegirLlistat(void);
	void m_ordenar(int, int);
	int m_seleccionarPivot(int, int);
	void m_dividirVector(int, int, int&);
	void m_intercanviar(int, int);
};

