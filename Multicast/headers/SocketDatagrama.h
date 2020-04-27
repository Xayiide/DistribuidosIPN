#ifndef SOCKETDATAGRAMA_H_
#define SOCKECTDATAGRAMA_H_

#include "PaqueteDatagrama.h"
#include "Timeval.h"
#include <netinet/in.h>


class SocketDatagrama {
	private:
		struct Timeval timeval;
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s; //ID socket

	public:
		SocketDatagrama(int);
		~SocketDatagrama();

		//Recibe un paquete tipo datagrama proveniente de este socket
		int recibe(PaqueteDatagrama &);
		int recibeTimeout(PaqueteDatagrama &, time_t, suseconds_t);

		//Envía un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama &);
		struct sockaddr_in getDirForanea();
};

#endif /* SOCKECTDATAGRAMA_H_ */
