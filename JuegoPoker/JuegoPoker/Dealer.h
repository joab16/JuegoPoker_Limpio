#pragma once

#include "Jugadas.h"
#include "Jugador.h"
#include "Deck.h"

using namespace std;
class Jugador;
class Dealer
{
	friend ostream & operator<<(ostream &, Dealer *);
	friend class PruebaDealer;
private:
	int turnoActual;
	Deck * deck;
	Jugadas * jugada; //para usarlo en tomardecision y seleccionarganador
	list<Carta*> comunitarias; // era list<Deck*>.
	list<Jugador *> jugadores;
	int bote = 0;
	int ciegaPequenna;
	int ciegaGrande;
	int apuestaPequenna;
	int apuestaGrande;
	int ronda; //ronda que se va jugando.
	int numeroJugadores;
	bool aumento;

	bool solicitarDecisiones(Jugador *);

	void eliminarJugador(Jugador * jugador);

	Jugador * seleccionarGanador();

	void repartirDinero(Jugador *);

	void llenarBote(int);

	void revelar();

	void imprimir(ostream &);

	void finalizar();

public:

	Dealer();
	Dealer(int, int);

	~Dealer();

	void inicializarJuego(int, int);
	void repartirCartas();
};

//ostream
ostream & operator<<(ostream &, Dealer *);