#include <iostream>
#include <string>
#include "Libros.h"
#include "Lector_CSV.h"

#define Libros_Biblioteca "best-selling-book.csv"

using namespace std;

int main()
{
    //Cargar los datos en la memoria
    std::cout << "Cargando datos...";
    Lector_CSV reader;
    list<Libros> libros = reader.Leer(Libros_Biblioteca);
    std::cout << "Listo";

    int menu;
    cout << "Menu:" << endl;
    cout << "1. Comprar" << endl;
    cout << "2. Vender" << endl;
    cout << "3. Alquilar" << endl;
    cout << "4. Ver Stock" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opción: ";

    string Titulo;
    string Autor;
    string Lenguaje_original;
    int Fecha_de_publicacion;
    string Genero;
    int Precio;
    int Unidades;

    cin >> menu;

    switch (menu)
    {
    case 1:
        cout << "Titulo del libro: \n";
        cin >> Titulo;
        cout << "Autor: \n";
        cin >> Autor;
        cout << "Lenguaje original: \n";
        cin >> Lenguaje_original;
        cout << "Fecha de publicacion: \n";
        cin >> Fecha_de_publicacion;
        cout << "Genero: \n";
        cin >> Genero;
        cout << "Precio: \n";
        cin >> Precio;
        cout << "Unidades: \n";
        cin >> Unidades;

        cout << "Son " << Precio * Unidades << " euros";
        //Añadir al csv y sumar las unidades nuevas al stock total
    case 2:
        

    default:
        break;
    }
}