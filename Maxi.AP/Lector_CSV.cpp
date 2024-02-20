#include "Lector_CSV.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;


list<Libros> Lector_CSV::Leer(string path)
{
	list<Libros> ret = {};
	string line;
	ifstream myfile(path);
	bool firstLineParsed = false;

	if (!myfile.is_open())
	{
		cout << "No se puede abrir el archivo \n";
		return ret;
	}

	while (getline(myfile, line)) {
		if (!firstLineParsed)
			firstLineParsed = true;
		else
		{
			Libros b = LeerLibro(line);
			ret.push_back(b);
		}
	}
	myfile.close();
	return ret;
}

int Lector_CSV::setPath(string fichero)
{
	path = fichero;
	return 0;
}

string Lector_CSV::getPath()
{
	return path;
}

Libros Lector_CSV::LeerLibro(string line)
{
	vector<string> parts = split(line, ',');
	Libros ret;
	ret.Titulo = parts[0];
	ret.Autor = parts[1];
	ret.Lenguaje_Original = parts[2];
	ret.Fecha_de_Publicacion = stoi(parts[3]);
	ret.Venta_en_Millones = stoi(parts[4]);
	ret.Genero = parts[5];
	ret.Unidades = stod(parts[6]);
	ret.Precio = stod(parts[7]);
	return ret;
}

vector<string> Lector_CSV::split(string source, char delimiter)
{
	vector<string> ret = {};
	size_t pos = 0;
	string token;
	while ((pos = source.find(delimiter)) != string::npos) {
		token = source.substr(0, pos);
		source.erase(0, pos + 1);
		if (token[0] == '"') {
			pos = source.find(delimiter);
			if (pos != string::npos) {
				string token2 = source.substr(0, pos);
				token.append(token2);
				source.erase(0, pos + 1);
				token.erase(0, pos = 1);
				//TODO: borrar la segunda "
			}
			else {
				
			}
		}
		ret.push_back(token);
	}
	ret.push_back(source);
	return ret;
}