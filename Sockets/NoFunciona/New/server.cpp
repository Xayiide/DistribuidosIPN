#include "SocketDatagrama.h"

#include <iostream>
#include <string.h>    /* memcpy    */
#include <arpa/inet.h> /* inet_ntop */

#define PORT 7200

int main(void) {
	int   nums[2];
	char *auxdata;


	/* Configure server address, create socket and bind socket */
	SocketDatagrama  sockserv = SocketDatagrama(PORT);
	PaqueteDatagrama recvdata = PaqueteDatagrama(2 * sizeof(int));
	PaqueteDatagrama senddata = PaqueteDatagrama(1 * sizeof(int));

	sockserv.printlocal();

	sockserv.setouttersize(sizeof(sockaddr_in));

	while (1) {
		sockserv.recibe(recvdata);
		sockserv.printoutter();
		auxdata = recvdata.getdat();
		memcpy(nums, auxdata, recvdata.getlen());

		int res = nums[0] + nums[1];
		
		senddata.setdata((char *) res);
		sockserv.envia(senddata);
	}

	return 0;
}