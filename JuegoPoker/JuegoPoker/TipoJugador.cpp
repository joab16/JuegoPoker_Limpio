#include "stdafx.h"
#include "TipoJugador.h"

/**
* @brief Constructor.
*/
TipoJugador::TipoJugador()
{
	//estableci probablidad :)
	probabilidadMinimaRetiro = (rand() % 10) / 10;
}

/**
* @brief Destructor
*/
TipoJugador::~TipoJugador()
{
}

float TipoJugador::analizarProbabilidad(list<Carta*>&comunitarias, list<Carta*>&mano)
{
	Jugadas *j = new Jugadas();
	j->establecerPorcentajeExito(comunitarias, mano);
	return 0.0f;
}

list<Carta*> TipoJugador::encontrarMejorJugada(list<Carta*>&comunitarias, list<Carta*>&mano)
{
	return list<Carta*>();
}

