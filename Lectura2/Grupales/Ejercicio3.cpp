#include "Fecha.hpp"
#include <iostream>

int main() {
	Fecha a, b, c(21, 9, 1973);
	
	b.inicializaFecha(17, 6, 2000);
	
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();

	std::cout << c.convierte() << std::endl;

	return 0;
}
