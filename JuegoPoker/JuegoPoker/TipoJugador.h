#pragma once
#include "Jugador.h"
#include "Carta.h"
#include "Jugadas.h"

class TipoJugador {
private:
	int apuestaMinima;
	int apuestaMaxima;
	list<Carta> mejorJugada;
	float probabilidadGane;

public:
	TipoJugador();

	TipoJugador(int, int, float);

	~TipoJugador();

	float probabilidadMinimaRetiro;

	int tomarDecision(float);

	float analizarProbabilidad(list<Carta*> &, list<Carta*> &);

	list<Carta*> encontrarMejorJugada(list<Carta*> &, list<Carta*> &);
};
