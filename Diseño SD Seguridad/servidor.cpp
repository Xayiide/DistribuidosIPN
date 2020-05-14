#include "Respuesta.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <algorithm>    // std::binary_search, std::sort
using namespace std;
int main()
{
    Respuesta resp(7200);
    vector <int> registros;
    cout << "Servidor iniciado....\n";
    std::ofstream file1("registros.txt", std::ofstream::out | std::ofstream::trunc); //creamos el archivo de salida 
    file1.close();
    ofstream output;
    while (true) {
        struct mensaje *m = resp.getRequest(); //peticiones al servidor 
        if(m != NULL) {
            output.open("registros.txt", ios::out | ios::app ); //abrimos el archivo
            struct registro r;
            memcpy(&r, &m->arguments, sizeof(struct registro));
            timeval tiempo; // struct timeval 
            tiempo.tv_sec = 0; // mide los segundos 
            tiempo.tv_usec = 0; //mide los microsegundos 
            if(!binary_search(registros.begin(), registros.end(),atoi(r.celular))){ //buscamos el numero de telefono 
                registros.push_back(atoi(r.celular)); //convierte el numero del celular en un entero y lo guarda en el vector 
                sort(registros.begin(), registros.end()); // organiza de forma ascendente el vector 
                gettimeofday(&tiempo,NULL); //
                string regs = r.toString(); //guarda el registro como string 
                cout <<"Segundos: "<<tiempo.tv_sec << endl; //imprime segundos en la terminal 
                cout <<"Microsegundos: "<<tiempo.tv_usec << endl; //imprime microsegundos en la terminal 
                regs += to_string(tiempo.tv_sec) + to_string(tiempo.tv_usec); //concatena los registros con sus tiempos 
                output.write(regs.c_str(), regs.length()); //escribe el registro en el archivo 
                output.write("\n",1);
                output.flush(); //
                resp.sendReply((char *)&tiempo); //envia la respuesta 
            }else{
            	cout << "El numero de telefono ya fue registrado" << endl;
                cout<<"Segundos: "<<tiempo.tv_sec<<endl;
                cout<<"Microsegundos: "<<tiempo.tv_usec<<endl;
                resp.sendReply((char *)&tiempo); //envia la respuesta
            }
            output.close();//cerramos el archivo 
        }
        cout << endl;
    }
}
