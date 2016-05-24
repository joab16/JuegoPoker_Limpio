#pragma once
using namespace std;

class Carta
{
	friend ostream & operator<<(ostream &, Carta &);
private:

	const int DIAMANTES = 1;
	const int PICAS = 2;
	const int CORAZONES = 3;
	const int TREBOLES = 4;

	int numeroCarta;
	int palo;

public:
	Carta(int, int);
	Carta();
	~Carta();
	void operator=(Carta &);
};

ostream & operator<<(ostream &, Carta &);