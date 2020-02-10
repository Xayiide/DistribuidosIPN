#include <unistd.h>
#include <iostream>

class NumerosRand {
	private:
		int *arreglo;
		unsigned int numeroElementos;
	public:
		NumerosRand(unsigned int num);
		~NumerosRand();
		void inicializaNumerosRand(void);
};

NumerosRand::NumerosRand(unsigned int num) {
	numeroElementos = num;
	arreglo = new int[numeroElementos];
}

NumerosRand::~NumerosRand() {
	delete[] arreglo;
}

void NumerosRand::inicializaNumerosRand() {
	unsigned int i;

	for (i = 0; i < numeroElementos; i++)
		arreglo[i] = rand();

	return;
}

void pruebaClase() {
	unsigned int capacidad;

	std::cout << "Numero de enteros aleatorios en el arreglo: ";
	std::cin >> capacidad;
	NumerosRand tmp(capacidad);
	tmp.inicializaNumerosRand();
	sleep(7);
}

int main() {
	char res;

	do {
		pruebaClase();
		std::cout << "Probar de nuevo? (s/n) ";
		std::cin  >> res;
	} while ((res == 's') || (res == 'S'));
}
