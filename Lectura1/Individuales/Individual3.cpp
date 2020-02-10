/* Programa que reciba de STDIN un valor entero de segundos
 * e imprima su equivalente en h, m, s */
#include <iostream>

int main(int argc, char *argv[]) {
	int t    = 0;
	int hrs  = 0;
	int min  = 0;
	int seg  = 0;

	std::cout << "Introduzca segundos > ";
	std::cin >> t;
	std::cout << std::endl;

	if (t < 0) {
		std::cout << "El valor debe ser positivo" << std::endl;
		return 1;
	}

	if (t == 0) {
		std::cout << "0 horas 0 minutos 0 segundos" << std::endl;
		return 0;
	}

	hrs = t/3600;
	t = t - hrs * 3600;

	min = t/60;
	t = t - min * 60;

	std::cout << hrs << " horas "
		      << min << " minutos "
			  << t   << " segundos " << std::endl;
	return 0;
}
