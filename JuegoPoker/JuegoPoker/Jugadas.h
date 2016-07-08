#pragma once

#include "Deck.h"
//cmabie los Deck[] mano por list<Carta *>
class Jugadas
{
private:
	int cantidadCartas;
	double calificacion;

public:
	Jugadas();

	~Jugadas();

	double establecerPorcentajeExito(list<Carta *>);

	void establecerCalificacion(double);

	double compararJugadas(list<Carta *> , list<Carta *> );

	int esFlorImperial(list<Carta *> );

	int esEscaleraColor(list<Carta *> );

	int esPoker(list<Carta *> );

	int esFull(list<Carta *> );

	int esColor(list<Carta *> );

	int esEscalera(list<Carta *> );

	int esTrio(list<Carta *> );

	int esDoblePareja(list<Carta *> );

	int esPareja(list<Carta *> );

	int esCartaAlta(list<Carta *> );
	
	// ale
	double obtenerCalificacion(list<Carta *>);
};
