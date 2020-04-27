#include "headers/SocketMulticast.h"
#include "headers/SocketDatagrama.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>


#define TAM_MAX_DATA 650
using namespace std;

int main(int argc, char const *argv[]){
	if (argc != 4){
		std::cout << "usage: " << argv[0] << " <ip> <port> <ttl>\n";
		return -1;
	}

	char          *ip     = (char *) argv[1];
	int            puerto = atoi(argv[2]);
	int            t      = atoi(argv[3]);
	unsigned char  ttl    = (unsigned char) t;

	int numeros[2];
	int resp;
	int intentos = 7,n;

	std::cout << "[>] Primer numero:  "; std::cin >> numeros[0];
	std::cout << "[>] Segundo numero: "; std::cin >> numeros[1];
	std::cout << "\n\n";
	SocketMulticast mcastsock(puerto);
	PaqueteDatagrama pdsend((char*) numeros, 2 * sizeof(int), ip, puerto);
	
	mcastsock.envia(pdsend, ttl);

	SocketDatagrama dgsock(7200);
	PaqueteDatagrama pdrecv(sizeof(int));

	do {
		n = dgsock.recibeTimeout(pdrecv, 2, 600000);
		if (n == -1){
			intentos--;
		} else {
			memcpy(&resp, pdrecv.obtieneDatos(), sizeof(int));            
			std::cout << "IP:   " << pdrecv.obtieneDireccion() << std::endl;            
			std::cout << "Suma: " << resp << "\n" << std::endl;
			std::cout << "\n\n";
		}
	} while((intentos > 0));

	if (n == -1) {
		std::cout << "Tiempo de respuesta agotado\n";
		exit(0);
	} 

	return 0;
}
