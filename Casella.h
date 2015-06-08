class Casella {

public:
	Casella();
	~Casella();
	Casella(bool mina);
	/////GETTERS I SETTERS//////////
	bool getVisible();
	bool getMina();
	int getValor();

	void setMarcada();
	void setMina();
	////////////////////////////////

	bool descobreixCasella();
	void incrementaValor();
	void setVisible(bool b);
	
private:
	bool m_visible;
	bool m_marcada;
	bool m_minada;
	int m_valor;
};