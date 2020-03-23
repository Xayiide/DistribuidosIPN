#include <sys/socket.h> /* socket          */
#include <sys/types.h>  /* socket. POSIX.1 */
#include <arpa/inet.h>  /* htons ...       */
#include <netinet/in.h> /* inet_addr       */
#include <strings.h>    /* bzero           */


#include "SocketDatagrama.h"


/* p es el nombre del puerto al que vamos a conectarnos */
SocketDatagrama::SocketDatagrama(int port) {

	bzero(&this->direccionForanea, sizeof(this->direccionForanea));
	bzero(&this->direccionLocal, sizeof(this->direccionLocal));

	this->s = socket(AF_INET, SOCK_DGRAM, 0);

	direccionLocal.sin_family      = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;  /* Asigname cualquier IP */
	direccionLocal.sin_port        = htons(port); /* Asigname el puerto x */
}

int SocketDatagrama::recibe(PaqueteDatagrama &pd) {
	int num;
	socklen_t clilen = sizeof(this->direccionForanea);
	recvfrom(this->s, 
			(char *) num,
			sizeof(int),
			0,
			(struct sockaddr *) &this->direccionForanea,
			&clilen);
	pd.inicializaDatos((char *) num);
}
