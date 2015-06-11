#include "Partida.h"

Partida::Partida()
{

}

Partida::~Partida() 
{
	m_tauler.destrueixTauler();
}

void Partida::iniciaPartida(){
	system("cls");
	cout << "Entra el teu nom: ";
	cin >> m_nom;
	cout << "Escull el nivell de joc: ";
	int nivell;
	cin >> nivell;
	m_tauler = Tauler(nivell);
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
		m_tauler.pintaTaulerTest();
		cout << endl << "Que vols fer? (Marcar (M), Destapar(D)): ";
		cin >> opc;
		cout << endl << "Indica fila i columna: ";
		cin >> fila;
		cin >> columna;
		if (opc == 'd')
		{
			if (!m_tauler.destaparCasella(fila - 1, columna - 1))
				cout << "No es pot destapar la casella seleccionada" << endl;

		}
		else if (opc == 'm')
		{
			if (!m_tauler.marcaCasella(fila - 1, columna - 1))
				cout << "No es pot marcar la casella seleccionada" << endl;
		}
		jocAcabat = (m_tauler.jocGuanyat() || m_tauler.jocPerdut());
	} while (!jocAcabat);
	if (m_tauler.jocGuanyat())
		cout << "Has guanyat la partida!!" << endl;
	else
		cout << "Has perdut!!" << endl;
	
	m_tauler.pintaTaulerJocAcabat();
	m_tauler.destrueixTauler();

}

