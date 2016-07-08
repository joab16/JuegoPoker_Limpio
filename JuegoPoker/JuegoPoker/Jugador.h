#pragma once

#include "stdafx.h"
#include "TipoJugador.h"
#include "Carta.h"

using namespace std;

class TipoJugador;

class Jugador
{
private:

	int apuesta;

	int dineroRestante;

	int decision;

	TipoJugador * tipo;

public:

	Jugador(char*, int);

	~Jugador();

	int tomarDecision(double);

	void aņadirAMano(Carta *);

	list<Carta*> mano;

	char* nombre;
};
