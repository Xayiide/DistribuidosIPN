#ifndef _PAQUETEDATAGRAMA_H_
#define _PAQUETEDATAGRAMA_H_

#include <netdb.h>       /* INET_ADDRSTRLEN */
#include <netinet/in.h>

class PaqueteDatagrama {
	private:

	public:
		PaqueteDatagrama(char *, unsigned int, char *, int);
		PaqueteDatagrama(unsigned int);
		~PaqueteDatagrama();


		

};



#endif /* _PAQUETEDATAGRAMA_H_*/