/**
* @class Carta
* @brief Atributos de carta.
*/
#pragma once

using namespace std;

class Carta
{
	friend ostream & operator<<(ostream &, Carta *);

private:
	const int DIAMANTES = 1;//estos tampoco los hemos usado
	const int PICAS = 2;
	const int CORAZONES = 3;
	const int TREBOLES = 4;

	int numeroCarta; /*!< varible integer numeroCarta. Valor de la carta*/
	int palo; /*!< varible integer palo. Numero de palo de la carta*/

public:
	Carta(int, int);
	Carta();
	~Carta();
	
	void operator=(Carta &); //creo que este tampoco lo usamos :o
	
	int getValor();//creo que estos dos no se ocupan porque al imprimir eso se hace con la sobrecarga
	
	int getPalo();//
};
ostream & operator<<(ostream &, Carta *);