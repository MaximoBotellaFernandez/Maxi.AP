#pragma once
#include<string>
#include<vector>
#include<list>
#include"Libros.h"
using namespace std;

class Lector_CSV
{
public:
	list<Libros> Leer(string path);

private:
	Libros LeerLibro(string line);
	vector<string> split(string source, string delimiter);

};