#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>

/* Modificar Coordenada.h y Coordenada.cpp para poder recibir dos
 * parametros como coordenadas polares y que asigne los valores apropiados,
 * devolviendo el mismo area */

int main() {
	Rectangulo rectangulo2(Coordenada(2, 3), Coordenada(5, 1));

	std::cout << "Calculando area..." << std::endl;
	rectangulo2.imprimeEsq();

	double area = rectangulo2.obtieneArea();

	std::cout << "El area es: " << area << std::endl;

	return 0;
}
