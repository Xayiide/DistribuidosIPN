#include <stdlib.h>
#include <iostream>

class Fecha {
	private:
		int dia, mes, year;
		static int vecesMuestF;
	public:
		static int getVecesMuestF();
		Fecha(int = 3, int = 4, int = 2014);
		void inicializaFecha(int, int, int);
		void muestraFecha();
};

int Fecha::vecesMuestF = 0;

int Fecha::getVecesMuestF() {
	// std::cout << "Dia: " << dia << std::endl;
	return vecesMuestF;
}

Fecha::Fecha(int dd, int mm, int yyyy) {
	dia  = dd;
	mes  = mm;
	year = yyyy;
}

void Fecha::inicializaFecha(int dd, int mm, int yyyy) {
	dia  = dd;
	mes  = mm;
	year = yyyy;
	return;
}

void Fecha::muestraFecha() {
	std::cout << "[yyyy-mm-dd]: " << year << "-" << mes << "-" << dia
		      << std::endl;
	vecesMuestF++;
	return;
}


int main() {
	Fecha a, b, c(21, 9, 2000);
	b.inicializaFecha(17, 6, 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
	std::cout << "Se ha llamado a muestraFecha() " << c.getVecesMuestF()
		<< " veces" << std::endl;

	return 0;
}
