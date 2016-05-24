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

	for (int i = 0; i < 5; i++) {
		comunitarias.push_front(deck->obtenerCarta());

	}
	for (list<Jugador*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		(*it)->añadirAMano(deck->obtenerCarta());
		(*it)->añadirAMano(deck->obtenerCarta());
	}
}

bool Dealer::solicitarDecisiones(Jugador * it)
{
	bool desicion;
	Jugadas jugada;
	float calificacion = jugada.obtenerCalificacion(); 
	if (it->tomarDecision(calificacion) == 0)
	{
		for (list<Jugador*>::iterator ite = jugadores.begin(); ite != jugadores.end(); ite++)
		{
			if (it == *ite)
			{
				list<Jugador*>::iterator tmp;
				jugadores.erase(tmp);
				ite = jugadores.end();
			}
		}
		desicion = false;
	}
	else
	{
		desicion = true;
	}
	return desicion;
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

