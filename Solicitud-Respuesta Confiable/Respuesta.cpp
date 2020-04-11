#include "Respuesta.h"
#include <iostream>
using namespace std;
Respuesta::Respuesta(int port)
{
    socketlocal = new SocketDatagrama(port);
    clientePaqueteDatagrama = new PaqueteDatagrama(sizeof(mensaje));
    contador = 0;
}

struct mensaje *Respuesta::getRequest(void)
{
    int null = 0;
    struct mensaje aux;
    memcpy(aux.arguments, &null, sizeof(null));
    PaqueteDatagrama paq(sizeof(struct mensaje));
    socketlocal->recibe(paq);
    memcpy(clientePaqueteDatagrama, &paq, sizeof(paq));
    memcpy(&petition, clientePaqueteDatagrama->obtieneDatos(), clientePaqueteDatagrama->obtieneLongitud());
    if (petition.requestId < contador)
    {
     
        petition = aux;
        return &petition;
    }
    else
    {

        contador++;
        return &petition;
    }
}

void Respuesta::sendReply(char *respuesta)
{
    mensaje response = {.messageType = 0, .requestId = 1, .operationId = 1};
    memcpy(response.arguments, respuesta, sizeof(respuesta));
    PaqueteDatagrama paqueteDatagrama(sizeof(struct mensaje));
    paqueteDatagrama.inicializaDatos((char *)&response);
    paqueteDatagrama.inicializaIp(clientePaqueteDatagrama->obtieneDireccion());
    paqueteDatagrama.inicializaPuerto(clientePaqueteDatagrama->obtienePuerto());
    socketlocal->envia(paqueteDatagrama);
}
