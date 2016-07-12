/**
* @class PruebaCarta
* @brief Prueba que carta se cree correctamente. Hija de Carta
*/

#pragma once

#include "Carta.h"

class PruebaCarta :
	public Carta
{
public:
	PruebaCarta(int, int);
	virtual ~PruebaCarta();
};

