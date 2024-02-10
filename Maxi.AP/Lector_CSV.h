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
	Libros LeerLibro(string line);
	vector<string> split(string source, char delimiter);

public:
	list<Libros> Leer(string path);
	int setPath(string fichero);
	string getPath();
};