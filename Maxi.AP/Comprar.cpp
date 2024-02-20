#include "Comprar.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

void Comprar::IniciarCompra(list<Libros>* libros, string path)
{
    ifstream myfile(path);
    list<Libros> ret = {};

    myfile.open(path);

    if (!myfile.is_open())
        {
            cout << "No se puede abrir el archivo \n";
        }

    // TODO: buscar el libro por título y si existe, agregarle unidades
    cin.ignore();
    string titulo = readFromCin("Titulo del libro");

    Libros libro;
    if (buscar(libros, titulo, libro)) {
        string unidades = readFromCin("Unidades");
        int uni = stoi(unidades);
        if (uni > libro.Unidades)
        {
            // TODO: mostrar mensaje de erroro y madnar ATPC
            return;
        }
        libro.Unidades += uni;

        cout << "Son " << libro.Precio * uni << " euros.\n";
        cout << "Quedan " << libro.Unidades << " Unidades.\n";
        return;
    }
    Libros nuevoLibro;
    nuevoLibro.Titulo = titulo;
    nuevoLibro.Autor = readFromCin("Autor");
    nuevoLibro.Lenguaje_Original = readFromCin("Lenguaje original");
    string fecha = readFromCin("Fecha de publicacion");
    nuevoLibro.Fecha_de_Publicacion = stoi(fecha);
    string ventas = readFromCin("Ventas (mill.)");
    nuevoLibro.Venta_en_Millones = stoi(ventas);
    nuevoLibro.Genero = readFromCin("Genero");
    string precio = readFromCin("Precio");
    nuevoLibro.Precio = stod(precio);
    string unidades = readFromCin("Unidades");
    nuevoLibro.Unidades = stoi(unidades);

    cout << "Son " << nuevoLibro.Precio * nuevoLibro.Unidades << " euros.\n";
    cout << "Quedan " << nuevoLibro.Unidades << " Unidades.\n";
    libros->push_back(nuevoLibro);
}

bool Comprar::buscar(list<Libros>* libros, string titulo, Libros& libro) {
    list<Libros>::iterator it = libros->begin();
    do
    {
        libro = *it;
        if (libro.Titulo == titulo)
            return true;
        else 
            it++;
    } while (it != libros->end());
    return false;
}

string Comprar::readFromCin(string message) {
    string ret;
    cout << message << ":\n";
    getline(cin, ret);
    return ret;
}
