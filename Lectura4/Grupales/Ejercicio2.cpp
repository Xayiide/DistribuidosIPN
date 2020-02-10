#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>

int main() {
	Rectangulo rectangulo2(Coordenada(2, 3), Coordenada(5, 1));
	double ancho, alto;

	std::cout << "Calculando area..." << std::endl;
	rectangulo2.imprimeEsq();

	alto  = rectangulo2.obtieneSupIzq().obtenerY() -
		    rectangulo2.obtieneInfDer().obtenerY();

	ancho = rectangulo2.obtieneInfDer().obtenerX() -
			rectangulo2.obtieneSupIzq().obtenerX();

	std::cout << "El area es: " << ancho * alto << std::endl;

	return 0;
}
