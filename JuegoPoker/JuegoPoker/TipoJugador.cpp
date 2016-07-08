#include "stdafx.h"
#include "TipoJugador.h"

TipoJugador::TipoJugador()
{
	//estableci probablidad :)
	probabilidadMinimaRetiro = (rand() % 10) / 10;
}

TipoJugador::~TipoJugador()
{
}

double TipoJugador::analizarProbabilidad(list<Deck*>&)
{
	return 0.0;
}

list<Deck*> TipoJugador::encontrarMejorJugada(list<Deck*>&, list<Deck*>&)
{
	return list<Deck*>();
}
