#pragma once

#include "Deck.h"

class Jugadas
{
private:
	int cantidadCartas;
	float calificacion;

public:
	Jugadas();

	~Jugadas();

	float establecerPorcentajeExito(Deck mano[]);

	void establecerCalificacion(float);

	float compararJugadas(Deck mano1[], Deck mano2[]);

	int esFlorImperial(Deck mano[]);

	int esEscaleraColor(Deck mano[]);

	int esPoker(Deck mano[]);

	int esFull(Deck mano[]);

	int esColor(Deck mano[]);

	int esEscalera(Deck mano[]);

	int esTrio(Deck mano[]);

	int esDoblePareja(Deck mano[]);

	int esPareja(Deck mano[]);

	int esCartaAlta(Deck mano[]);
	
	float obtenerCalificacion();
};
