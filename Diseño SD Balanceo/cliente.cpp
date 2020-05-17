#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "Solicitud.h"
#include <sys/time.h>
#include <unistd.h>
#include <iostream> 
#include <list> 
#include <thread>  
#include <iterator> 
using namespace std;
int n = 0;
list <int> lista;
list<int>::iterator itr;

struct registro GenerarVoto(int j){
	char telefono[11], curp[19], t[11], sexo;
	int i, destino, opcion, elemento;
	struct registro reg1;
	//Partidos disponibles 2018
	char const partidos[9][4] = {"PRI", "PAN", "PRD", "P_T", "VDE", "MVC", "MOR", "PES", "PNL"};
	//Entidades federativas
	char const entidad[32][3] =  {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};
	//Obtiene un elemento aleatorio de la lista de telefonos y lo elimina de la lista para evitar la repeticion
	i = n - j;
	elemento = rand()%i;		
	itr = lista.begin();
	for(int k = 0; k < elemento; k++)
		++itr;
	elemento = *itr;
	lista.erase(itr);
	sprintf(telefono, "5%9d", elemento);
	strcpy(reg1.celular, telefono);

	if(rand()%2 == 0)
		sexo = 77;
	else
		sexo = 72;
	i = rand()%32;
	sprintf(curp, "%c%c%c%c%c%c%c%c%c%c%c%s%c%c%c%c%c", 65 + rand()%25 , 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, 
	sexo, entidad[i], 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48);
	strcpy(reg1.CURP, curp);
	i = rand()%9;
	strcpy(reg1.partido, partidos[i]);
	return reg1;
}

void enviar(char* ip, int puerto, struct registro r, Solicitud s){
	timeval res;
	memcpy(&res, s.doOperation(ip, puerto, 1, (char *)&r),sizeof(timeval));
	cout << res.tv_sec << endl;
	cout << res.tv_usec << endl;
}

int main(int argc, char *argv[]){
	if (argc != 8){
		printf("Forma de uso: %s ip_servidorA puertoA ip_servidorB puertoB ip_servidorC puertoC n\n", argv[0]);
		exit(0);
	}
	srand(time(NULL));
	char* serverA_Ip = argv[1];
	int serverA_Port = atoi(argv[2]);
	char* serverB_Ip = argv[3];
	int serverB_Port = atoi(argv[4]);
	char* serverC_Ip = argv[5];
	int serverC_Port = atoi(argv[6]);
	n = atoi(argv[7]);
	int cont = 0;
	Solicitud sol;
	//Llena una lista con numeros telefonicos de 9 digitos secuenciales creibles
	int inicial = 500000000 + rand()%100000000;
	for (int i = inicial; i < inicial + n; i++) { 
		lista.push_back(i);
	}
	while(cont < n) {
		struct registro regist = GenerarVoto(cont);
		string lastc = string(regist.celular);
		lastc = lastc.back();
		int lastN = atoi(lastc.c_str());
		if(0 <= lastN and lastN <= 3){
			thread t(enviar, serverA_Ip, serverA_Port, regist, sol);
			t.detach();
		}
		else if(4 <= lastN and lastN <= 6){
			thread t(enviar, serverB_Ip, serverB_Port, regist, sol);
			t.detach();
		}
		else if(7 <= lastN and lastN <= 9){
			thread t(enviar, serverC_Ip, serverC_Port, regist, sol);
			t.detach();
		}
		usleep(1000);
		cont++;
	}
	cout << cont << endl;
	return 0;
}
