#include "stdafx.h"
#include "PruebaDealer.h"
using namespace std;

PruebaDealer::PruebaDealer()
{
}


PruebaDealer::~PruebaDealer()
{
	delete d;
}

void PruebaDealer::PruebaDealer::RepartirCartas()
{
	d->deck = new Deck();
	list<Jugador*> prueba;
	list<Carta*> manos;
	d->jugadores.push_front(new Jugador("Alexa", 10000));
	d->jugadores.push_front(new Jugador("Joab", 20000));
	d->jugadores.push_front(new Jugador("Rodrigo", 30000));
	d->repartirCartas();
	for (list<Jugador*>::iterator it = d->jugadores.begin(); it != d->jugadores.end(); it++)
	{
		cartasJugadores((*it)->nombre, (*it)->mano);
	}
	cartasComunitarias();
}

void PruebaDealer::cartasJugadores(char* nombre, list<Carta*> mano)
{
	cout << "Las  cartas de " << nombre << " son: "<< endl;
	for (list<Carta*>::iterator it = mano.begin(); it != mano.end(); it++)
	{
		cout << " Palo: " << (*it)->getPalo() << " Numero: " << (*it)->getValor() << endl;
	};
	cout << endl;
	cout << endl;
}

void PruebaDealer::cartasComunitarias()
{
	cout << "Las comunitarias son: " << endl;
	for (list<Carta*>::iterator it = d->comunitarias.begin(); it != d->comunitarias.end(); it++)
	{
		cout << " Palo: " << (*it)->getPalo() << " Numero: " << (*it)->getValor() << endl;
	};
}