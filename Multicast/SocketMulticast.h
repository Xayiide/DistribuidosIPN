#ifndef SOCKETMULTICAST_H_
#define SOCKETMULTICAST_H_
class SocketMulticast{
public:
SocketMulticast(int);
~SocketMulticast();
int recibe(PaqueteDatagrama & p);
int envia(PaqueteDatagrama & p, unsigned char ttl);
//Se une a un grupo multicast, recibe la IP multicast
void unirseGrupo(char *);
//Se sale de un grupo multicast, recibe la IP multicast
void salirseGrupo(char *);
private:
int s; //ID socket
struct ip_mreq multicast;
struct sockaddr_in direccionLocal;
struct sockaddr_in direccionLocal;
#endif
