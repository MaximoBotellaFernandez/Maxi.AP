#pragma once
#include "Libros.h"
#include <list>

class Comprar
{
private:
	string readFromCin(string message);
	string path;
	string line;
public:
	void IniciarCompra(list<Libros>* libros, string path);
	bool buscar(list<Libros>* libros, string titulo, Libros& libro);
};

