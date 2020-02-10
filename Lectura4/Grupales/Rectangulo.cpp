#include "Rectangulo.h"
#include <iostream>

Rectangulo::Rectangulo() : superiorIzq(0, 0), inferiorDer(0, 0) { }


Rectangulo::Rectangulo(double xSupIzq, double ySupIzq,
		               double xInfDer, double yInfDer) : 
	superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer) { }

Rectangulo::Rectangulo(Coordenada supIzq, Coordenada infDer) :
	superiorIzq(supIzq.obtenerX(), supIzq.obtenerY()),
	inferiorDer(infDer.obtenerX(), infDer.obtenerY()) { }

void Rectangulo::imprimeEsq() {
	std::cout << "Sup izq:" << std::endl;
	std::cout << "[x]: " << superiorIzq.obtenerX() << std::endl;
	std::cout << "[y]: " << superiorIzq.obtenerY() << std::endl;

	std::cout << "Inf der:" << std::endl;
	std::cout << "[x]: " << inferiorDer.obtenerX() << std::endl;
	std::cout << "[y]: " << inferiorDer.obtenerY() << std::endl;
}

Coordenada Rectangulo::obtieneSupIzq() {
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer() {
	return inferiorDer;
}

double Rectangulo::obtieneArea() {
	double alto  = obtieneSupIzq().obtenerY() -
		           obtieneInfDer().obtenerY();
	double ancho = obtieneInfDer().obtenerX() -
				   obtieneSupIzq().obtenerX();

	return alto * ancho;
}
