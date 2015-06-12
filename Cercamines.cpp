#include "Tauler.h"
#include "Partida.h"
#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;
/**
* Programa principal, s'encarrega de mostrar un menu a l'usuari per que esculli l'acció que dessitja, en cas
* de que vulgui jugar, inicia la partida i el control passa a la classe partida, aquesta classe torna a agafar el control
* un cop que la partida ha acabat.
*/
void main() {
	locale::global(locale("spanish"));
	char tecla,teclaTornar;
	bool sortir = false;
	Partida p = Partida();
	Puntuacions punt = Puntuacions(); 
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
		do {
			p.iniciaPartida();		
			punt.desaResultat(p.getResultat());
			cout << "Vols tornar a jugar? (S/N)";
			teclaTornar = _getch();
			p.destrueixTauler();
		}
		while ((teclaTornar == 's'));
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