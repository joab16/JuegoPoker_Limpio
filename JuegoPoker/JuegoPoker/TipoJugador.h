/**
* @class TipoJugador
* @brief Tipo de jugador del jugador.
*/

#pragma once

#include "Deck.h"

class TipoJugador {

private:
	int apuestaMinima;//no se sa
	int apuestaMaxima;//no se usa
	list<Deck> mejorJugada; //no se ha usado
	double probabilidadGane; //no se ha usado

public:
	TipoJugador();

	~TipoJugador();

	double probabilidadMinimaRetiro;  /*!< varible double probabilidadMinimaRetiro */

//borre tomar decision, no se ocupaba

	double analizarProbabilidad(list<Deck*> &);

	list<Deck*> encontrarMejorJugada(list<Deck*> &, list<Deck*> &);
};
