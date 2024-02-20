#include "Comprar.h"
#include "Lector_CSV.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

void Comprar::IniciarCompra(list<Libros>* libros, string path)
{
    Libros nuevoLibro;
    double Precio = 0;
    int Unidades = 0;
    ifstream myfile(path);
    list<Libros> ret = {};

    myfile.open(path);

    if (!myfile.is_open())
        {
            cout << "No se puede abrir el archivo \n";
        }

    // TODO: buscar el libro por título y si existe, agregarle unidades
    cin.ignore();
    nuevoLibro.Titulo = readFromCin("Titulo del libro");

    nuevoLibro.Autor = readFromCin("Autor");
    nuevoLibro.Lenguaje_Original = readFromCin("Lenguaje original");
    string fecha = readFromCin("Fecha de publicacion");
    nuevoLibro.Fecha_de_Publicacion = stoi(fecha);
    nuevoLibro.Genero = readFromCin("Genero");
    string precio = readFromCin("Precio");
    nuevoLibro.Precio = stod(precio);
    string unidades = readFromCin("Unidades");
    nuevoLibro.Unidades = stoi(unidades);

    cout << "Son " << nuevoLibro.Precio * nuevoLibro.Unidades << " euros.\n";
    cout << "Quedan " << nuevoLibro.Unidades << " Unidades.\n";
    // TODO: hacer algo con unidades y precio
    libros->push_back(nuevoLibro);
}

string Comprar::readFromCin(string message) {
    string ret;
    cout << message << ":\n";
    //cin.ignore();
    getline(cin, ret);
    return ret;
}
