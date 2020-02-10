#include "Temperatura.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	float temp;
	std::string grado;
	Temperatura t;

	std::cout << "Ingrese temperatura: ";
	std::cin  >> temp;
	std::cout << std::endl;

	std::cout << "Ingrese (K)elvin, (F)ahrenheit o (C)elsius: ";
	std::cin  >> grado;
	std::cout << std::endl;

	if (grado == "K" || grado == "k") {
		t.setTempKelvin(temp);
	} else if (grado == "F" || grado == "f") {
		t.setTempFahrenheit(temp);
	} else if (grado == "C" || grado == "c") {
		t.setTempCelsius(temp);
	} else {
		std::cout << "Por favor, sólo [KkFfCc]" << std::endl;
		return -1;
	}

	t.getTempKelvin();
	t.getTempFahrenheit();
	t.getTempCelsius();

	return 0;
}
