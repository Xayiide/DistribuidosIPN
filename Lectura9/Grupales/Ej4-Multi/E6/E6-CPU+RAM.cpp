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

void cpu() {
	double i = 0;
	double _sin = 0, _cos = 0, _tan = 0, _log = 0, _sqrt = 0;

	while (i < 100000000) {
		_sin  += sin(i);
		_cos  += cos(i);
		_tan  += tan(i);
		_log  += log(i);
		_sqrt += sqrt(i);
		i++;
	}

	std::cout << "Sin : " << _sin  << std::endl;
	std::cout << "Cos : " << _cos  << std::endl;
	std::cout << "tan : " << _tan  << std::endl;	
	std::cout << "Log : " << _log  << std::endl;
	std::cout << "sqrt: " << _sqrt << std::endl;

	return;
}

int main() {
	std::thread th1(cpu), th2(ram);
	std::cout << "\nWaiting...\n";
	th1.join();
	th2.join();

	return 0;
}
