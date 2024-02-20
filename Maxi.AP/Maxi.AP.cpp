#include <iostream>
#include <string>
#include "Libros.h"
#include "Lector_CSV.h"
#include "Escaparate.h"
#include "Comprar.h"
#include "Escritor_CSV.h"

#define Libros_Libreria "C:\\git\\AP\\Maxi.AP\\x64\\Debug\\best-selling-book-r-datos.csv"
using namespace std;

int ShowMenu() {
    cout << "Menu:" << endl;
    cout << "1. Comprar" << endl;
    cout << "2. Vender" << endl;
    cout << "3. Ver Stock" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese su opcion: ";
    int menu;
    cin >> menu;
    return menu;
}

int main()
{
    Lector_CSV reader;
    Escaparate escaparate;
    Comprar comprar;
    Escritor_CSV escritor;
    reader.setPath(Libros_Libreria);
    list<Libros> libros = reader.Leer(Libros_Libreria);
    int menu = 0;
    while (menu != 4) {
        menu = ShowMenu();
        switch (menu)
        {
            case 1:
                comprar.IniciarCompra(&libros, Libros_Libreria);
                escritor.Guardar(&libros, Libros_Libreria);
                break;
            case 2:
                break;
            case 3:
                escaparate.Mostrar(&libros);
                break;
            default:
                break;
        }
    }
}