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

//solo borre coss que no se ocupban y le puse ms texto :)
void PruebaDealer::PruebaDealer::RepartirCartas()
{
	cout << "Los jugadores Alexa, Joab y Rodrigo tendran sus 2 cartas y estaran las 5 cartas comunitarias\n\n";

	d->deck = new Deck();
	if (d->deck != NULL)
	{
		cout << "Se formo el deck de cartas...\n";
	}

	d->jugadores.push_front(new Jugador("Alexa", 10000));
	d->jugadores.push_front(new Jugador("Joab", 20000));
	d->jugadores.push_front(new Jugador("Rodrigo", 30000));		
	
	if (!(d->jugadores.empty()))
	{
		cout << "Se anadieron los jugadores...\n";
	}
	
	cout << "Se reparten las cartas...\n\n";
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
		cout << (*it) << endl;
	};
	cout << endl;
	cout << endl;
}

void PruebaDealer::cartasComunitarias()
{
	cout << "Las comunitarias son: " << endl;
	for (list<Carta*>::iterator it = d->comunitarias.begin(); it != d->comunitarias.end(); it++)
	{
		cout << (*it) << endl;
	};
}