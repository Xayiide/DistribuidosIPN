#include "Solicitud.h"
#include <stdlib.h>
#include <iostream>
int cont = 0;
Solicitud::Solicitud()
{
    socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{
    short n = 7;
    time_t segundos = 2;
    suseconds_t microsegundos = 500000;

    struct mensaje datos;
    datos.messageType = 1123456;
    datos.requestId = cont;
    datos.operationId = suma;
    memcpy(datos.arguments, arguments, sizeof(arguments));
    PaqueteDatagrama paq((char *)&datos, sizeof(datos), IP, puerto);

    int result = -1;
    while ((n--) > 0 && result < 0)
    {
        fflush(stdout);
        socketlocal->envia(paq);
        result = socketlocal->recibeTimeout(paq, segundos, microsegundos);
        if (result > 0)
        {
            cont++;
            break;
        }
    }
    if (n < 0)
    {
        printf("Servidor no disponible\n");
        exit(0);
    }
    memcpy(&response, paq.obtieneDatos(), paq.obtieneLongitud());

    return response.arguments;
}
