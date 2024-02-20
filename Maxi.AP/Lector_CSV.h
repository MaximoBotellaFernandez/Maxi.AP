#pragma once
#include<string>
#include<vector>
#include<list>
#include"Libros.h"
using namespace std;

class Lector_CSV
{
private:
	string path;
	string line;

public:
	list<Libros> Leer(string path);
	int setPath(string fichero);
	string getPath();
	vector<string> split(string source, char delimiter);
	Libros LeerLibro(string line);
};