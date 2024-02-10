#pragma once
#include <string>
#include <iostream>
#include "Libros.h"
#include<list>

using namespace std;

class Escaparate
{
public:
	void Mostrar(list<Libros>* libros);
};