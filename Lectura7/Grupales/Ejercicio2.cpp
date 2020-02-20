#include <iostream>
#include <string>

int main() {
	std::string cadena("ESCOM");
	// std::cout << cadena[6] << std::endl; /* Throws std::out_of_range */

	std::cout << cadena.at(6) << std::endl;

	return 0;
}
