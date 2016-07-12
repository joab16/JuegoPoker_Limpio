#pragma once
#include "stdafx.h"
#include "Deck.h"

class Jugadas
{
private:
	int cantidadCartas;
	float calificacion;

public:
	Jugadas();

	~Jugadas();

	float establecerPorcentajeExito(list <Carta *>, list <Carta *>);

	void establecerCalificacion(float);

	float compararJugadas(list<Carta *>, list <Carta *>, list <Carta *>);

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
	
	float obtenerCalificacion();

	list <Carta *> ordenaLista(list <Carta *>, list <Carta *>);
};
