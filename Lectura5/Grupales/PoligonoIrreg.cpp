#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>

PoligonoIrreg::PoligonoIrreg() {
	return;
}

double PoligonoIrreg::numVertices = 0;

PoligonoIrreg::PoligonoIrreg(int v) {
	vertices.reserve(v);
	numVertices += v;
	return;
}

void PoligonoIrreg::addVertice(Coordenada c) {
	vertices.push_back(c);
}

void PoligonoIrreg::imprimeVertices() {
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << "Vertice" << i << std::endl;
		std::cout << "  [x]: " << vertices[i].obtenerX() << std::endl;
		std::cout << "  [y]: " << vertices[i].obtenerY() << std::endl;
	}
}

double PoligonoIrreg::getNumVertices() {
	return numVertices;
}

