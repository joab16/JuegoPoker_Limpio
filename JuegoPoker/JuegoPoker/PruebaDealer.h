#pragma once

#include "Dealer.h"

class PruebaDealer : public Dealer
{
private:
	void cartasJugadores(char *, list<Carta*>);
	void cartasComunitarias();
	void repartir();

public:
	PruebaDealer();
	virtual ~PruebaDealer();
};

