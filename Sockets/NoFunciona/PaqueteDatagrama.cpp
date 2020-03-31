#include "PaqueteDatagrama.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int tam, char *ipp, int port)
{
	datos = new char[tam];
	memcpy(datos, dat, strlen(dat));
	memcpy(ip, ipp, sizeof(ip)); /* sizeof(ip) para que no desborde */
	longitud = tam;
	puerto   = port;
}
PaqueteDatagrama::PaqueteDatagrama(unsigned int tam) : longitud(tam){
	datos = new char[tam];
}
PaqueteDatagrama::~PaqueteDatagrama() {
	delete[] datos;
}
char* PaqueteDatagrama::obtieneDireccion(){
	return ip;
}
unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}
int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}
char* PaqueteDatagrama::obtieneDatos(){
	return datos;
}
void PaqueteDatagrama::inicializaPuerto(int p){
	puerto = p;
}
void PaqueteDatagrama::inicializaIp(char *ipp){
	memcpy(ip, ipp, sizeof(ip)); /* sizeof(ip) para no desbordar el array */
}
void PaqueteDatagrama::inicializaDatos(char *dat){
	memcpy(datos, dat, strlen(dat));
}
