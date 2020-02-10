#include "Fecha.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h> /* memset */


Fecha::Fecha(int dd, int mm, int yyyy) : dia(dd),
										 mes(mm),
										 year(yyyy) {
	if ((mes < 1) || (mes > 12)) {
		std::cout << "Mes debe estar entre 1 y 12\n";
		exit(1);
	}
	else if ((dia < 1) || (dia > 31)) {
		std::cout << "Dia debe estar entre 1 y 31\n";
		exit(1);
	}
	else if ((year < 0) || (year > 2020)) {
		std::cout << "Year debe estar entre 0 y 2020\n";
		exit(1);
	}
	// memset(array, '\0', 8192);
	// memset(darray, '\0', 8192);
}

int Fecha::getYear() {
	return year;
}

int Fecha::getMes() {
	return mes;
}

int Fecha::getDia() {
	return dia;
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

void Fecha::aleatorio() {
	srand(time(NULL));
	dia  = rand() % 31 + 1;
	mes  = rand() % 12 +1;
	year = rand() % 2020 + 1;
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


