#pragma once
#include "Jugador.h"
#include "Deck.h"

class TipoJugador {
private:
	int apuestaMinima;
	int apuestaMaxima;
	list<Deck> mejorJugada;
	double probabilidadGane;

public:
	TipoJugador();

	~TipoJugador();

	double probabilidadMinimaRetiro;

//borre tomar decision, no se ocupaba

	double analizarProbabilidad(list<Deck*> &);

	list<Deck*> encontrarMejorJugada(list<Deck*> &, list<Deck*> &);
};
