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
	int bote = 0;
	int ciegaPequenna;
	int ciegaGrande;
	int apuestaPequenna;
	int apuestaGrande;
	int ronda = 1; //ronda que se va jugando.
	int numeroJugadores;

public:

	Dealer();
	Dealer(int, int);

	~Dealer();

	void inicializarJuego(int, int);

	void repartirCartas();

	bool solicitarDecisiones(Jugador * it);

	char* seleccionarGanador(list<Deck*> manos);

	void repartirDinero();

	void llenarBote(int);

	list<Deck*> revelar();
};