class Casella {

public:
	Casella();
	~Casella();
	Casella(bool mina);
	bool descobreixCasella();
	void setMarcada();
private:
	bool m_visible;
	bool m_marcada;
	bool m_minada;
	int m_valor;
};