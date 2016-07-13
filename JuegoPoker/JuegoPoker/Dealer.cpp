#include "stdafx.h"
#include "Dealer.h"
#include "Deck.h"

/**
* @brief Constructor (exclusivo para pruebaDealer). Estable que está en la ronda 1.
*/
Dealer::Dealer()
{
	ronda = 1;
}

/**
* @brief Constructor. Llama a incializar juego.
* @param ciegaPequenna integer
* @param numeroJugadores integer
*/
Dealer::Dealer(int ciegaPequenna, int numeroJugadores)
{
	inicializarJuego(ciegaPequenna, numeroJugadores);
}

/**
* @brief Destructor.
*/
Dealer::~Dealer()
{
	delete deck;
	delete jugada;
}

/**
* @brief Inicia el juego.
* @param ciegaPequenna integer
* @param numeroJugadores integer
*/
void Dealer::inicializarJuego(int ciegaPequena, int numeroJugador)
{
	deck = new Deck();
	int dinero;
	this->ciegaPequenna = ciegaPequena;
	this->ciegaGrande = 2 * ciegaPequena;
	this->numeroJugadores = numeroJugador;
	
	for (int i = 0; i < this->numeroJugadores; i++) 
	{
		dinero = rand() % 40000 + 10000;
		jugadores.push_front(new Jugador("Alexa", dinero));
	}
	
	bote = 0;
	aumento = false; //NUEVO
	ronda = 1;
	for (int i = 0; i < 5 && this->jugadores.size() == 1; ++i) //reparte las cartas las 5 rondas o hasta que quede 1 jugador. Esta comentado hasta que este lo de jugadas :)
	{
		repartirCartas();
	}
	this->finalizar();
}

/**
* @brief Reparte las cartas.
*/
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
			//(*it)->
		}
		++ronda;
		aumento = false; // termina esa ronda y comienza de nuevo el aumento;
	}
	else
	{
		finalizar();
	}
}

/**
* @brief Solicita la decision del jugado: sigue, se retira o aumenta.
* @param jugador Jugador *
* @return decicion bool
*/
bool Dealer::solicitarDecisiones(Jugador * jugador)
{ //cambio esto porque en ningun monmento se le manda la mano para ver que calificacion se tiene :o Antes se mandaba Carta * mano[]
	bool seguir;
	float calificacion = jugador->tipo->analizarProbabilidad(this->comunitarias, jugador->mano);		
	int decision = jugador->tomarDecision(calificacion);
	if (decision == 0) //decide retirarse
	{
		eliminarJugador(jugador);
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

/**
* @brief Elimina al jugador si decide retirarse.
* @param jugador Jugador *
*/
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

// cambie de char * a Jugador * para que sea facil al repartir el dinero y asi. el parametro que recibia no servia, en mi opinion xd
/**
* @brief Decide quien es el ganador
* @return ganador Jugador *
*/
Jugador * Dealer::seleccionarGanador()
{
	Jugador * ganador = NULL;
	list<Jugador*>::iterator jugador1 = jugadores.begin();
	list<Jugador*>::iterator jugador2 = ++jugador1;
	
	while (jugador1 != jugadores.end())
	{
		if (jugador2 != jugadores.end())
		{			
			if ((*jugador1)->tipo->getProbabilidad() > (*jugador2)->tipo->getProbabilidad())
			{
				//es mayor la probabilidad de gane del jugador1
				ganador = (*jugador1);
				++jugador2;
			}
			else if ((*jugador1)->tipo->getProbabilidad() < (*jugador2)->tipo->getProbabilidad())
			{
				//es mayor la probabilidad de gane del jugador2
				ganador = (*jugador2);
				jugador1 = ++jugador2;
			}
			else
			{
				//Las probabilidades son las mismas
				if (jugada->compararJugadas((*jugador1)->tipo->getMejorJugada(), (*jugador2)->tipo->getMejorJugada(), (*jugador1)->tipo->getProbabilidad()) == 1)
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
	}

	return ganador;
}

//se reparte dinero de una vez al ganador
/**
* @brief Reparte dinero al ganador.
* @param jugador Jugador *
*/
void Dealer::repartirDinero(Jugador * ganador)
{
	ganador->dineroRestante = bote;
}

/**
* @brief Agrega al bote el dinero de las apuestas.
* @param apuesta int
*/
void Dealer::llenarBote(int apuesta)
{
	bote += apuesta;
}

//ESTE NO SE SI SIRVE
void Dealer::revelar()
{
	//return comunitarias;
}

//NUEVO
/**
* @brief Imprime mano de cada jugador
* @param out ostream &
*/
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

//NUEVO
/**
* @brief Termina el juego.
*/
void Dealer::finalizar()
{
	Jugador * ganador;
	if (this->jugadores.size() == 1)
	{
		ganador = this->jugadores.back();
	}
	else
	{
		ganador = seleccionarGanador();
	}
	if (ganador != NULL)
	{
		repartirDinero(ganador);
	}
}

//NUEVO
/**
* @brief Sobrecarga del operador <<
* @param out ostream &
* @param d Dealer *
* @return out ostream &
*/
ostream & operator<<(ostream & out, Dealer * d)
{
	d->imprimir(out);
	return out;
}
