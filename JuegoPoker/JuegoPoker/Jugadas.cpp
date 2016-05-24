#include "stdafx.h"
#include "Jugadas.h"

Jugadas::Jugadas()
{
}

Jugadas::~Jugadas()
{
}

float Jugadas::establecerPorcentajeExito(Deck mano[])
{
	float porcentaje = 0;

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

void Jugadas::establecerCalificacion(float calificacion)
{
	this -> calificacion = calificacion;
}

float Jugadas::compararJugadas(Deck mano1[], Deck mano2[])
{
	return 0.0f;
}

int Jugadas::esFlorImperial(Deck mano[])
{
	for (int i = 0; i < 8; i++)
	{
		//mano[1].
	}
	return 0;
}

int Jugadas::esEscaleraColor(Deck mano[])
{
	return 0;
}

int Jugadas::esPoker(Deck mano[])
{
	return 0;
}

int Jugadas::esFull(Deck mano[])
{
	return 0;
}

int Jugadas::esColor(Deck mano[])
{
	return 0;
}

int Jugadas::esEscalera(Deck mano[])
{
	return 0;
}

int Jugadas::esTrio(Deck mano[])
{
	return 0;
}

int Jugadas::esDoblePareja(Deck mano[])
{
	return 0;
}

int Jugadas::esPareja(Deck mano[])
{
	return 0;
}

int Jugadas::esCartaAlta(Deck mano[])
{
	return 0;
}
