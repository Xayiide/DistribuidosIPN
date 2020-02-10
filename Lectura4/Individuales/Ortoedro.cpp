#include "Ortoedro.h"
#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>

Ortoedro::Ortoedro(Coordenada infIzqAla, Coordenada supDerAca) {
	
	if (supDerAca.obtenerX() <= infIzqAla.obtenerX() ||
		supDerAca.obtenerY() <= infIzqAla.obtenerY() ||
		supDerAca.obtenerZ() <= infIzqAla.obtenerZ()) {
		std::cout << "El primer punto tiene que estar más cerca del eje \
			en todas sus coordenadas" << std::endl;
		return;
	}


	sup(Coordenada(supDerAca.obtenerX(),
				   supDerAca.obtenerY(),
				   supDerAca.obtenerZ()),
		Coordenada(infIzqAla.obtenerX(),
				   infIzqAla.obtenerY(),
				   supDerAca.obtenerZ()));

	inf(Coordenada(infIzqAla.obtenerX(),
				   infIzqAla.obtenerY(),
				   infIzqAla.obtenerZ()),
		Coordenada(supDerAca.obtenerX(),
				   supDerAca.obtenerY(),
				   infIzqAla.obtenerZ()));

	izq(Coordenada(infIzqAla.obtenerX(),
				   infIzqAla.obtenerY(),
				   infIzqAla.obtenerZ(),
		Coordenada(infIzqAla.obtenerX(),
				   supDerAca.obtenerY(),
				   supDerAca.obtenerZ()));

	der(Coordenada(supDerAca.obtenerX(),
				   supDerAca.obtenerY(),
				   supDerAca.obtenerZ()),
		Coordenada(supDerAca.obtenerX(),
				   infIzqAla.obtenerY(),
				   infIzqAla.obtenerZ()));

	ala(Coordenada(infIzqAla.obtenerX(),
			       infIzqAla.obtenerY(),
				   infIzqAla.obtenerZ()),
		Coordenada(supDerAca.obtenerX(),
				   infIzqAla.obtenerY(),
				   supDerAca.obtenerZ()));

	aca(Coordenada(supDerAca.obtenerX(),
				   supDerAca.obtenerY(),
				   supDerAca.obtenerZ()),
		Coordenada(infIzqAla.obtenerX(),
				   supDerAca.obtenerY(),
				   infIzqAla.obtenerZ()));

}
