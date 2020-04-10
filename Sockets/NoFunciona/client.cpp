#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

#include <stdio.h>

int main() {
	int nums[2] = {10, 15};

	PaqueteDatagrama pqt1((char *) nums, sizeof(nums), "127.0.0.1", 7200);
	PaqueteDatagrama pqt2(sizeof(int));
	SocketDatagrama  sckt(0);

	sckt.envia(pqt1);
	sckt.recibe(pqt2);

	printf("Hemos enviado: %d y %d, y nos han devuelto: %d\n", nums[0], nums[1], pqt2.obtieneDatos());

	return 0;
}