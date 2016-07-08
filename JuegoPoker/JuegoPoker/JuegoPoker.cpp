// JuegoPoker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include "Carta.h"
#include "PruebaDealer.h"

int main()
{
	srand(time(NULL));

	PruebaDealer l;
	l.RepartirCartas();

	Dealer * d = new Dealer(1, 2);
	d->repartirCartas();
	cout << d;
	delete d;

    return 0;
}

