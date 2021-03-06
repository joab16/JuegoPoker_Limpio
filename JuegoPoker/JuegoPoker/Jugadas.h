/**
* @class Jugadas
* @brief Define jugadas del poker y establece calificaciones
*/

#pragma once
#include "stdafx.h"
#include "Deck.h"
//cmabie los Deck[] mano por list<Carta *>
class Jugadas
{
private:
	int cantidadCartas; /*!< varible integer cantidadCartas*/	
	
public:
	Jugadas();
	~Jugadas();

	double establecerPorcentajeExito(list <Carta *>, list <Carta *>);
	
	int compararJugadas(list<Carta *>, list <Carta *>, float);

	int esFlorImperial(list <Carta *>, list <Carta *>);

	int esEscaleraColor(list <Carta *>, list <Carta *>);

	int esPoker(list <Carta *>, list <Carta *>);

	int esFull(list <Carta *>, list <Carta *>);

	int esColor(list <Carta *>, list <Carta *>);

	int esEscalera(list <Carta *>, list <Carta *>);

	int esTrio(list <Carta *>, list <Carta *>);

	int esDoblePareja(list <Carta *>, list <Carta *>);

	int esPareja(list <Carta *>, list <Carta *>);

	int esCartaAlta(list <Carta *>, list <Carta *>);
	
	list <Carta *> ordenaLista(list <Carta *>, list <Carta *>);

	list <Carta *> mejorJugada; /*!< lista que contiene la mejor jugada*/
};
