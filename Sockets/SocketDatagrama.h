#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

#include <netinet/in.h>       /* sockaddr_in */
#include "PaqueteDatagrama.h" /* PaqueteDatagrama */

class SocketDatagrama {
	public:
		SocketDatagrama(int);
		~SocketDatagrama();

		int recibe(PaqueteDatagrama &p); /* Recibe un paquete datagrama */
		int envia(PaqueteDatagrama &p);  /* Envia un paquete datagrama */

	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int                s; /* ID socket */
};


#endif /* SOCKETDATAGRAMA_H_ */