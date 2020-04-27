#include "mensaje.h"
#include "SocketDatagrama.h"

class Respuesta {
	public:
		Respuesta(int pl);
		struct mensaje *getRequest(void);
		void sendReply(char *respuesta);

	private:
		SocketDatagrama *localSocket;
};