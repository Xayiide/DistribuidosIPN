/* Debe tardar entre 7.6 - 8 segundos */

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
#include <stdlib.h>

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



int main() {

	std::thread th1(ram), th2(ram);
	std::cout << "\nWaiting...\n";
	th1.join();
	th2.join();

	return 0;

}
