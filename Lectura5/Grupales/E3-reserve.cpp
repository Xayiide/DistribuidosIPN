#include "PoligonoIrreg.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

int main() {
	int numObjetos  = 3000000;
	int maxVertices = 10000;
	int i = 0;


	std::vector<PoligonoIrreg> vPolis;
	vPolis.reserve(numObjetos);
	
	for (i = 0; i < numObjetos; i++) {
		int num = rand() % maxVertices + 1;
		vPolis[i] = PoligonoIrreg(num);
	}
	std::cout << "Numero de vertices: " << vPolis[i].getNumVertices()
		<< std::endl;
}
