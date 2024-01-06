#include "Lector_CSV.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

list<Libros> Lector_CSV::Leer(string path)
{
	//Implementar la lectura del achivo CSV y devolver un array de ç?
	list<Libros> ret = {};
	string line;
	ifstream myfile(path);
	bool firstLineParsed = false;
	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			if (!firstLineParsed)
				firstLineParsed = true;
			else
			{
				cout << line << endl;
				Libros b = LeerLibro(line);
				ret.push_back(b);
			}
		}
		myfile.close();
	}

	else cout << "No se puede abrir el archivo";
	return ret;
}

vector<string> Lector_CSV::split(string source, string delimiter)
{
	vector<string> ret = {};
	size_t pos = 0;
	std::string token;
	while ((pos = source.find(delimiter)) != std::string::npos) {
		token = source.substr(0, pos);
		ret.push_back(token);
		source.erase(0, pos + delimiter.length());
	}
	ret.push_back(source);
	return ret;
}