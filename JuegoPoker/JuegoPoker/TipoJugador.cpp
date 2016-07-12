#include "stdafx.h"
#include "TipoJugador.h"

TipoJugador::TipoJugador()
{
}

TipoJugador::TipoJugador(int, int, float)
{
}

TipoJugador::~TipoJugador()
{
}

int TipoJugador::tomarDecision(float)
{
	return 0;
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

