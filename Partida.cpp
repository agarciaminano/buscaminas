#include "Partida.h"

Partida::Partida()
{

}
/**
* Destructor de la classe.
*/
Partida::~Partida() 
{
	destrueixTauler(); //Destruim el tauler sempre que la partida s'acabi, ja que l'usuari pot tancar el joc sense haver acabat la partida
						// i d'aquesta manera ens assegurem que es destrueixi sempre el tauler.
}

/**
* Demana les dades a l'usuari (nom i nivell), inicialitza les variables de joc i el tauler.
*
*/
void Partida::iniciaPartida(){
	system("cls");
	cout << "Entra el teu nom: ";
	cin >> m_resultat.nom;
	cout << "Escull el nivell de joc: ";
	cin >> m_resultat.nivell;
	m_tauler = Tauler(m_resultat.nivell);
	m_resultat.puntuacio = 0;
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
		m_tauler.pintaTauler(m_resultat.puntuacio);
		cout << endl << "Que vols fer? (Marcar (M), Destapar(D)): ";
		cin >> opc;
		cout << endl << "Indica fila i columna: ";
		cin >> fila;
		cin >> columna;
		if (opc == 'd')
		{
			if (!m_tauler.destaparCasella(fila - 1, columna - 1))
				cout << "No es pot destapar la casella seleccionada" << endl;
			else if (!m_tauler.jocPerdut())
				m_resultat.puntuacio++;

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
	
	m_tauler.pintaTaulerJocAcabat(m_resultat.puntuacio);
	
	
}


/**
* Crida al mètode destrueixTauler de tauler per que alliberi recursos.
*/
void Partida::destrueixTauler() {
	m_tauler.destrueixTauler();
}

tResultat Partida::getResultat(){
	return m_resultat;
}