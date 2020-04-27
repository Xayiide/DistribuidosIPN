#include "headers/SocketMulticast.h" 

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

SocketMulticast::SocketMulticast(int puerto) {
	s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	int reuse = 1;
	if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
		printf("Error al llamar a la función setsockopt\n");
		exit(0);
	}

	/* Empty direccionLocal */
	bzero((char *)&direccionLocal, sizeof(direccionLocal));

	/* Fill direccionLocal */
	direccionLocal.sin_family      = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;  // inet_addr(argv[1])
	direccionLocal.sin_port        = htons(puerto);

	/* bind socket */
	bind(s, (struct sockaddr *) &direccionLocal, sizeof(direccionLocal));
}

SocketMulticast::~SocketMulticast() {
	close(s);
}

void SocketMulticast::unirseGrupo(char *ip) {
	multicast.imr_multiaddr.s_addr = inet_addr(ip);
	multicast.imr_interface.s_addr = htonl(INADDR_ANY);

	int res = setsockopt(s, 
						 IPPROTO_IP, 
						 IP_ADD_MEMBERSHIP, 
						 (void *) &multicast, 
						 sizeof(multicast));

	if (res<0) std::cout << "No te uniste el grupo\n";
	else       std::cout << "Te uniste al grupo " << ip << "\n";
}

void SocketMulticast::salirseGrupo(char *ip) {
	if (multicast.imr_multiaddr.s_addr == inet_addr(ip))
		setsockopt(s,
				   IPPROTO_IP,
				   IP_DROP_MEMBERSHIP,
				   (void *) &multicast,
				   sizeof(multicast));       
}

int SocketMulticast::envia(PaqueteDatagrama &pd, unsigned char ttl) {
	int n = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));

	if (n < 0) {
		fprintf(stderr, "Ha ocurrido un error al enviar el paquete\n");
	} else { /* No error */
		int clilen = sizeof(direccionForanea);

		/* Empty direccionForanea */
		bzero((char *) &direccionForanea, sizeof(direccionForanea));

		/* Fill direccionForanea */
		direccionForanea.sin_family      = AF_INET;
		direccionForanea.sin_addr.s_addr = inet_addr(pd.obtieneDireccion());
		direccionForanea.sin_port        = htons(pd.obtienePuerto());

		sendto(s,
			   pd.obtieneDatos(),
			   pd.obtieneLongitud(),
			   0,
			   (struct sockaddr *) &direccionForanea,
			   (socklen_t) clilen);
	}

	/* return n */
}

int SocketMulticast::recibe(PaqueteDatagrama &pd) {
	int clilen = sizeof(direccionForanea);

	int n = recvfrom(s,
                     pd.obtieneDatos(),
                     pd.obtieneLongitud(),
                     0,
                     (struct sockaddr *) &direccionForanea,
                     (socklen_t*) &clilen);
	pd.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	pd.inicializaPuerto(ntohs(direccionForanea.sin_port));
	
	return n;
}

