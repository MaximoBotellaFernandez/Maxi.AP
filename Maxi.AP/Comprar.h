#pragma once
#include "Libros.h"
#include <list>

class Comprar
{
private:
	string readFromCin(string message);

public:
	void IniciarCompra(list<Libros>* libros);
};

