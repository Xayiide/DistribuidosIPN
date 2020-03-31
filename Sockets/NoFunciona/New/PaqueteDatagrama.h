#ifndef _PAQUETEDATAGRAMA_H_
#define _PAQUETEDATAGRAMA_H_

#include <netdb.h>       /* INET_ADDRSTRLEN */
#include <netinet/in.h>  /* INET_ADDRSTRLEN */


class PaqueteDatagrama {
	private:
		char         *_data;                 /* Datos a transmitir       */
		char          _ip[INET_ADDRSTRLEN];  /* IPv4 origen              */
		unsigned int  _len;                  /* Longitud de los datos    */
		int           _port;                 /* Puerto origen            */

	public:
		PaqueteDatagrama(char *, unsigned int, char *, int);
		PaqueteDatagrama(unsigned int);
		~PaqueteDatagrama();

		char         *getaddr();
		int           getport();
		char         *getdat();
		unsigned int  getlen();

		void setaddr(char *);
		void setport(int);
		void setdata(char *);
};

#endif /* _PAQUETEDATAGRAMA_H_ */
