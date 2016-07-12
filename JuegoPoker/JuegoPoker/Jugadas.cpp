#include "stdafx.h"
#include "Jugadas.h"

/**
* @brief Constructor
*/
Jugadas::Jugadas()
{
}

/**
* @brief Destructor
*/
Jugadas::~Jugadas()
{
}

/**
* @brief Establece el porcentaje de exito
* @param mano list<Carta*>
*/
double Jugadas::establecerPorcentajeExito(/*ale*/ list<Carta*> mano)
{
	double porcentaje = 0;

	if (esFlorImperial(mano) == 1)
	{
		porcentaje = 1.0;
	}
	else if (esEscaleraColor(mano) == 1)
	{
		porcentaje = 0.9;
	}
	else if(esPoker(mano) == 1)
	{
		porcentaje = 0.8;
	}
	else if (esFull(mano) == 1)
	{
		porcentaje = 0.7;
	}
	else if (esColor(mano) == 1)
	{
		porcentaje = 0.6;
	}
	else if (esEscalera(mano) == 1)
	{
		porcentaje = 0.5;
	}
	else if (esTrio(mano) == 1)
	{
		porcentaje = 0.4;
	}
	else if (esDoblePareja(mano) == 1)
	{
		porcentaje = 0.3;
	}
	else if (esPareja(mano) == 1)
	{
		porcentaje = 0.2;
	}
	else if (esCartaAlta(mano) == 1)
	{
		porcentaje = 0.1;
	}
	return porcentaje;
}

//me parece que esta no es necesaria :o
void Jugadas::establecerCalificacion(double calificacion)
{
	this -> calificacion = calificacion;
}

// cambie valor de retorno de double a int para que devuelva quien es mayor, 1 o 2,
/**
* @brief Compara manos de dos jugadores
* @param mano1 list<Carta*>
* @param mano2 list<Carta*>
* @return mayor int
*/
int Jugadas::compararJugadas(list<Carta *> mano1, list<Carta *> mano2)
{
	return 0;
}

/**
* @brief Verifica si es Flor Imperial o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esFlorImperial(list<Carta *> mano)
{
	for (int i = 0; i < 8; i++)
	{
		//mano[1].
	}
	return 0;
}

/**
* @brief Verifica si es Escalera de Color o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esEscaleraColor(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si es Poker o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esPoker(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si es Full House o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esFull(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si puede ganar por Color o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esColor(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si es Escalera o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esEscalera(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si es Trio o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esTrio(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si tiene doble pareja o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esDoblePareja(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si tiene pareja o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esPareja(list<Carta *> mano)
{
	return 0;
}

/**
* @brief Verifica si tiene CartaAlta o es posible que lo haga
* @param mano list<Carta*>
* @return es int
*/
int Jugadas::esCartaAlta(list<Carta *> mano)
{
	return 0;
}

//NUEVO

/**
* @brief Obtiene calificacion de una mano
* @param mano list<Carta*>
* @return calificacion double
*/
double Jugadas::obtenerCalificacion(list<Carta*> mano)
{
	return establecerPorcentajeExito(mano);
}

//cambié los deck mano[] por list<Carta *> porque usamos listas :)