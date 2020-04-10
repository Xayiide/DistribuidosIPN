#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

#include <stdio.h>


int main() {

	SocketDatagrama sckt(7200);
	PaqueteDatagrama pkt1(2 * sizeof(int));

	sckt.recibe(pkt1);

	char *nums = pkt1.obtieneDatos();
	int num1 = (int) nums[0];
	int num2 = (int) nums[1];

	int res = num1 + num2;

	PaqueteDatagrama pkt2((char *) res, sizeof(res), "127.0.0.1", pkt1.obtienePuerto());

	sckt.envia(pkt2);

	return 0;
}