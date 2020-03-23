#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <random> /* random */
#include <time.h>   /* time() */
#include <sys/socket.h> /* inet_addr */
#include <netinet/in.h> /* inet_addr */ 
#include <arpa/inet.h>  /* inet_addr */ 

int main() {
	int num[2], res;

	srand(time(NULL));
	num[0] = std::rand() % 10 + 1; /* 1 - 10 */
	num[1] = std::rand() % 10 + 1;

	SocketDatagrama sockClnt = SocketDatagrama(0); /* Assign any port */

	/* Lo que vamos a enviar en realidad son dos caracteres que representan
	   dos numeros */
	PaqueteDatagrama pkt = PaqueteDatagrama(2 * sizeof(char));
	pkt.inicializaDatos((char *) num);
	pkt.inicializaIp("127.0.0.1");
	pkt.inicializaPuerto(7200); /* Puerto en el que escucha el servidor */
	


}