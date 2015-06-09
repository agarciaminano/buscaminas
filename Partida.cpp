#include "Partida.h"

Partida::Partida()
{

}

Partida::~Partida() 
{
	m_tauler.destrueixTauler();
}

void Partida::iniciaPartida(){
	cout << "Entra el teu nom: ";
	cin >> m_nom;
	m_tauler = Tauler(1);
	m_tauler.inicialitza();
	joc();

}
/*
* Bucle principal de una partida, s'encarrega de pintar el tauler, de demanar l'acció a realitzar 
*i de consultar quan s'ha acabat la partida.
*
*/
void Partida::joc(){
	char opc;
	int fila;
	int columna;
	bool jocAcabat = false;
	do {
		m_tauler.pintaTauler();
		cout << endl << "Que vols fer? (Marcar (M), Destapar(D) )";
		cin >> opc;
		cout << endl << "Indica fila i columna: ";
		cin >> fila;
		cin >> columna;
		if (opc == 'D')
		{
			if (m_tauler.destaparCasella(fila, columna));

		}
	} while (!jocAcabat);
	m_tauler.pintaTauler();
	m_tauler.destrueixTauler();

}

