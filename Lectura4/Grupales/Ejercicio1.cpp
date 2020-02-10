#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>

int main() {
	Rectangulo rectangulo1(2, 3, 5, 1);
	double ancho, alto;

	std::cout << "Calculando area..." << std::endl;
	rectangulo1.imprimeEsq();

	alto  = rectangulo1.obtieneSupIzq().obtenerY() -
		    rectangulo1.obtieneInfDer().obtenerY();

	ancho = rectangulo1.obtieneInfDer().obtenerX() -
			rectangulo1.obtieneSupIzq().obtenerX();

	std::cout << "El area es: " << ancho * alto << std::endl;

	return 0;
}
