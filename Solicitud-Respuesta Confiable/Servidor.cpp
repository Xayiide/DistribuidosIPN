#include "Respuesta.h"
#include <iostream>

using namespace std;
  
int main() {
    Respuesta server(7200);
    struct mensaje *request;
    unsigned int num[2], sum;
    int nbd=0;

    cout << "Servidor conectado..." << endl;
    while (1) {
        cout << "Esperando peticion..." << endl;
        request = server.getRequest();
	
        memcpy(num, (*request).arguments, sizeof(num));
        nbd+= num[0];
        cout << "Saldo actual: " << nbd << endl;
        server.sendReply((char *)&nbd);
	
    }
    return 0;
}
