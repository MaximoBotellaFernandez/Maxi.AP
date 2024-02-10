#pragma once
#include <list>
#include <string>
#include "Libros.h"

class Escritor_CSV
{
private:
	string Normalizar(string texto);
public:
	void Guardar(list<Libros>* libros, string path);
};

