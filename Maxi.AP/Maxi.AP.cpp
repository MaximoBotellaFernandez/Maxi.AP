#include <iostream>

int main()
{
	std::cout << "Cargando datos...";
	Lector_CSV reader;
	list<Libros> libros = reader.Leer(Libros_Biblioteca);
	std::cout << "Listo";
    
    int opcion;
    cout << "Menu:" << endl;
    cout << "1. Comprar" << endl;
    cout << "2. Vender" << endl;
    cout << "3. Alquilar" << endl;
    cout << "4. Ver Stock" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opción: ";
