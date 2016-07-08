#pragma once

#include "Jugadas.h"
#include "Jugador.h"
#include "Deck.h"

using namespace std;
class Dealer
{
	friend ostream & operator<<(ostream &, Dealer *);
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
	int ronda; //ronda que se va jugando.
	int numeroJugadores;
	bool aumento;

public:

	Dealer();
	Dealer(int, int);

	~Dealer();

	void inicializarJuego(int, int);

	void repartirCartas();

	bool solicitarDecisiones(Jugador *);

	void eliminarJugador(Jugador * jugador);

	char* seleccionarGanador(list<Deck*>);

	void repartirDinero();

	void llenarBote(int);

	void revelar();
	void imprimir(ostream &);
};

//ostream
ostream & operator<<(ostream &, Dealer *);