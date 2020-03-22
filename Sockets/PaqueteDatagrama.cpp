#include "PaqueteDatagrama.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int tam, char *ipp,int puertos)
{
	dat=new char[tam];
	ipp=new char[16];
	memcpy(ip,ipp,16);
	longitud=tam;
	puerto=puertos;
}
PaqueteDatagrama::PaqueteDatagrama(unsigned int tam) : longitud(tam){
	datos=new char[tam];
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
	puerto=p;
}
void PaqueteDatagrama::inicializaIp(char *ipp){
	ipp=new char[16];
	memcpy(ip,ipp,16);
}
void PaqueteDatagrama::inicializaDatos(char *dat){
	datos=dat;
}
