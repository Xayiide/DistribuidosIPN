#include "Fecha.hpp"
#include <iostream>


int masVieja(Fecha f1, Fecha f2) {
	if (f1.getYear() > f2.getYear()) {
		return 1;
	}
	else if ((f1.getYear() == f2.getYear()) &&
			 (f1.getMes()  >  f2.getMes())) {
		return 1;
	}
	else if ((f1.getYear() == f2.getYear()) &&
			 (f1.getMes()  == f2.getMes())  &&
			 (f1.getDia()  >  f2.getDia())) {
		return 1;
	}
	else if ((f1.getYear() == f2.getYear()) &&
		     (f1.getMes()  == f2.getMes())  &&
			 (f1.getDia()  == f2.getDia())) {
		return 0;
	}
	else {
		return -1;
	}

}

int main() {
	Fecha a(10, 10, 2010);
	Fecha b(10, 10, 2011);
	Fecha c(10, 11, 2010);
	Fecha d(11, 10, 2010);
	Fecha e(9, 10, 2010);

	int aa = masVieja(a, a);
	int ab = masVieja(a, b);
	int ac = masVieja(a, c);
	int ad = masVieja(a, d);
	int ae = masVieja(a, e);
	int bc = masVieja(b, c);

	std::cout << "a: "; a.muestraFecha();
	std::cout << "b: "; b.muestraFecha();
	std::cout << "c: "; c.muestraFecha();
	std::cout << "d: "; d.muestraFecha();
	std::cout << "e: "; e.muestraFecha();

	std::cout << std::endl;


	std::cout << "a - a: " << aa << std::endl;
	std::cout << "a - b: " << ab << std::endl;
	std::cout << "a - c: " << ac << std::endl;
	std::cout << "a - d: " << ad << std::endl;
	std::cout << "a - e: " << ae << std::endl;
	std::cout << "b - c: " << bc << std::endl;

	return 0;

}
