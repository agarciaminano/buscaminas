#include "Casella.h"

Casella::Casella(){
	m_visible = false;
	m_marcada = false;
	m_minada = false;
	m_valor = 0;
	
}
Casella::~Casella(){

}


bool Casella::getVisible(){
	return m_visible;
}

bool Casella::getMina(){
	return m_minada;
}
int Casella::getValor(){
	return m_valor;
}

void Casella::setMarcada(){
	m_marcada = true;
}

void Casella::setMina(){
	m_minada = true;
}


void Casella::descobreixCasella(){
	m_visible = true;
}
void Casella::incrementaValor(){
	m_valor += 1;
}
