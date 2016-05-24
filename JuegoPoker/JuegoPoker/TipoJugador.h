#pragma once
#include "Jugador.h"
#include "Deck.h"

class TipoJugador {
private:
	int apuestaMinima;
	int apuestaMaxima;
	list<Deck> mejorJugada;
	float probabilidadGane;

public:
	TipoJugador();

	TipoJugador(int, int, float);

	~TipoJugador();

	float probabilidadMinimaRetiro;

	int tomarDecision(float);

	float analizarProbabilidad(list<Deck*> &);

	list<Deck*> encontrarMejorJugada(list<Deck*> &, list<Deck*> &);
};
