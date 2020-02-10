#include "Fraccion.hpp"
#include <iostream>

int main() {
	int     num;
	int     den;
	double res;

	std::cout << "Numerador: ";
	std::cin  >> num;

	std::cout << "Denominador: ";
	std::cin  >> den;
	std::cout << std::endl;

	Fraccion f(num, den);

	res = f.calcular();
	std::cout << "Resultado: " << res << std::endl;

	return 0;
}
