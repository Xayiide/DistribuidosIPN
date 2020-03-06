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
#include <math.h>

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

int main() {
	std::thread th1(save, "pepe"), th2(ram);
	std::cout << "\nWaiting...\n";
	th1.join();
	th2.join();

	return 0;
}

