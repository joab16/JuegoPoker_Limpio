#include "stdafx.h"
#include "Jugador.h"

Jugador::Jugador(char * nombre, int dinero)
{
	this->nombre = nombre;
	this->dineroRestante = dinero;
	this->tipo = new TipoJugador();
}

Jugador::~Jugador()
{
	delete tipo;
}

int Jugador::tomarDecision(double calificacion)
{
	if (calificacion <= tipo->probabilidadMinimaRetiro)
		decision = 1;
	else if (calificacion == 1)
	{
		decision = 2;
		//quite lo de apuesta, se hace de una en dealer.
	}
	else
		decision = 0;
	return decision;
}

void Jugador::añadirAMano(Carta * carta)
{
	mano.push_front(carta);
}