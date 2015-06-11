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
	cin >> m_nivell;
	m_tauler = Tauler(m_nivell);
	m_puntuacio = 0;
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
		m_tauler.pintaTauler(m_puntuacio);
	//	m_tauler.pintaTaulerTest();
		cout << endl << "Que vols fer? (Marcar (M), Destapar(D)): ";
		cin >> opc;
		cout << endl << "Indica fila i columna: ";
		cin >> fila;
		cin >> columna;
		if (opc == 'd')
		{
			if (!m_tauler.destaparCasella(fila - 1, columna - 1))
				cout << "No es pot destapar la casella seleccionada" << endl;
			else if (m_tauler.jocPerdut())
				m_puntuacio++;

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
	
	m_tauler.pintaTaulerJocAcabat(m_puntuacio);
	m_tauler.destrueixTauler();
	
}


int Partida::getNivell(){
	return m_nivell;
}

int Partida::getPuntuacio(){
	return m_puntuacio;
}
char* Partida::getNom(){
	return m_nom;
}