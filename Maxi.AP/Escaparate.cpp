#include "Escaparate.h"

void Escaparate::Mostrar(list<Libros> libros)
{
	for (std::list<Libros>::iterator it = libros.begin(); it != libros.end(); ++it)
	{
		Libros libro = *it;
		cout << libro.Titulo << ", " << libro.Autor << " (" << libro.Fecha_de_Publicacion << ")\n";
	}
	cout << "\n";
}
