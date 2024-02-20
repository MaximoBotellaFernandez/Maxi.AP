#include "Vender.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

void Vender::IniciarVenta(list<Libros>* libros, string path)
{
    ifstream myfile(path);
    list<Libros> ret = {};

    myfile.open(path);

    if (!myfile.is_open())
    {
        cout << "No se puede abrir el archivo \n";
    }
    cin.ignore();
    string titulo = readFromCin("Titulo del libro");

    Libros libro;
    if (buscar(libros, titulo, libro)) {
        string unidades = readFromCin("Unidades");
        int uni = stoi(unidades);
        if (uni > libro.Unidades)
        {
            cout << "No hay suficientes unidades, Quedan " << libro.Unidades << " unidades.\n";
            return;
        }
        libro.Unidades -= uni;

        cout << "Son " << libro.Precio * uni << " euros.\n";
        cout << "Quedan " << libro.Unidades << " Unidades.\n";
        return;
    }
}

bool Vender::buscar(list<Libros>* libros, string titulo, Libros& libro)
{
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

string Vender::readFromCin(string message) {
    string ret;
    cout << message << ":\n";
    getline(cin, ret);
    return ret;
}