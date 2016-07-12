/**
* @class PruebaDealer
* @brief Pruebas de dealer. Hija de Dealer.
*/

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

