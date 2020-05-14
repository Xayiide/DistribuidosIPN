#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include "registro.h"
class Respuesta{
	public:
	 	Respuesta(int pl);
	 	struct mensaje *getRequest(void);
		void sendReply(char *respuesta);
		int getError( void );
	private:
	    SocketDatagrama *socketlocal;
	    unsigned int contRequest;
};