#include "stdafx.h"
#include "PruebaDealer.h"
using namespace std;

PruebaDealer::PruebaDealer() : Dealer()
{
	deck = new Deck();

	if (deck != NULL)
	{
		cout << "Se formo el deck de cartas...\n";
	}

	jugadores.push_front(new Jugador("Alexa", 10000));
	jugadores.push_front(new Jugador("Joab", 20000));
	jugadores.push_front(new Jugador("Rodrigo", 30000));

	if (!(jugadores.empty()))
	{
		cout << "Se anadieron los jugadores...\n";
	}

	repartir();
}


PruebaDealer::~PruebaDealer()
{
}

//solo borre coss que no se ocupban y le puse ms texto :)
void PruebaDealer::PruebaDealer::repartir()
{
	cout << "Se reparten las cartas...\n\n";
	repartirCartas();

	for (list<Jugador*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
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
	for (list<Carta*>::iterator it = comunitarias.begin(); it != comunitarias.end(); it++)
	{
		cout << (*it) << endl;
	};
}