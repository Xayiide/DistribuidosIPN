#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "SocketMulticast.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	SocketDatagrama socket = SocketDatagrama(2345);
	char* ip = argv[1];
	int numeros[2];
	cout<<"Numero1 "; cin>>numeros[0];
	cout<<"Numero2 "; cin>>numeros[1];
	//numeros[0] = (int)*argv[2];
	//numeros[1] = (int)*argv[3];
	PaqueteDatagrama datagrama = PaqueteDatagrama((char *) numeros, 2 * sizeof(int),ip, 2345);
	socket.envia(&datagrama, &ttl);
	socket.unirseGrupo();

	PaqueteDatagrama databack =  PaqueteDatagrama(sizeof(int));
	socket.recibe(&databack);
	int * ans = (int*)databack.obtieneDatos();
	cout<< " Dirección " << datagrama.obtieneDireccion() << " puerto: " << datagrama.obtienePuerto() << endl;
	cout << "Respuesta="<<(*ans)<< endl;
	return 0;
}
