#include "SocketDatagrama.h"

#include <stdio.h>
#include <string.h>    /* memcpy    */
#include <arpa/inet.h> /* inet_ntop */

#define PORT 7200

int main(void) {
	
	int   nums[2] = {10, 5};
	socklen_t srvaddrsize;

	/* Configure client address. Create client Socket. Bind client socket */
	SocketDatagrama  sockclnt = SocketDatagrama(0);

	/* Configure server */
	struct sockaddr_in srv;
	memset(&srv, 0, sizeof srv);
	srv.sin_family      = AF_INET;
	srv.sin_port        = htons(PORT);
	srv.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockclnt.setoutter(srv);

	srvaddrsize = sizeof(srv);
	sockclnt.setouttersize(srvaddrsize);


	PaqueteDatagrama recvdata = PaqueteDatagrama(1 * sizeof(int));
	PaqueteDatagrama senddata = PaqueteDatagrama(2 * sizeof(int));

	senddata.setaddr("127.0.0.1");
	senddata.setport(PORT);
	senddata.setdata((char *) nums);


	sockclnt.printlocal();
	sockclnt.printoutter();

	sockclnt.envia(senddata);
	sockclnt.recibe(recvdata);

	return 0;
}