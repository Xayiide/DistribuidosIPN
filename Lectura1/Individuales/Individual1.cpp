/* Calcular la raiz cuadrada de un entero n utilizando el 
 * algoritmo babilonico.
 * Haciendo n del tipo double y resultado con 4 decimales */

#include <iostream>
#include <iomanip>


int main(int argc, char *argv[]) {
	double n = 0;
	double r = 1;
	int    i = 0;

	std::cout << "Introduza un número: ";
	std::cin  >> n;
	std::cout << std::endl;

	if (n == 0) {
		std::cout << "Su raíz aproximada es 0" << std::endl;
		return 0;
	}

	if (n < 0) {
		std::cout << "El número debe ser positivo" << std::endl;
		return 0;
	}

	for (i = 0; i < 10; i++)
		r = (r + (n / r)) / 2;

	std::cout << "Su raíz aproximada es: " << std::setprecision(4)
		      << r << std::endl;
	return 0;
}
