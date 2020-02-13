#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

#include "Coordenada.h"
#include <vector>

class PoligonoIrreg {
	private:
		std::vector<Coordenada> vertices;
		static double numVertices;
	public:
		PoligonoIrreg();
		PoligonoIrreg(int);
		void addVertice(Coordenada);
		void imprimeVertices();
		double getNumVertices();
};

#endif
