#include "Coordenada.h"
#include <iostream>

Coordenada::Coordenada(double xx, double yy, double zz) : 
	x(xx), y(yy), z(zz) { }

double Coordenada::obtenerX() {
	return x;
}

double Coordenada::obtenerY() {
	return y;
}

double Coordenada:obtenerZ() {
	return z;
}
