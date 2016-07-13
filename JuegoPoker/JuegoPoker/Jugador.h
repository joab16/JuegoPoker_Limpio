/**
* @class Jugador
* @brief Jugador con sus atributos.
*/
#pragma once

#include "stdafx.h"
#include "TipoJugador.h"
#include "Dealer.h"

using namespace std;

class TipoJugador;
class Jugador
{
	//que jugador sea amigo de Dealer para que pueda usar todas las variables ya qu es el que lo crea y hace otras gestiones xd
	friend class Dealer;

private:
	int apuesta; /*!< varible integer apuesta*/
	int dineroRestante; /*!< varible integer dineroRestante. Dinero que posee el jugador.*/
	int decision; /*!< varible integer decision. Seguir, retirarse, aumentar apuesta.*/
	TipoJugador * tipo; /*!< varible TipoJugador * tipo.*/
	list<Carta*> mano; /*!< varible list<Carta*> mano.*/
	char * nombre; /*!< varible char * nombre*/

public:
	Jugador(char*, int);
	~Jugador();

	int tomarDecision(float);

	void añadirAMano(Carta *);

	char * getNombre();

	list<Carta*> getMano();
};
