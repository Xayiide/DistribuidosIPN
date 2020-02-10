#include "Fecha.hpp"
#include <iostream>

int main() {
	Fecha a, b, c(21, 9, 1972);
	
	b.inicializaFecha(17, 6, 2000);
	
	a.muestraFecha(); /* 3-4-2014 */
	b.muestraFecha();
	c.muestraFecha();

	std::cout << c.convierte() << std::endl;

	a.leapyr() ? std::cout << "2014 es bisiesto" << std::endl :
		         std::cout << "2014 no es bisiesto" << std::endl;

	c.leapyr() ? std::cout << "1972 es bisiesto" << std::endl :
				 std::cout << "1972 no es bisiesto" << std::endl;

	int numBisiestos = 0;
	for (int i = 1; i <= 2020; i++) {
		a.inicializaFecha(1, 1, i);
		if (a.leapyr())
			numBisiestos++;
	}

	std::cout << "Número de años bisiestos: " << numBisiestos << std::endl;

	return 0;
}
