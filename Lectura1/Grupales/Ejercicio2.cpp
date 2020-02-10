#include <iostream>

int main() {
	int   entero1 = 10;
	int   entero2 = 20;
	float float1  = 5.5;

	std::cout << "entero1/entero2: ";
	std::cout << entero1 << "/" << entero2 << " = " << 
		entero1/entero2 << std::endl;

	std::cout << "entero2/entero1: ";
	std::cout << entero2 << "/" << entero1 << " = " << 
		entero2/entero1 << std::endl;

	std::cout << "entero2/float1: ";
	std::cout << entero2 << "/" << float1 << " = " <<
		entero2/float1 << std::endl;


	
	return 0;
}
