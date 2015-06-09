class Casella {

public:
	Casella();
	~Casella();
	/////GETTERS I SETTERS//////////
	bool getVisible();
	bool getMina();
	int getValor();

	void setMarcada();
	void setMina();
	////////////////////////////////

	void descobreixCasella();
	void incrementaValor();
	
	
private:
	bool m_visible;
	bool m_marcada;
	bool m_minada;
	int m_valor;
};