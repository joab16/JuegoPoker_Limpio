/**
* @class TipoJugador
* @brief Tipo de jugador del jugador.
*/

#pragma once
#include "Jugador.h"
#include "Carta.h"
#include "Jugadas.h"

#include "Deck.h"

class TipoJugador {

private:
	list<Carta*> mejorJugada; 
	float probabilidadGane; 

public:
	TipoJugador();

	~TipoJugador();

	float probabilidadMinimaRetiro;  /*!< varible double probabilidadMinimaRetiro */

	list<Carta*> getMejorJugada();
	void setMejorJugada(list<Carta*>&);

	float getProbabilidad();
	void setProbabilidad(float);

//borre tomar decision, no se ocupaba

	float analizarProbabilidad(list<Carta*> &, list<Carta*> &);

	list<Carta*> encontrarMejorJugada(list<Carta*> &, list<Carta*> &);
};
