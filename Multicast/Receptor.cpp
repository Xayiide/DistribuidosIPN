#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define TAM_MAX_DATA 650

int main(int argc, char const *argv[])
{
    char cadena[15];
    char* ip = (char *) argv[1];
    int puerto = atoi(argv[2]);

    SocketMulticast socketMulticast(puerto);
    PaqueteDatagrama databack(2 * sizeof(int));
    socketMulticast.recibe(databack);
    memcpy(&cadena,databack.obtieneDatos(),2 * sizeof(int));

    cout << "IP: " << databack.obtieneDireccion();
    cout << "Puerto: " << databack.obtienePuerto() <<endl;
    cout << "Cadena recibida: " << cadena << endl;

    SocketDatagrama socketDatagrama(7200);
    PaqueteDatagrama dataEnvio((char*) r ,sizeof(int),databack.obtieneDireccion(),7200);
    socketDatagrama.envia(dataEnvio);

    return 0;
}
