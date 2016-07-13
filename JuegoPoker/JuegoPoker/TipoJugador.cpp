#include "stdafx.h"
#include "TipoJugador.h"

/**
* @brief Constructor.
*/
TipoJugador::TipoJugador()
{	
	probabilidadMinimaRetiro = (rand() % 10) / 10;
}

/**
* @brief Destructor
*/
TipoJugador::~TipoJugador()
{
}

list<Carta*> TipoJugador::getMejorJugada()
{
	return this->mejorJugada;;
}

void TipoJugador::setMejorJugada(list<Carta*>& jugada)
{
	this->mejorJugada = jugada;
}

float TipoJugador::getProbabilidad()
{
	return this->probabilidadGane;
}

void TipoJugador::setProbabilidad(float probabilidad)
{
	this->probabilidadGane = probabilidad;
}

float TipoJugador::analizarProbabilidad(list<Carta*>&comunitarias, list<Carta*>&mano)
{	
	Jugadas *j = new Jugadas();
	this->setProbabilidad(j->establecerPorcentajeExito(comunitarias, mano));
	this->mejorJugada = j->mejorJugada;
	return this->getProbabilidad();
}

list<Carta*> TipoJugador::encontrarMejorJugada(list<Carta*>&comunitarias, list<Carta*>&mano)
{
	return list<Carta*>();
}

