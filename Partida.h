#include "Tauler.h"
#include "Puntuacions.h"
const int MAX_DIGITS_NOM = 25;

class Partida {
public:
	Partida();
	~Partida();
	void iniciaPartida();
	void joc();
	tResultat getResultat();
	void destrueixTauler();
private:
	tResultat m_resultat;
	Tauler m_tauler;

};