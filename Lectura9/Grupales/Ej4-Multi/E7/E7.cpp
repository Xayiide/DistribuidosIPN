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

void save(std::string fn) {
	int i, j, k, f;
	int n = 26 * 26 * 26 * 100;
	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string big   = "";

	std::cout << "[" << fn << "] Creando palabras...\n";
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			k = std::rand() % alpha.length() + 1;
			big += alpha[k];
		}
		big += " ";
	}

	std::cout << "[" << fn << "] Palabras creadas\n";
	std::cout << "[" << fn << "] Tamaño de big: "  << big.size() << "\n";

	if ((f = open(fn.c_str(), O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1) {
		perror(fn.c_str());
		exit(2);
	}

	for (char &c : big) {
		write(f, &c, sizeof(c));
	}

	fsync(f);
	close(f);

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
	std::thread th1(save, "pepe"), th2(cpu), th3(ram);
	std::cout << "\nWaiting...\n";
	th1.join();
	th2.join();
	th3.join();

	return 0;
}
