#include <sys/socket.h> /* socket          */
#include <sys/types.h>  /* socket. POSIX.1 */
#include <arpa/inet.h>  /* htons ...       */
#include <netinet/in.h> /* inet_addr       */
#include <netinet/ip.h> /* sockaddr_in     */
#include <strings.h>    /* bzero           */
#include <stdio.h>      /* vscode dice que NULL is undefined si no */
#include <unistd.h>     /* close           */

#include "SocketDatagrama.h"


/* p es el nombre del puerto al que vamos a conectarnos */
SocketDatagrama::SocketDatagrama(int port) {

	bzero(&this->direccionForanea, sizeof(this->direccionForanea));
	bzero(&this->direccionLocal, sizeof(this->direccionLocal));

	this->s = socket(AF_INET, SOCK_DGRAM, 0);

	direccionLocal.sin_family      = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;  /* Asigname cualquier IP */
	direccionLocal.sin_port        = htons(port); /* Asigname el puerto x */

	bind(s, (struct sockaddr *) &direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama() {
	close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &pd) {
	int ret, res = 0;
	ret = recvfrom(s, &res, sizeof(int), 0, NULL, NULL);
	pd.inicializaDatos((char *) res);
	return ret;
}

int SocketDatagrama::envia(PaqueteDatagrama &pd) {
	int ret;
	struct sockaddr_in aux;
	aux.sin_family      = AF_INET;
	aux.sin_addr.s_addr = inet_addr(pd.obtieneDireccion());
	aux.sin_port        = pd.obtienePuerto();
	ret = sendto(s, pd.obtieneDatos(), 2 * sizeof(int), 0, (struct sockaddr *) &aux, sizeof(aux));
	return ret;
}

sockaddr_in SocketDatagrama::getlocal() {
	return direccionLocal;
}

sockaddr_in SocketDatagrama::getoutter() {
	return direccionForanea;
}


