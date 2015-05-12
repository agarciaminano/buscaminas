class Casella {

public:
	Casella();
	~Casella();
	Casella(bool mina);
	bool descobreixCasella();
	void setMarcada();
	bool getMina();
	void setMina();
	void incrementaValor();
private:
	bool m_visible;
	bool m_marcada;
	bool m_minada;
	int m_valor;
};