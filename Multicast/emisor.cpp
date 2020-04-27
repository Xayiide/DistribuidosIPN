#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>


#define TAM_MAX_DATA 650
using namespace std;

int main(int argc, char const *argv[]){
    char* ip;
    char ip_cad[15];
    int puerto;
    int t;
    char cad[20];
    unsigned char ttl;
    cout<<"Ingresa la ip del multicast: ";
    cin>>ip_cad;
    ip=ip_cad;
    cout<<"Ingresa el puerto: ";
    cin>>puerto;
    cout<<"Ingresa el numero de routers (TTL): ";
    cin>>t;
    ttl=(unsigned char) t;
    cout<<"Ingresa la cadena: ";
    cin>>cad;


    SocketMulticast socket=SocketMulticast(puerto);
    
    PaqueteDatagrama datagrama = PaqueteDatagrama((char *) cad, 2 * sizeof(int),ip, puerto);
    socket.envia(datagrama, ttl);

    PaqueteDatagrama databack =  PaqueteDatagrama(sizeof(int));
    socket.recibe(databack);
    
    int * ans = (int*)databack.obtieneDatos();
    cout<< " Dirección " << datagrama.obtieneDireccion() << " puerto: " << datagrama.obtienePuerto() << endl;
    cout << "Respuesta="<<(*ans)<< endl;

/*
    char* ip = (char*) argv[1];
    //int puerto = atoi(argv[2]);
    int t = atoi(argv[3]);
    unsigned char ttl = (unsigned char) t;
    int puerto=7200;

    int numeros[2];
    int resp;
    int veces = 7,n;

    cout<<"Ingrese el primer numero: ";cin>>numeros[0];
    cout<<"Ingrese el segundo numero: ";cin>>numeros[1];


    SocketMulticast socket=SocketMulticast(puerto);
    
    PaqueteDatagrama datagrama = PaqueteDatagrama((char *) numeros, 2 * sizeof(int),ip, puerto);
    socket.envia(datagrama, 1);

    //SocketMulticast socketMulticast(puerto);
    //PaqueteDatagrama paqueteDatagrama_Envio((char*) numeros,2 * sizeof(int),ip,puerto);
    
    //socketMulticast.envia(paqueteDatagrama_Envio,ttl);

/*
    SocketDatagrama socketDatagrama(7200);
    PaqueteDatagrama paqueteDatagrama_Recepcion(sizeof(int));

    do {
        n = socketDatagrama.recibeTimeout(paqueteDatagrama_Recepcion,2,500000);
        if (n == -1){
            veces--;
        } else {
            memcpy(&resp,paqueteDatagrama_Recepcion.obtieneDatos(),sizeof(int));
            cout << "IP: " << paqueteDatagrama_Recepcion.obtieneDireccion() << endl;
            cout << "Suma :" << resp << "\n" << endl;
        }
    }while((veces > 0));

    if (n == -1) {

         cout << "Se acabo el tiempo de respuesta" << endl;
         exit(0);

    } 
    PaqueteDatagrama databack =  PaqueteDatagrama(sizeof(int));
    socket.recibe(databack);
    int * ans = (int*)databack.obtieneDatos();
    cout<< " Dirección " << datagrama.obtieneDireccion() << " puerto: " << datagrama.obtienePuerto() << endl;
    cout << "Respuesta="<<(*ans)<< endl;*/
    return 0;
}
