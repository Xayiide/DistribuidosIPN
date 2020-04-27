#include "SocketDatagrama.h"

class Solicitud {
	public:
		Solicitud();
		char *doOperation(char *IP, int puerto, int opID, char *args);

	private:
		SocketDatagrama *localSocket;
};