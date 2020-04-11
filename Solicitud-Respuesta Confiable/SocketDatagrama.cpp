#include "SocketDatagrama.h"
#include <errno.h>


SocketDatagrama::SocketDatagrama(int port)
{
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    //bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

int SocketDatagrama::envia(PaqueteDatagrama &p)
{
    //bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    int tam = sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
    return tam;
}

int SocketDatagrama::recibe(PaqueteDatagrama &p)
{
    char datos[p.obtieneLongitud()];
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    int tam = recvfrom(s, (char *)datos, p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), ip, INET_ADDRSTRLEN);
    p.inicializaIp(ip);
    p.inicializaPuerto((int)ntohs(direccionForanea.sin_port));
    p.inicializaDatos(datos);
    return tam;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos)
{
    timeout.tv_sec = segundos;
    timeout.tv_usec = microsegundos;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    char datos[p.obtieneLongitud()];
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    int n = recvfrom(s, (char *)datos, p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    if (n < 0)
    {
        if (errno == EWOULDBLOCK)
        {
            fprintf(stderr, "-> Tiempo para recepción transcurrido\n");
        }
        else
        {
            fprintf(stderr, "Error en recvfrom\n");
        }
        n = -1;
    }
    else
    {
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(direccionForanea.sin_addr), ip, INET_ADDRSTRLEN);
        p.inicializaIp(ip);
        p.inicializaPuerto((int)ntohs(direccionForanea.sin_port));
        p.inicializaDatos(datos);
    }
    //setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, NULL, 0);
    return n;
}

SocketDatagrama::~SocketDatagrama()
{
    close(s);
}
