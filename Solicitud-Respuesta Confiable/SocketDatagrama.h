#ifndef __SOCKET_DATAGRAMA__
#define __SOCKET_DATAGRAMA__
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string>
#include <unistd.h>

using namespace std;
class SocketDatagrama
{
public:
    SocketDatagrama(int);
    ~SocketDatagrama();
    int recibe(PaqueteDatagrama &p);
    int envia(PaqueteDatagrama &p);
    int recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);

private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    timeval timeout;
    int s;
};
#endif
