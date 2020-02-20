#include <iostream>
#include <string>
#include <random>
#include <time.h>


int main() {
	int n = 5000000;
	int i, j, k;

	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; /* 26 */
	std::string big   = "";

	std::cout << "Creando palabras..." << std::endl;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			k = std::rand() % alpha.length() + 1;
			big += alpha[k];
		}
		big += " ";
	}

	std::cout << "Palabras creadas" << std::endl;
	std::cout << "Tamaño de big: " << big.size() << std::endl;
	std::cout << "Encontrando ocurrencias de IPN..." << std::endl;

	size_t p = big.find("IPN", 0);
	int ipns = 0;
	while (p != std::string::npos) {
		ipns++;
		p = big.find("IPN", p + 1);
	}

	std::cout << "Numero de apariciones de IPN: " << ipns << std::endl;

	return 0;

}
