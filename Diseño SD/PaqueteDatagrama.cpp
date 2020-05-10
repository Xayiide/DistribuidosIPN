#include <string.h>
#include <cstdlib>
#include "PaqueteDatagrama.h"
using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char* data, unsigned int Longitud, char* dirIP, int port){
    longitud=Longitud;
    datos = new char[Longitud];
    memcpy(datos, data, longitud);
    memcpy(ip, dirIP, sizeof(ip));
    puerto = port;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int Longitud){
    longitud=Longitud;
    datos = new char[longitud];
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

void PaqueteDatagrama::inicializaPuerto(int port){
    puerto=port;
}

void PaqueteDatagrama::inicializaIp(char* dirIP){
    memcpy(ip,dirIP,sizeof(ip));
}

void PaqueteDatagrama::inicializaDatos(char* data){
    memcpy(datos,data,longitud);
}

PaqueteDatagrama::~PaqueteDatagrama(){
    delete[] datos;
}

