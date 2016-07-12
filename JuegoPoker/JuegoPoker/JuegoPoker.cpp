// JuegoPoker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include "Carta.h"
#include "PruebaDealer.h"
#include "PruebaCarta.h"

using namespace std;

void pruebas();
void iniciarJuego();

int main()
{
	srand(time(NULL));

	pruebas();

	system("cls");

	iniciarJuego();
	
	/*PruebaJugadas j;
	j.validaPareja();*/

    return 0;
}

void pruebas()
{
	cout << "Prueba de dealer (Verificar jugadores tengan sus 2 cartas y que esten las 5 cartas comunitarias)\n\n";
	PruebaDealer * pDealer = new PruebaDealer();

	cout << endl << "Prueba de carta (Verificar que se cree la carta con los valores enviados)\n\n";
	PruebaCarta * pCarta = new PruebaCarta(10, 4);
	cout << "Carta creada:" << pCarta <<endl;
	system("pause");

	delete pCarta;
	delete pDealer;
}

void iniciarJuego()
{
	Dealer * d = new Dealer(1, 2);
	cout << d;
	delete d;
}