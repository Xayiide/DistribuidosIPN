#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <random>       /* random    */
#include <time.h>       /* time()    */
#include <sys/socket.h> /* inet_addr */
#include <netinet/in.h> /* inet_addr */ 
#include <arpa/inet.h>  /* inet_addr */ 
#include <iostream>     /* std::cout */
#include <unistd.h>     /* close */

int main() {
	int num[2];

	srand(time(NULL));
	num[0] = std::rand() % 10 + 1; /* 1 - 10 */
	num[1] = std::rand() % 10 + 1;
	std::cout << "num[0]: " << num[0] << "\n";
	std::cout << "num[1]: " << num[1] << "\n";

	SocketDatagrama sockClnt = SocketDatagrama(10000); /* Assign any port */

	/* Lo que vamos a enviar en realidad son dos caracteres que representan
	   dos numeros */
	PaqueteDatagrama pkt = PaqueteDatagrama(2 * sizeof(char));
	pkt.inicializaDatos((char *) num); /* Datos que vamos a enviar al serv */
	pkt.inicializaIp("127.0.0.1"); /* IP del servidor */
	pkt.inicializaPuerto(7200); /* Puerto en el que escucha el servidor */


	char *ipclient   = sockClnt.getlocal();
	char *ipserver   = sockClnt.getoutter();
	int   portclient = sockClnt.getlocalport();
	int   portserver = sockClnt.getoutterport();
	std::cout << "[Client]: " << ipclient << ":" << portclient << "\n";
	std::cout << "[Server]: " << ipserver << ":" << portserver << "\n";
	std::cout << "[Server]: " << pkt.obtieneDireccion() << ":" << pkt.obtienePuerto() << "\n";
	
	std::cout << "Enviando los dos enteros...\n";
	sockClnt.envia(pkt);
	sockClnt.recibe(pkt);

	std::cout << "El resultado es: " << pkt.obtieneDatos() << "\n";
	sockClnt.~SocketDatagrama();
	pkt.~PaqueteDatagrama();

	return 0;
}