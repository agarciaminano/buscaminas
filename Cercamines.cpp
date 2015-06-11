#include "Tauler.h"
#include "Partida.h"
#include <iostream>
#include <conio.h>
#include "Puntuacions.h"
#include <locale.h>
using namespace std;

void main() {
	locale::global(locale("spanish"));
	char tecla;
	bool sortir = false;
	Partida p;
	Puntuacions punt;
	tResultat resul;
	do
	{ 
	system("cls");
	cout << "Jugar (J)" << endl;
	cout << "Mostrar puntuacions ordenades per nom (N)" << endl;
	cout << "Mostrar puntuacions ordenades per nivell (L)" << endl;
	cout << "Mostrar puntuacions ordenades per punts (P)" << endl;
	cout << "Sortir (S) " << endl << endl;
	cout << "Escull una opció: ";
	tecla = _getch();
	switch (tecla)
	{
	case 'j': 
		p = Partida();
		p.iniciaPartida();
		resul.nom = p.getNom();
		resul.nivell = p.getNivell();
		resul.puntuacio = p.getPuntuacio();
		punt.desaResultat(resul);
		cout << "Vols tornar a jugar? (S/N)";
		if (_getch() == 's')
			p.destrueixTauler();
			p.iniciaPartida();
		break;
	case 's': sortir = true;
		break;
	case 'n': punt.veureOrdenatPerNom();
		
		break;
	case 'l': punt.veureOrdenatPerNivell();
		
		break;
	case 'p': punt.veureOrdenatPerPuntuacio();
		
		break;
	default:
		break;
	}

	} while (!sortir);
	
}