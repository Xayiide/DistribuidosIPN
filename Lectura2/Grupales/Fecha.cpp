#include "Fecha.hpp"
#include <iostream>

Fecha::Fecha(int dd, int mm, int yyyy) {
	mes  = mm;
	dia  = dd;
	year = yyyy;
}

void Fecha::inicializaFecha(int dd, int mm, int yyyy) {
	year = yyyy;
	mes  = mm;
	dia  = dd;
	return;
}

void Fecha::muestraFecha() {
	std::cout << "La fecha es (dia-mes-año): "
		      << dia << "-" << mes << "-" << year << std::endl;
	return;
}

int Fecha::convierte() {
	return (year * 10000) + (mes * 100) + dia;
}

bool Fecha::leapyr() {
	if (year % 400 == 0)
		return true;

	if (year % 4 == 0 && year % 100 != 0)
		return true;

	return false;
}
