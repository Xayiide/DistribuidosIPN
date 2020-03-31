#include "PaqueteDatagrama.h"

#include <string.h> /* memcpy */
#include <netdb.h>  /* INET_ADDRSTRLEN */

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int tam,
									char *ip, int port) {
	_data = new char[tam];
	_len  = tam;
	_port = port;

	memcpy(_data, dat, _len);
	memcpy(_ip, ip, INET_ADDRSTRLEN);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam) {
	_data = new char[tam];
	_len  = tam;
}


PaqueteDatagrama::~PaqueteDatagrama() {
	delete[] _data;
}

/********************** Getters & Setters **********************/

char *PaqueteDatagrama::getaddr() {
	return _ip;
}

int PaqueteDatagrama::getport() {
	return _port;
}

char *PaqueteDatagrama::getdat() {
	return _data;
}

unsigned int PaqueteDatagrama::getlen() {
	return _len;
}


void PaqueteDatagrama::setaddr(char *addr) {
	memcpy(_ip, addr, INET_ADDRSTRLEN);
}

void PaqueteDatagrama::setdata(char *dat) {
	memcpy(_data, dat, _len);
}

void PaqueteDatagrama::setport(int port) {
	_port = port;
}

