#include "headers/Respuesta.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>

#define TAM_MAX_DATA 65000

Respuesta::Respuesta(int puerto) {
	socketlocal = new SocketDatagrama(puerto);
}

struct mensaje* Respuesta::getRequest(void ) {
	PaqueteDatagrama pdrecv(sizeof(mensaje));
	socketlocal->recibe(pdrecv);

	memcpy(&_mensaje, pdrecv.obtieneDatos(), sizeof(mensaje));

	return &_mensaje;
}

void Respuesta::sendReply(char *reply) {
	mensaje msgrep;

	memcpy(msgrep.arguments, reply, TAM_MAX_DATA);
	msgrep.messageType = 1;
	msgrep.operationId = 321;
	msgrep.messageType = 0;

	PaqueteDatagrama pdsend((char*) &msgrep, sizeof(mensaje), inet_ntoa(socketlocal->getDirForanea().sin_addr), ntohs(socketlocal->getDirForanea().sin_port));
	socketlocal->envia(pdsend);
}

SocketDatagrama *Respuesta::getSocket() {
	return this->socketlocal;
}
