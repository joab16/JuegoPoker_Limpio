/**
* @class Deck
* @brief Cartas del juego.
*/
#pragma once
#include "stdafx.h"
#include "Carta.h"

using namespace std;

class Deck
{
private:

	list<Carta*> deck; /*!< lista Carta* deck*/

	Carta *carta; /*!< varible Carta* Carta */

public:

	Deck();

	~Deck();

	Carta* obtenerCarta();

	void revolverBaraja();

	void imprimir();

};



