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

//no se que hace
double TipoJugador::analizarProbabilidad(list<Deck*>&)
{
	return 0.0;
}
//no se que hace
list<Deck*> TipoJugador::encontrarMejorJugada(list<Deck*>&, list<Deck*>&)
{
	return list<Deck*>();
}
