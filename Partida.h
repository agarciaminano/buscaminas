#include "Tauler.h"

const int MAX_DIGITS_NOM = 25;

class Partida {
public:
	Partida();
	~Partida();
	void iniciaPartida();
	void joc();
	int getPuntuacio();
	int getNivell();
	char* getNom();
	void destrueixTauler();
private:
	char m_nom[MAX_DIGITS_NOM];
	int m_puntuacio;
	int m_nivell;
	Tauler m_tauler;

};