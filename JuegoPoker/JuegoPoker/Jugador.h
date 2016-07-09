#pragma once

#include "stdafx.h"
#include "TipoJugador.h"
#include "Dealer.h"

using namespace std;

class TipoJugador;

class Jugador
{
	//que jugador sea amigo de Dealer para que pueda usar todas las variables ya qu es el que lo crea y hace otras gestiones xd
	friend class Dealer;
private:

	int apuesta;

	int dineroRestante;

	int decision;

	TipoJugador * tipo;

public:

	Jugador(char*, int);

	~Jugador();

	int tomarDecision(double);

	void añadirAMano(Carta *);

	list<Carta*> mano;

	char* nombre;
};
