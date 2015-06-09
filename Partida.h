#include "Tauler.h"

const int MAX_DIGITS_NOM = 25;

class Partida {
public:
	Partida();
	~Partida();
	void iniciaPartida();
	void joc();
private:
	char m_nom[MAX_DIGITS_NOM];
	Tauler m_tauler;

};