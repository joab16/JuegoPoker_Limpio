#include "stdafx.h"
#include "Jugadas.h"

Jugadas::Jugadas()
{
}

Jugadas::~Jugadas()
{
}

double Jugadas::establecerPorcentajeExito(/*ale*/ list<Carta *> mano)
{
	double porcentaje = 0;

	if (esFlorImperial(mano) == 1)
	{
		porcentaje = 1.0f;
	}
	else if (esEscaleraColor(mano) == 1)
	{
		porcentaje = 0.9f;
	}
	else if(esPoker(mano) == 1)
	{
		porcentaje = 0.8f;
	}
	else if (esFull(mano) == 1)
	{
		porcentaje = 0.7f;
	}
	else if (esColor(mano) == 1)
	{
		porcentaje = 0.6f;
	}
	else if (esEscalera(mano) == 1)
	{
		porcentaje = 0.5f;
	}
	else if (esTrio(mano) == 1)
	{
		porcentaje = 0.4f;
	}
	else if (esDoblePareja(mano) == 1)
	{
		porcentaje = 0.3f;
	}
	else if (esPareja(mano) == 1)
	{
		porcentaje = 0.2f;
	}
	else if (esCartaAlta(mano) == 1)
	{
		porcentaje = 0.1f;
	}
	return porcentaje;
}

//me parece que esta no es necesaria :o
void Jugadas::establecerCalificacion(double calificacion)
{
	this -> calificacion = calificacion;
}

// cambie valor de retorno de double a int para que devuelva quien es mayor, 1 o 2,
int Jugadas::compararJugadas(list<Carta *> mano1, list<Carta *> mano2)
{
	return 0.0;
}

int Jugadas::esFlorImperial(list<Carta *> mano)
{
	for (int i = 0; i < 8; i++)
	{
		//mano[1].
	}
	return 0;
}

int Jugadas::esEscaleraColor(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esPoker(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esFull(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esColor(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esEscalera(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esTrio(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esDoblePareja(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esPareja(list<Carta *> mano)
{
	return 0;
}

int Jugadas::esCartaAlta(list<Carta *> mano)
{
	return 0;
}

//ale
double Jugadas::obtenerCalificacion(list<Carta*> mano)
{
	return establecerPorcentajeExito(mano);
}

//cambié los deck mano[] por list<Carta *> porque usamos listas :)