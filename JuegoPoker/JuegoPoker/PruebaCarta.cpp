#include "stdafx.h"
#include "PruebaCarta.h"


PruebaCarta::PruebaCarta(int v, int p) : Carta(v, p)
{
	cout << "Valor enviado: " << v << " Numero de palo enviado: " << p << endl;
	Carta * carta = new Carta(v, p);
	cout << "Carta creada: " << carta << endl << endl;
	delete carta;
}

PruebaCarta::~PruebaCarta()
{
}
