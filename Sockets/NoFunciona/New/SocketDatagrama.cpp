#include "SocketDatagrama.h"

#include <stdio.h>       /* printf */
#include <string.h>      /* memset */
#include <arpa/inet.h>   /* htons  */
#include <unistd.h>      /* close  */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


/* Set local address and port. Create socket and bind it */
SocketDatagrama::SocketDatagrama(int port) {
	struct sockaddr_in salocal;
	memset(&salocal.sin_zero, 0, sizeof salocal.sin_zero);
	salocal.sin_family      = AF_INET;
	salocal.sin_port        = htons(port);
	salocal.sin_addr.s_addr = inet_addr("127.0.0.1");

	setlocal(salocal);

	/* TODO: Error checking */
	_sockfd = socket(_local.sin_family, SOCK_DGRAM, 0);

	/* TODO: Error checking */
	bind(_sockfd, (struct sockaddr *) &_local, sizeof(_local));
}

SocketDatagrama::~SocketDatagrama() {
	close(_sockfd);
}

void SocketDatagrama::setlocal(sockaddr_in sa) {
	memset(&_local, 0, sizeof _local);
	_local.sin_family      = sa.sin_family;
	_local.sin_port        = sa.sin_port;
	_local.sin_addr.s_addr = sa.sin_addr.s_addr;
}

void SocketDatagrama::setoutter(sockaddr_in sa) {
	memset(&_outter, 0, sizeof _outter);
	_outter.sin_family     = sa.sin_family;
	_local.sin_port        = sa.sin_port;
	_local.sin_addr.s_addr = sa.sin_addr.s_addr;
}

void SocketDatagrama::setouttersize(socklen_t size) {
	_outteraddrsize = size;
}

sockaddr_in* SocketDatagrama::getlocal() {
	return &_local;
}

sockaddr_in* SocketDatagrama::getoutter() {
	return &_outter;
}

socklen_t SocketDatagrama::getouttersize() {
	return _outteraddrsize;
}




void SocketDatagrama::printlocal() {
	char s[INET_ADDRSTRLEN];
	inet_ntop(_local.sin_family, (struct sockaddr *) &_local, s, sizeof s);
	printf("[+] Nuestra IP: %s:%d\n", s, _local.sin_port);
}

void SocketDatagrama::printoutter() {
	char s[INET_ADDRSTRLEN];
	inet_ntop(_outter.sin_family, (struct sockaddr *) &_outter, s, sizeof s);
	printf("[+] IP externa: %s:%d\n", s, _outter.sin_port);
}


int SocketDatagrama::recibe(PaqueteDatagrama &pd) {
	/* Vamos a recibir dos enteros. Los almacenaremos en los datos de pd y ya */
	int nums[2], ret;
	ret = recvfrom(_sockfd,
				   (char *) nums,
				   pd.getlen(),
				   0,
				   (struct sockaddr *) &_outter,
				   &_outteraddrsize);
	pd.setdata((char *) nums);

	printf("Hemos recibido: %s-\n", (char *) nums);
	return ret;
}

int SocketDatagrama::envia(PaqueteDatagrama &pd) {
	/* Vamos a enviar lo que sea que haya en pd */
	int nums[2];
	char *aux = pd.getdat();
	memcpy(&nums, aux, pd.getlen());

	printf("Vamos a enviar: %s-\n", aux);

	return sendto(_sockfd,
				  (char *) &nums,
				  pd.getlen(),
				  0,
				  (struct sockaddr *) &_outter,
				  _outteraddrsize);
}