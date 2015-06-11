#include "Tauler.h"
#include "Partida.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main() {
	char tecla;
	bool sortir = false;
	Partida p;
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
		cout << "Vols tornar a jugar? (S/N)";
		if (_getch() == 's')
			p.iniciaPartida();
		break;
	case 's': sortir = true;
		break;
	default:
		break;
	}

	} while (!sortir);
	
}