#include <iostream>

class Fecha {
	private:
		int dia;
		int mes;
		int year;

	public:
		Fecha(int = 3, int = 4, int = 2014);
		void inicializaFecha(int, int, int);
		void muestraFecha();
};

Fecha::Fecha(int dd, int mm, int yyyy) {
	dia  = dd;
	mes  = mm;
	year = yyyy;
}

void Fecha::inicializaFecha(int dd, int mm, int yyyy) {
	year = yyyy;
	mes  = mm;
	dia  = dd;
	return;
}

void Fecha::muestraFecha() {
	std::cout << "La fecha es (dia-mes-año): "
		      << dia << "-" << mes << "-" << year << std::endl;
	return;
}

int main() {
	Fecha a, b, c(21, 9, 1973);
	b.inicializaFecha(17, 6, 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
}
