#include "SocketMulticast.h" 
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
using namespace std;
SocketMulticast::SocketMulticast(int port)
{
	s=socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	 bzero((char *)&direccionLocal, sizeof(direccionLocal));
    //bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}
SocketMulticast::~SocketMulticast()
{
    close(s);
}
int SocketMulticast::envía(PaqueteDatagrama &p, unsigned char ttl)
{
	int cliente = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));
	int r;
        bzero((char *)&direccionForanea, sizeof(direccionForanea));
        direccionForanea.sin_family = AF_INET;
        direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
        direccionForanea.sin_port = htons(p.obtienePuerto());
        r = sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&cliente);

}
int SocketMulticast::recibe(PaqueteDatagrama &p)
{
	int cliente=setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
	char datos[p.obtieneLongitud()];
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    int tam = recvfrom(s, (char *)datos, p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &cliente);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), ip, INET_ADDRSTRLEN);
    p.inicializaIp(ip);
    p.inicializaPuerto((int)ntohs(direccionForanea.sin_port));
    p.inicializaDatos(datos);
    return tam;
}
void SocketMulticast::unirseGrupo(char *ip)
{
	int result;
	multicast.imr_multiaddr.s_addr = inet_addr(ip);
	multicast.imr_interface.s_addr = htonl(INADDR_ANY);
	result=setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
	if(result<0)
		cout<<"Error al unirse al grupo\n";
	else
		cout<<"Te uniste al grupo\n";
}
void SocketMulticast::salirseGrupo(char *ip)
{
	if ( multicast.imr_multiaddr.s_addr == inet_addr(ip) ) {
        	setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));       
		cout<<"Saliste del grupo"<<endl;
    }else{
		cout<<"Error al salir del grupo"<<endl;
}
