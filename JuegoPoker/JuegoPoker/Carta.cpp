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

void Carta::operator=(Carta & otra)
{
	this->numeroCarta = otra.numeroCarta;
	this->palo = otra.palo;
}

int Carta::getValor()
{
	return this->numeroCarta;
}

int Carta::getPalo()
{
	return this->palo;
}
