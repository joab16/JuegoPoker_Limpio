#pragma once

#include "Deck.h"
#include "Dealer.h"
#include "Jugador.h"
#include "Carta.h"

class PruebaDealer
{
public:
	Dealer * d = new Dealer;
	PruebaDealer();
	~PruebaDealer();
	void cartasJugadores(char * nombre, list<Carta*> mano);
	void cartasComunitarias();
	void RepartirCartas();

	
};
