#include "headers/Solicitud.h"
#include "headers/PaqueteDatagrama.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

#define TAM_MAX_DATA 65000

Solicitud::Solicitud() {
	socketLocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *ip,
                             int puerto,
							 int operationid,
							 char *arguments,
							 unsigned int id) {
	mensaje msgsend;
	mensaje m;
	int veces = 7;
	int n, resp;

	memcpy(msgsend.arguments, arguments, TAM_MAX_DATA);
	msgsend.messageType = 0;
	msgsend.operationId = operationid;
	msgsend.requestId   = id;

	std::cout << msgsend.arguments << std::endl;

	PaqueteDatagrama pdsend((char*) &msgsend, sizeof(mensaje), ip, puerto);
	std::cout << "Esperando respuesta del servidor...\n";
   
	PaqueteDatagrama pdrecv(sizeof(mensaje));

	do {
		socketLocal -> envia(pdsend);
		n = socketLocal->recibeTimeout(pdrecv, 2, 500000);
		if (n != -1)
			break;
		veces--;
		std::cout << "Veces: " << veces << "\n";
	} while(veces > 0);

	if (n == -1) {
		 std::cout << "Se ha agotado el tiempo de respuesta\n";
		 exit(0);
	} else {
		std::cout << "Cliente: \n" <<  "IP:" << pdrecv.obtieneDireccion();
		std::cout << ", Puerto: " << pdrecv.obtienePuerto() << "\n" << std::endl;

		memcpy(&_mensaje, pdrecv.obtieneDatos(), sizeof(mensaje));
		memcpy(&resp,&_mensaje.arguments,sizeof(int));
		std::cout << "La respuesta es: " << resp << "\n"; 
	}


	return _mensaje.arguments;
}

SocketDatagrama *Solicitud::getSocket() {
	return this->socketLocal;
}
