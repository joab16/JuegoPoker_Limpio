#include "stdafx.h"
#include "Jugador.h"

/**
* @brief Constructor
* @param nombre char *
* @param dinero integer
*/
Jugador::Jugador(char * nombre, int dinero)
{
	this->nombre = nombre;
	this->dineroRestante = dinero;
	this->tipo = new TipoJugador();
}

/**
* @brief Destructor
*/
Jugador::~Jugador()
{
	delete tipo;
}

/**
* @brief Toma decision: seguir, retirarse, aumentar apuesta.
* @param calificacion double
* @return decision int
*/
int Jugador::tomarDecision(float calificacion)
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

/**
* @brief Agrega carta a la mano del jugador
* @param carta Carta *
*/
void Jugador::añadirAMano(Carta * carta)
{
	mano.push_front(carta);
}

//NUEVO
/**
* @brief Devuelve nombre del jugador
* @return nombre char *
*/
char * Jugador::getNombre()
{
	return this->nombre;
}

//NUEVO
/**
* @brief Devuelve mano de cartas del jugador
* @return mano list<Carta*>
*/
list<Carta*> Jugador::getMano()
{
	return this->mano;
}
