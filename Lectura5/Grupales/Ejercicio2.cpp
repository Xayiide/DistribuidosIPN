#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>

int main() {	
	PoligonoIrreg p1;
	p1.addVertice(Coordenada(0, 0));
	p1.addVertice(Coordenada(1, 1));
	p1.addVertice(Coordenada(2, 2));
	p1.addVertice(Coordenada(3, 3));

	p1.imprimeVertices();

	return 0;
}
