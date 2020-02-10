#include "Rectangulo.h"
#include <iostream>

Rectangulo::Rectangulo() : superiorIzq(0, 0), inferiorDer(0, 0) { }


Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double zSupIzq,
		               double xInfDer, double yInfDer, double zInfDer) : 
	superiorIzq(xSupIzq, ySupIzq, zSupIzq),
	inferiorDer(xInfDer, yInfDer, zInfDer) { }

Rectangulo::Rectangulo(Coordenada supIzq, Coordenada infDer) :
	superiorIzq(supIzq.obtenerX(), supIzq.obtenerY(), supIzq.obtenerZ()),
	inferiorDer(infDer.obtenerX(), infDer.obtenerY(), infDer.obtenerZ()) { }

void Rectangulo::imprimeEsq() {
	std::cout << "Sup izq:" << std::endl;
	std::cout << "[x]: " << superiorIzq.obtenerX() << std::endl;
	std::cout << "[y]: " << superiorIzq.obtenerY() << std::endl;
	std::cout << "[z]: " << superiorIzq.obtenerZ() << std::endl;

	std::cout << "Inf der:" << std::endl;
	std::cout << "[x]: " << inferiorDer.obtenerX() << std::endl;
	std::cout << "[y]: " << inferiorDer.obtenerY() << std::endl;
	std::cout << "[z]: " << inferiorDer.obtenerZ() << std::endl;
}

Coordenada Rectangulo::obtieneSupIzq() {
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer() {
	return inferiorDer;
}

double Rectangulo::obtieneArea() {
	/* TODO: Fix */
	double alto  = obtieneSupIzq().obtenerY() -
		           obtieneInfDer().obtenerY();
	double ancho = obtieneInfDer().obtenerX() -
				   obtieneSupIzq().obtenerX();

	return alto * ancho;
}
