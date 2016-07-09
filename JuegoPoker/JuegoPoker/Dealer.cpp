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
	delete jugada;
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
	//for (int i = 0; i < 5 && finalizar != true; ++i) //reparte las cartas las 5 rondas o hasta que quede 1 jugador
	//{
		repartirCartas();
	/*}*/
}

void Dealer::repartirCartas()
{
	if (jugadores.size() != 1) //verifica que no quede solo un jugador, sino finaliza el juego :o
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
	else
	{
		finalizar();
	}
}

bool Dealer::solicitarDecisiones(Jugador * it)
{ //cambio esto porque en ningun monmento se le manda la mano para ver que calificacion se tiene :o
	bool seguir;
	double calificacion = jugada->obtenerCalificacion(it->mano);
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

// cambie de char * a Jugador * para que sea facil all repartir el dinero y asi. el parametro que recibia no servia, en mi opinion xd
Jugador * Dealer::seleccionarGanador()
{
	Jugador * ganador = NULL;
	list<Jugador*>::iterator jugador1 = jugadores.begin();
	list<Jugador*>::iterator jugador2 = ++jugador1;
	
	while (jugador1 != jugadores.end())
	{
		if (jugador2 != jugadores.end())
		{
			if (jugada->compararJugadas((*jugador1)->mano, (*jugador2)->mano) == 1)
			{
				ganador = (*jugador1);
				++jugador2;
			}
			else
			{
				ganador = (*jugador2);
				jugador1 = ++jugador2;
			}
		}
	}

	return ganador;
}

//se reparte dinero de una vez al ganador
void Dealer::repartirDinero(Jugador * ganador)
{
	ganador->dineroRestante = bote;
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

void Dealer::finalizar()
{
	Jugador * ganador = seleccionarGanador();
	if (ganador != NULL)
	{
		repartirDinero(ganador);
	}
}

// ale
ostream & operator<<(ostream & out, Dealer * d)
{
	d->imprimir(out);
	return out;
}
