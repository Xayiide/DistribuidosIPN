#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

#include "PaqueteDatagrama.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>


class SocketDatagrama {
	public:
		SocketDatagrama(int);
		~SocketDatagrama();

		int recibe(PaqueteDatagrama &p);
		int envia(PaqueteDatagrama &p);

	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s;
};

#endif /* SOCKETDATAGRAMA_H_ */