#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>
#include <thread>

#define numElem 459999999

void ram() {
	int *arr, i;
	
	arr = new int[numElem];
	for (i = 0; i < numElem; i++)
		arr[i] = 0;

	for (i = 0; i < 100000000; i++)
			arr[rand() % numElem] = rand();

	return;
}

void cpu() {
	int n = 85000000;
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

	return;

}

int main() {
	std::thread th1(cpu), th2(ram);
	std::cout << "\nWaiting...\n";
	th1.join();
	th2.join();

	return 0;
}
