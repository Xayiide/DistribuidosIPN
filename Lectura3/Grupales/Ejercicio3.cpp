#include "Fecha.hpp"
#include <iostream>
#


int masVieja(Fecha *f1, Fecha *f2) {
	if (f1->getYear() > f2->getYear()) {
		return 1;
	}
	else if ((f1->getYear() == f2->getYear()) &&
			 (f1->getMes()  >  f2->getMes())) {
		return 1;
	}
	else if ((f1->getYear() == f2->getYear()) &&
			 (f1->getMes()  == f2->getMes())  &&
			 (f1->getDia()  >  f2->getDia())) {
		return 1;
	}
	else if ((f1->getYear() == f2->getYear()) &&
		     (f1->getMes()  == f2->getMes())  &&
			 (f1->getDia()  == f2->getDia())) {
		return 0;
	}
	else {
		return -1;
	}

}

int main() {

	std::cout << "Entrando al bucle..." << std::endl;
	for (int i = 0; i < 1000000; i++) {
		Fecha a, b;
		a.aleatorio();	
		b.aleatorio();
		masVieja(&a, &b);
	}
	std::cout << "Saliendo del bucle..." << std::endl;

	return 0;

}
