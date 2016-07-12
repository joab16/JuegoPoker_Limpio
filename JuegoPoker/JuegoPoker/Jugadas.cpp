#include "stdafx.h"
#include "Jugadas.h"

Jugadas::Jugadas()
{
}

Jugadas::~Jugadas()
{
}

float Jugadas::establecerPorcentajeExito(list <Carta *> comunitarias, list <Carta *> mano)
{
	float porcentaje = 0;

	if (esFlorImperial(comunitarias, mano) == 1)
	{
		porcentaje = 1.0f;
	}
	else if (esEscaleraColor(comunitarias, mano) == 1)
	{
		porcentaje = 0.9f;
	}
	else if(esPoker(comunitarias, mano) == 1)
	{
		porcentaje = 0.8f;
	}
	else if (esFull(comunitarias, mano) == 1)
	{
		porcentaje = 0.7f;
	}
	else if (esColor(comunitarias, mano) == 1)
	{
		porcentaje = 0.6f;
	}
	else if (esEscalera(comunitarias, mano) == 1)
	{
		porcentaje = 0.5f;
	}
	else if (esTrio(comunitarias, mano) == 1)
	{
		porcentaje = 0.4f;
	}
	else if (esDoblePareja(comunitarias, mano) == 1)
	{
		porcentaje = 0.3f;
	}
	else if (esPareja(comunitarias, mano) == 1)
	{
		porcentaje = 0.2f;
	}
	else if (esCartaAlta(comunitarias, mano) == 1)
	{
		porcentaje = 0.1f;
	}
	return porcentaje;
}

void Jugadas::establecerCalificacion(float calificacion)
{
	this -> calificacion = calificacion;
}

float Jugadas::compararJugadas(list <Carta *> comunitarias, list <Carta *> mano1, list <Carta *> mano2)
{
	list<Carta *> cartasJugador1 = ordenaLista(comunitarias, mano1);
	list<Carta *> cartasJugador2;
	return 0.0f;
}

int Jugadas::esFlorImperial(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;
	int primerValor = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if (((*it)->getValor() + 1 == (*next(it, 1))->getValor()))
		{
			if ((*it)->getPalo() == (*next(it, 1))->getPalo())
			{
				++banderaResultado;
			}
		}
		else
		{
			if ((*it)->getValor() != (*next(it, 1))->getValor())
			{
				banderaResultado = 0;
			}
		}
		if ((banderaResultado == 4) && ((*next(it, 1))->getValor() != 14))
		{
			banderaResultado = 0;
		}
	}
	if (banderaResultado == 4)
	{		
		return 1;
	}
	else
	{
		return 0;
	}
}

int Jugadas::esEscaleraColor(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;
	int primerValor = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if (((*it)->getValor() + 1 == (*next(it, 1))->getValor()))
		{
			if ((*it)->getPalo() == (*next(it, 1))->getPalo())
		    {
			   ++banderaResultado;
		    }
		}
		else
		{
			if ((*it)->getValor() != (*next(it, 1))->getValor())
			{
				banderaResultado = 0;
			}
		}
	}
	if (banderaResultado == 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Jugadas::esPoker(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if ((*it)->getValor() == (*next(it, 1))->getValor())
		{
			++banderaResultado;
		}
		else
		{
			banderaResultado = 0;
		}
	}
	if (banderaResultado == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Jugadas::esFull(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;
	int banderaPareja = 0;
	int banderaTrio = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{		
		if (((*it)->getValor() == (*next(it, 1))->getValor()))
		{
			++banderaResultado;
		}
		else if (banderaResultado == 2)
		{
			banderaPareja = 1;
			banderaResultado = 0;
		}
		else if (banderaResultado == 3)
		{
			banderaTrio = 1;
			banderaResultado = 0;
		}
	}
	if (banderaTrio == 1 && banderaPareja == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int Jugadas::esColor(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;
	int primerValor = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if (((*it)->getPalo() == (*next(it, 1))->getPalo()))
		{
			++banderaResultado;
		}
	}
	if (banderaResultado >= 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Jugadas::esEscalera(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;
	int primerValor = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if (((*it)->getValor() + 1 == (*next(it, 1))->getValor()))
		{
			++banderaResultado;
		}
		else
		{
			if ((*it)->getValor() != (*next(it, 1))->getValor())
			{
				banderaResultado = 0;
			}
		}
	}
	if (banderaResultado == 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Jugadas::esTrio(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;
	int primerValor = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if (((*it)->getValor() == (*next(it, 1))->getValor()))
		{			
			++banderaResultado;
		}
	}
	if (banderaResultado > 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

int Jugadas::esDoblePareja(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;
	int primerValor = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if (((*it)->getValor() == (*next(it, 1))->getValor()) && (*it)->getValor != primerValor)
		{
			primerValor = (*it)->getValor;
			++banderaResultado;
		}
	}
	if (banderaResultado > 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Jugadas::esPareja(list <Carta *> comunitarias, list <Carta *> mano)
{
	list <Carta *> cartasTotales = ordenaLista(comunitarias, mano);
	int banderaResultado = 0;

	for (list<Carta *>::iterator it = cartasTotales.begin(); next(it, 1) != cartasTotales.end(); ++it)
	{
		if ((*it)->getValor() == (*next(it, 1))->getValor())
		{
			banderaResultado = 1;
		}
	}
	/*
	for (list<Carta *>::iterator it = cartasTotales.begin(); it != cartasTotales.end(); ++it)
	{
		list<Carta *>::iterator it2 = it;
		++it2;
		for (; it2 != cartasTotales.end(); ++it2)
		{
			if ((*it)->getValor() == (*it2)->getValor())
			{
				banderaResultado = 1;
				break;
			}
		}
		if (banderaResultado == 1)
		{
			break;
		}
	}*/
	
	return banderaResultado;
}

int Jugadas::esCartaAlta(list <Carta *> comunitarias, list <Carta *> mano)
{
	return 0;
}

float Jugadas::obtenerCalificacion()
{
	return this->calificacion;
}

list<Carta*> Jugadas::ordenaLista(list<Carta*> comunitarias, list<Carta*> mano)
{
	list <Carta *> cartasTotales = comunitarias;
	cartasTotales.insert(cartasTotales.end(), mano.begin(), mano.end());
	cartasTotales.sort([](Carta * a, Carta * b) { return a->getValor() < b->getValor(); });
	return cartasTotales;
}
