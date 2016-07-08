#include "stdafx.h"
#include "Dealer.h"
#include "Deck.h"

Dealer::Dealer()
{
	ronda = 1;
}

Dealer::Dealer(int ciegaPequenna, int numeroJugadores)
{
	inicializarJuego(ciegaPequenna, numeroJugadores);
}

Dealer::~Dealer()
{
	delete deck;
}

void Dealer::inicializarJuego(int ciegaPequena, int numeroJugador)
{
	deck = new Deck();
	int dinero;
	this->ciegaPequenna = ciegaPequena;
	this->ciegaGrande = 2 * ciegaPequena;
	this->numeroJugadores = numeroJugador;
	for (int i = 0; i < numeroJugadores; i++) {
		dinero = rand() % 40000 + 10000;
		jugadores.push_front(new Jugador("Alexa", dinero));
	}
	turnoActual = 0;
	bote = 0;
	aumento = false; //
	ronda = 1;
	repartirCartas();
}

void Dealer::repartirCartas()
{
	for (int i = 0; i < 5; i++) {
		comunitarias.push_front(deck->obtenerCarta());
	}
	for (list<Jugador*>::iterator it = jugadores.begin(); it != jugadores.end(); it++)
	{
		if (ronda == 1)
		{
			(*it)->añadirAMano(deck->obtenerCarta());
			(*it)->añadirAMano(deck->obtenerCarta());
		}
		else
		{
			if (solicitarDecisiones(*it))
			{
				(*it)->añadirAMano(deck->obtenerCarta());
			}
		}
	}
	++ronda;
	aumento = false; // termina esa ronda y comienza de nuevo el aumento;
}

bool Dealer::solicitarDecisiones(Jugador * it)
{ //cambio esto porque en ningun monmento se le manda la mano para ver que calificacion se tiene :o
	bool seguir;
	Jugadas jugada;
	double calificacion = jugada.obtenerCalificacion(it->mano);
	int decision = it->tomarDecision(calificacion);
	if (decision == 0) //decide retirarse
	{
		eliminarJugador(it);
		seguir = false;
	}
	else
	{
		seguir = true;
		if (decision == 2)//decide continuar y subir apuesta
		{
			aumento = true;
		}

		if (aumento)
		{
			bote += ciegaGrande + ciegaGrande;
		}
		else
		{
			bote += ciegaGrande;
		}
	}
	return seguir;
}

void Dealer::eliminarJugador(Jugador * jugador)
{
	list<Jugador*>::iterator ite = jugadores.begin();

	while ((*ite) != jugador && ite != jugadores.end())
	{
		++ite;
	}

	if (jugador == *ite)
	{
		jugadores.erase(ite);
	}
}
char* Dealer::seleccionarGanador(list<Deck*> manos)
{
	return nullptr;
}

void Dealer::repartirDinero()
{
}

void Dealer::llenarBote(int apuesta)
{
	bote += apuesta;
}

void Dealer::revelar()
{
	//return comunitarias;
}

//ale
void Dealer::imprimir(ostream & out)
{
	for (list<Jugador*>::iterator it = jugadores.begin(); it != jugadores.end(); ++it)
	{
		for (list<Carta *>::iterator ite = (*it)->mano.begin(); ite != (*it)->mano.end(); ++ite)
		{
			out << (*ite);
		}
		out << endl;
	}
}

// ale
ostream & operator<<(ostream & out, Dealer * d)
{
	d->imprimir(out);
	return out;
}
