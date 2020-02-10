#include "Rectangulo.h"
#include <iostream>

Rectangulo::Rectangulo() : superiorIzq(0, 0), inferiorDer(0, 0) { }

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq,
		               double xInfDer, double yInfDer) : 
	superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer) { } 
