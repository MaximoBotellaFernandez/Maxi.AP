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

    cout << "Titulo del libro: \n";
    cin >> nuevoLibro.Titulo;
    cout << "Autor: \n";
    cin >> nuevoLibro.Autor;
    cout << "Lenguaje original: \n";
    cin >> nuevoLibro.Lenguaje_Original;
    cout << "Fecha de publicacion: \n";
    cin >> nuevoLibro.Fecha_de_Publicacion;
    cout << "Genero: \n";
    cin >> nuevoLibro.Genero;
    cout << "Precio: \n";
    cin >> Precio;
    cout << "Unidades: \n";
    cin >> Unidades;

    cout << "Son " << Precio * Unidades << " euros";

    // TODO: hacer algo con unidades y precio
    libros->push_back(nuevoLibro);
}
