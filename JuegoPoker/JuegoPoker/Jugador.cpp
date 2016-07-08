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

int Jugador::tomarDecision(float calificacion)
{
	if (calificacion <= tipo->probabilidadMinimaRetiro)
		decision = 1;
	else if (calificacion == 1)
	{
		decision = 2;
		this->apuesta = 10; //no estoy clara cuánto puede subir.
	}
	else
		decision = 0;
	return decision;
}

void Jugador::añadirAMano(Carta * carta)
{
	mano.push_front(carta);
}