#include "SocketDatagrama.h"
#include <iostream>

int main() {
	// int nums[2];
	// int res;
	// socklen_t clilen;

	SocketDatagrama sockSrv = SocketDatagrama(7200);
	// clilen = sizeof(sockaddr_in);

	PaqueteDatagrama pkt = PaqueteDatagrama(2 * sizeof(char));

	while (1) {
		std::cout << "Recibiendo datos...\n";
		sockSrv.recibe(pkt);
		std::cout << "Hemos recibido: " << pkt.obtieneDatos() << "\n";
		
	}
}