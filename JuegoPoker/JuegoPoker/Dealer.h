#pragma once

#include "Jugadas.h"
#include "Jugador.h"
#include "Deck.h"

class Dealer
{
	friend class PruebaDealer;
private:
	int turnoActual;
	Deck * deck;
	list<Carta*> comunitarias; // era list<Deck*>.
	list<Jugador*> jugadores;
	list<Jugador*> jugadoresActuales;
	int bote = 0;
	int ciegaPequenna;
	int ciegaGrande;
	int apuestaActual;
	int ronda = 1; //ronda que se va jugando.
	int numeroJugadores;


public:

	Dealer();
	Dealer(int, int);

	~Dealer();

	void inicializarJuego(int, int);

	void repartirCartas();

	int solicitarDecision(Jugador * it);

	void llenarBote(int);

	void rondaApuestas();

	void finalizarTurno();

	
};