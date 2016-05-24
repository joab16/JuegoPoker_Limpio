#include "stdafx.h"
#include "Carta.h"

Carta::Carta(int numero, int palo)
{
	this->numeroCarta = numero;
	this->palo = palo;
}

Carta::Carta()
{
}

Carta::~Carta()
{
}

ostream & operator<<(ostream &cadena, Carta &carta)
{
	return cadena << "Numero: " << carta.numeroCarta << "\t Palo: " << carta.palo << endl;
}
