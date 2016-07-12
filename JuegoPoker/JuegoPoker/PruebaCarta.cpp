#include "stdafx.h"
#include "PruebaCarta.h"

/**
* @brief Constructor
* @param numero integer
* @param palo integer
*/
PruebaCarta::PruebaCarta(int numero, int palo) : Carta(numero, palo)
{
	cout << "Valor enviado: " << numero << " Numero de palo enviado: " << palo << endl;
}

PruebaCarta::~PruebaCarta()
{
}
