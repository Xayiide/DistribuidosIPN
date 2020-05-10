#include "SocketDatagrama.h"
#include <stdio.h>
#include <iostream> 
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	if(argc!=3){
		cout<<"Use: %s IP NombreArchivo.txt"<<argv[0]<<endl;
		exit(1);
	}

	int portServidor=7300;
	char info[34];
	string ruta=argv[2];
	ifstream archivo(ruta, ios::in);
	SocketDatagrama s(0);

	if(archivo.fail()){
		cout<<"Error al abrir el archivo"<<endl;
		exit(1);
	}
	else{
		archivo.getline(info, sizeof(info));
		info[31] = '\0';
		cout<<"Registro:"<<info<<endl;
		PaqueteDatagrama pe=PaqueteDatagrama(info, sizeof(info),argv[1],portServidor);
		s.envia(pe);
	}
	archivo.close();
}
