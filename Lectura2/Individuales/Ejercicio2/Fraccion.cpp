#include "Fraccion.hpp"
#include <iostream>

Fraccion::Fraccion(int n, int d) {
	if (d == 0) {
		std::cout << "El denominador no puede ser 0" << std::endl;
		std::cout << "Usando 1 en su lugar" << std::endl;
		den = 1;
	} else {
		den = d;
	}

	num = n;
}


double Fraccion::calcular() {
	double res = (num*1.0)/(den*1.0);
	return res;
}
