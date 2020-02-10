/* Programa que encuentre el area de un circulo dado
 * radio por STDIN */

#include <iostream>

int main() {
	const double PI = 3.1415926;
	float radio = 0;
	float area  = 0;
	
	std::cout << "Introduzca radio: ";
	std::cin  >> radio;
	std::cout << std::endl;
	
	area = PI * radio * radio;
	std::cout << "Area del círculo: " << area << std::endl;

	return 0;
}
