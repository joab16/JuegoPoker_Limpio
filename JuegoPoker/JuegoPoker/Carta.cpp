#include "stdafx.h"
#include "Carta.h"

/** 
* @brief Constructor. Asigna valores a las cartas.
* @param numero integer
* @param palo integer
*/
Carta::Carta(int numero, int palo)
{
	this->numeroCarta = numero;
	this->palo = palo;
}

/**
* @brief Constructor.
*/
Carta::Carta()
{

}

/**
* @brief Destructor.
*/
Carta::~Carta()
{

}

/**
* @brief Constructor. Asigna valores a las cartas.
* @param numero integer
* @param palo integer
*/
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

//se añade el ostream

/**
* @brief Sobrecarga del operador <<
* @param out ostream &
* @param c Carta *
*/
ostream & operator<<(ostream & out, Carta * c)
{
	out << " Numero: " << c->getValor() << " Palo: " << c->getPalo();
	return out;
}