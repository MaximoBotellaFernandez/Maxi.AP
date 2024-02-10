#include <iostream>
#include <string>
#include "Libros.h"
#include "Lector_CSV.h"
#include "Escaparate.h"

#define Libros_Libreria "C:\\git\\AP\\Maxi.AP\\x64\\Debug\\best-selling-books.csv"
using namespace std;

int ShowMenu() {
    cout << "Menu:" << endl;
    cout << "1. Comprar" << endl;
    cout << "2. Vender" << endl;
    cout << "3. Alquilar" << endl;
    cout << "4. Ver Stock" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opcion: ";
    int menu;
    cin >> menu;
    return menu;
}

int main()
{
    Lector_CSV reader;
    Escaparate escaparate;
    reader.setPath(Libros_Libreria);
    list<Libros> libros = reader.Leer(Libros_Libreria);

    string Titulo;
    string Autor;
    string Lenguaje_original;
    int Fecha_de_publicacion;
    string Genero;
    int Precio;
    int Unidades;

    int menu = 0;
    while (menu != 5) {
        menu = ShowMenu();
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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                escaparate.Mostrar(libros);
                break;
            default:
                break;
        }
    }
}