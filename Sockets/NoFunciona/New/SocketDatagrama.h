#ifndef _SOCKETDATAGRAMA_H_
#define _SOCKETDATAGRAMA_H_


#include "PaqueteDatagrama.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

class SocketDatagrama {
	private:
		struct sockaddr_in _local;
		struct sockaddr_in _outter;
		int                _sockfd;
		socklen_t          _outteraddrsize;

	public:
		SocketDatagrama(int);
		~SocketDatagrama();

		void setlocal(sockaddr_in);
		void setoutter(sockaddr_in);
		void setouttersize(socklen_t);
		
		sockaddr_in* getlocal();
		sockaddr_in* getoutter();
		socklen_t    getouttersize();

		void printlocal();
		void printoutter();

		int recibe(PaqueteDatagrama &p);
		int envia(PaqueteDatagrama &p);
};

#endif /* _SOCKETDATAGRAMA_H_ */