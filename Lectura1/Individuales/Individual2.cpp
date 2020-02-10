
/* Progama que imprima la altura de un edificio si se conoce
 * el tiempo que tardo una pelota de tenis desde que se dejo
 * caer en la parte mas alta del edificio y hasta llegar
 * al suelo */

/* H = 0.5 * g * t^2
 * g = 9.8 */

#include <iostream>

int main() {
	float g = 9.8;
	float t = 0;
	float h = 0;

	std::cout << "Tiempo: ";
	std::cin  >> t;

	h = 0.5 * g * t * t;
	std::cout << "La altura del edificio es: " << h << " metros\n"; 

	return 0;

}
