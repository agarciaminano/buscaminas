#include "Tauler.h"
#include "Partida.h"
#include <iostream>
using namespace std;

void main() {
	char tecla;
	bool sortir = false;
	Partida p;
	do
	{ 
	cout << "Jugar (J)" << endl;
	cout << "Mostrar puntuacions ordenades per nom (N)" << endl;
	cout << "Mostrar puntuacions ordenades per nivell (L)" << endl;
	cout << "Mostrar puntuacions ordenades per punts (P)" << endl;
	cout << "Sortir (S) " << endl << endl;
	cout << "Escull una opció: ";
	cin >> tecla;
	switch (tecla)
	{
	case 'j': 
		p = Partida();
		p.iniciaPartida();
		break;
	case 's': sortir = true;
		break;
	default:
		break;
	}

	} while (!sortir);
	
}