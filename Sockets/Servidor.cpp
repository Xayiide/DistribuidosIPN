#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h> /* bzero */

#include "SocketDatagrama.h"


using namespace std;
int main(){
	int res, clilen;
	struct sockaddr_in server_addr, msg_to_client_addr;
	//Crear el objeto SocketDatagrama
	/*se asigna una direccion al socket del servidor*/
	bzero((char *)&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=INADDR_ANY;
	server_addr.sin_port=htons(puerto);
	bind(s,(struct sockaddr *)&server_addr,sizeof(server_addr));
	clilen=sizeof(msg_to_client_addr);
	while(1){
		//Llamar a la función recibe

		/*envia la peticion al cliente. La estructura msg_to_client_addr contiene
		la direccion socket del cliente*/
		//Llamar a la funcion enviar 
		send_to(s,(char *)&res, sizeof(int), 0,(struct sockaddr*)&msg_to_client_addr,clilen);
	}
	return 0;
}
