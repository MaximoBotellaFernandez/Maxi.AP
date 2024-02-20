#pragma once
#include "Libros.h"
#include <list>

class Vender
{
private:
	string readFromCin(string message);
	string path;
	string line;
public:
	void IniciarVenta(list<Libros>* libros, string path);
	bool buscar(list<Libros>* libros, string titulo, Libros& libro);
};