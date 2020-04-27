#include "SocketDatagrama.h"

#include <strings.h> /* bzero */
#include <unistd.h>  /* close */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

SocketDatagrama::SocketDatagrama(int puertoL) {
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(struct sockaddr_in));
	bzero((char *)&direccionForanea, sizeof(struct sockaddr_in));

	direccionLocal.sin_family      = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port        = htons(puertoL);
	bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama() {
	close(s);
}

//Recibe un paquete tipo datagrama proveniente de este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p) {
	int retorno;
	socklen_t clilen; //Ojo no compila si es un tipo int en C
	clilen  = sizeof(direccionForanea);
	retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));

	return retorno;
}

//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p) {
	direccionForanea.sin_family      = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port        = htons(p.obtienePuerto());
	sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}