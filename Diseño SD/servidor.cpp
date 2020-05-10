#include"SocketDatagrama.h"
#include<iostream>
#include<fstream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Uso: %s archivo.txt\n", argv[0]);
        exit(0);
    }
    int port=7300, archivo;
    SocketDatagrama servidor(port);
    PaqueteDatagrama p(34);
    cout<<">>>>>>>>> Servidor iniciado"<<endl;
    
    while(1){
        if(servidor.recibe(p)){
            cout<<"Recibiendo registro"<<endl;
            cout<<"IP:"<<p.obtieneDireccion()<<endl;
            cout<<"Puerto:"<<p.obtienePuerto()<<endl;
            cout<<"Registros:"<<p.obtieneDatos()<<endl;

            if((archivo=open(argv[1],O_WRONLY|O_CREAT)));
	        write(archivo,p.obtieneDatos(),32);
            close(archivo);
        }
    }
}
