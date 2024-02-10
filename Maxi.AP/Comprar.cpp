#include <iostream>
#include "Comprar.h"
#include <string>
#include <list>

using namespace std;

void Comprar::IniciarCompra(list<Libros>* libros)
{
    Libros nuevoLibro;
    double Precio = 0;
    int Unidades = 0;

    // TODO: buscar el libro por título y si existe, agregarle unidades
    cin.ignore();
    nuevoLibro.Titulo = readFromCin("Titulo del libro");
    nuevoLibro.Autor = readFromCin("Autor");
    nuevoLibro.Lenguaje_Original = readFromCin("Lenguaje original");
    string fecha = readFromCin("Fecha de publicacion");
    nuevoLibro.Fecha_de_Publicacion = stoi(fecha);
    nuevoLibro.Genero = readFromCin("Genero");

    string precio = readFromCin("Precio");
    Precio = stod(precio);
    string unidades = readFromCin("Unidades");
    Unidades = stoi(unidades);

    cout << "Son " << Precio * Unidades << " euros.\n";

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
