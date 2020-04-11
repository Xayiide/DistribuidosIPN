#include "Mensaje.h"
#include "SocketDatagrama.h"
class Respuesta
{
public:
    Respuesta(int port);
    struct mensaje *getRequest(void);
    void sendReply(char *respuesta);

private:
    SocketDatagrama *socketlocal;
    PaqueteDatagrama *clientePaqueteDatagrama;
    struct mensaje petition;
    int contador;
};
