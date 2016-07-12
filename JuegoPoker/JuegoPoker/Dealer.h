/**
* @class Dealer
* @brief Controla el juego.
*/

#pragma once

#include "Jugadas.h" //Posibles jugadas de las cartas
#include "Jugador.h" //Jugadores
#include "Deck.h" //Deck de cartas

using namespace std;

class Jugador;
class Dealer
{

	friend ostream & operator<<(ostream &, Dealer *);
	friend class PruebaDealer;

private:
	int turnoActual; //NO SE USA
	Deck * deck; /*!< varible Deck * deck. Deck de cartas para el juego.*/
	Jugadas * jugada; /*!< varible Jugadas * jugada. Llama metodos de Jugadas. */ //NUEVO: para usarlo en tomardecision y seleccionarganador
	list<Carta*> comunitarias; /*!< varible list<Carta*> comunitarias. Lista de cartas comunitarias.*/
	list<Jugador*> jugadores; /*!< varible list<Jugador*> jugadores. Lista de jugadores en el juego.*/
	int bote; /*!< varible integer bote. Dinero del bote.*/
	int ciegaPequenna; /*!< varible integer ciegaPequenna.*/
	int ciegaGrande; /*!< varible integer ciegaGrande.*/
	int apuestaPequenna; //NO SE USA
	int apuestaGrande; //NO SE USA
	int ronda; /*!< varible integer ronda. Ronda actual.*/ //NUEVO: ronda que se va jugando.
	int numeroJugadores; /*!< varible integer numeroJugadores. Cantidad de jugadores participantes.*/
	bool aumento; /*!< varible bool aumento. Indica si alguien aumento la apuesta.*/

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

//NUEVO: ostream
ostream & operator<<(ostream &, Dealer *);