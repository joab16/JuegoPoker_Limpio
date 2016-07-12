#pragma once

#include "Jugadas.h"
#include "Dealer.h"
#include "Deck.h"
#include "Carta.h"
#include "Jugador.h"

class PruebaJugadas
{
public:
	Dealer * d = new Dealer;
	PruebaJugadas();
	~PruebaJugadas();

	void validaPareja();

private:
	
};