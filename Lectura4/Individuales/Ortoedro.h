#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_

#include "Rectangulo.h"

class Ortoedro {
	private:
		// Rectangulo caras[6]; /* Por sencillez es mejor individuales */
		Rectangulo sup, inf, izq, der, ala, aca;
	public:
		Ortoedro(Coordenada infIzqAla, Coordenada supDerAca);
		void   obtieneVertices();
		double obtieneArea();
		double obtieneVolumen();
};


#endif
