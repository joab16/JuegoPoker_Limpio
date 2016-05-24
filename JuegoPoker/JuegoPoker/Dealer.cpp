#include "stdafx.h"
#include "Dealer.h"
#include "Deck.h"

Dealer::Dealer()
{
}

Dealer::Dealer(int ciegaPequenna, int numeroJugadores)
{
	inicializarJuego(ciegaPequenna, numeroJugadores);
}

Dealer::~Dealer()
{
	delete deck;
}

void Dealer::inicializarJuego(int ciegaPequena, int numeroJugador)
{
	deck = new Deck();
	int dinero;
	this->ciegaPequenna = ciegaPequena;
	this->ciegaGrande = 2 * ciegaPequena;
	this->numeroJugadores = numeroJugador;
	for (int i = 0; i < numeroJugadores; i++) {
		dinero = rand() % 40000 + 10000;
		jugadores.push_front(new Jugador("Alexa", dinero));
	}
	turnoActual = 0;
	bote = 0;
	repartirCartas();
}

void Dealer::repartirCartas()
{
	if (turnoActual = 0)
	{
		for (list<Jugador*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
		{
			(*it)->añadirAMano(deck->obtenerCarta());
			(*it)->añadirAMano(deck->obtenerCarta());
		}
	}
	if (turnoActual = 1)
	{
		for (int i = 0; i < 3; i++)
			comunitarias.push_front(deck->obtenerCarta());
	}
	else if (turnoActual = 2)
	{
			comunitarias.push_front(deck->obtenerCarta());
	}
	else if (turnoActual = 3)
	{
			comunitarias.push_front(deck->obtenerCarta());
	}
}

bool Dealer::solicitarDecisiones(Jugador * jugador)
{
	return jugador->tomarDecision();
}



char* Dealer::seleccionarGanador(list<Deck*> manos)
{
	return nullptr;
}

void Dealer::repartirDinero()
{
}

void Dealer::llenarBote(int apuesta)
{
	bote += apuesta;
}

void Dealer::revelar()
{
//return comunitarias;
}

void Dealer::eliminarJugador(Jugador *jugador)
{
	{
		for (list<Jugador*>::iterator ite = jugadoresActuales.begin(); ite != jugadoresActuales.end(); ite++)
		{
			if (jugador == *ite)
				jugadores.erase(ite);
				ite = jugadores.end();
			}
		}
	}
}

void Dealer::subirApuesta()
{
}

