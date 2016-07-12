// JuegoPoker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include "Carta.h"
#include "PruebaDealer.h"
#include "PruebaJugadas.h"

int main()
{
	srand(time(NULL));

	PruebaDealer l;
	l.RepartirCartas();

	PruebaJugadas j;
	j.validaPareja();

    return 0;
}

