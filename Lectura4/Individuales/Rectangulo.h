#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Coordenada.h"

class Rectangulo {
	private:
		Coordenada superiorIzq;
		Coordenada inferiorDer;
	public:
		Rectangulo();
		Rectangulo(double xSupIzq, double ySupIzq, double zSupIzq,
				   double xInfDer, double yInfDer, double zInfDer);
		Rectangulo(Coordenada supIzq, Coordenada infDer);

		void imprimeEsq();
		Coordenada obtieneSupIzq();
		Coordenada obtieneInfDer();
		double obtieneArea();
};

#endif
