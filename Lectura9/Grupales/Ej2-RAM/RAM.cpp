/* Debe tardar entre 7.6 - 8 segundos */

#include <iostream>
#include <stdlib.h>

using namespace std;

#define numElem 459999999

int main() {
	int *arreglo, i;

	arreglo = new int[numElem];

	for (i = 0; i < numElem; i++)
		arreglo[i] = 0;
	
	for (i = 0; i < 100000000; i++)
		arreglo[rand() % numElem] = rand();

	return 0;

}
