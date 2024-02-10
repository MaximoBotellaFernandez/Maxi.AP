#include "Escritor_CSV.h"
#include <fstream>
#include <iostream>

using namespace std;

void Escritor_CSV::Guardar(list<Libros>* libros, string path)
{
	// para cada libro, escirbirlo en el fichero path
	ofstream outputFile(path); // create a new output file or overwrite an existing one
	if (!outputFile.is_open())
	{
		cerr << "Error opening file\n";
		return;
	}
	outputFile << "Book,Author(s),Original language,First published,Approximate sales in millions,Genre\n";
	for (list<Libros>::iterator it = libros->begin(); it != libros->end(); ++it)
	{
		Libros libro = *it;
		outputFile << Normalizar(libro.Titulo) + ",";
		outputFile << Normalizar(libro.Autor) + ",";
		outputFile << Normalizar(libro.Lenguaje_Original) + ",";
		outputFile << libro.Fecha_de_Publicacion << ",";
		outputFile << libro.Venta_en_Millones << ",";
		outputFile << Normalizar(libro.Genero) << "\n";
	}
	outputFile.close(); // close the file when done
}

string Escritor_CSV::Normalizar(string texto) {
	if (texto.find(',') != string::npos)
		return "\"" + texto + "\",";
	return texto;
}
