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
		char integer_string[2];
		sprintf(integer_string, "%d", i);
		char* nombre = "Jugador";
		strcat(nombre, integer_string);
		dinero = rand() % 40000 + 10000;
		jugadores.push_front(new Jugador(nombre, dinero));
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

int Dealer::solicitarDecision(Jugador * it,list<Carta*> comunitarias)
{
	
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

