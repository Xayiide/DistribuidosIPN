#include "headers/SocketDatagrama.h"


#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

SocketDatagrama::SocketDatagrama(int puerto){
	/* Create socket */
	s = socket(AF_INET, SOCK_DGRAM, 0);

	/* Empty socket */
	bzero((char *) &direccionLocal, sizeof(direccionLocal));

	/* Fill socket */
	direccionLocal.sin_family      = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;    // inet_addr(argv[1])
	direccionLocal.sin_port        = htons(puerto);

	/* bind socket */
	bind(s, (struct sockaddr *) &direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){
	close(s);
}



int SocketDatagrama::envia(PaqueteDatagrama &pd){
	int clilen = sizeof(direccionForanea);

	/* Empty direccionForanea */
	bzero((char *) &direccionForanea, sizeof(direccionForanea));
	
	/* Fill direccionForanea */
	direccionForanea.sin_family      = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(pd.obtieneDireccion());
	direccionForanea.sin_port        = htons(pd.obtienePuerto());

	int res = sendto(s,
	                 pd.obtieneDatos(),
					 pd.obtieneLongitud(),
					 0,
					 (struct sockaddr *) &direccionForanea,
					 (socklen_t) clilen);

	// if (res<0) std::cout << "No se envio\n";
	// else       std::cout << "Se envio\n";
}

int SocketDatagrama::recibe(PaqueteDatagrama &pd){
	int clilen = sizeof(direccionForanea);
	int n = recvfrom(s,
	                 pd.obtieneDatos(),
					 pd.obtieneLongitud(),
					 0,
					 (struct sockaddr *) &direccionForanea,
					 (socklen_t *) &clilen);
	pd.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	pd.inicializaPuerto(ntohs(direccionForanea.sin_port));
	
	return n;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama &pd,
                                   time_t            secs,
								   suseconds_t       usecs) {
	int clilen          = sizeof(direccionForanea);
	timeval.tv_sec      = secs;
	timeval.tv_usec     = usecs;

	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeval, sizeof(timeval));

	int n = recvfrom(this->s,
	                 pd.obtieneDatos(),
					 pd.obtieneLongitud(),
					 0,
					 (struct sockaddr *) &direccionForanea,
					 (socklen_t *) &clilen);

	pd.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	pd.inicializaPuerto(ntohs(direccionForanea.sin_port));

	if (n < 0) {
		if (errno == EWOULDBLOCK)
			fprintf(stderr, "EWOULDBLOCK\n");
		else 
			fprintf(stderr, "SocketDatagrama::recvfrom(): %s\n", strerror(errno));
		return -1;
	}

}


struct sockaddr_in SocketDatagrama::getDirForanea() {
	return this->direccionForanea;
}
