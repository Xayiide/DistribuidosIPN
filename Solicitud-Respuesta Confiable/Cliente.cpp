#include "Solicitud.h"
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{   
    if(argc != 3){
        printf("ERROR: %s ip_servidor N\n", argv[0]);
        exit(1);
        }
    //int id_mensaje=1;
    int puertoserver = 7200;
    int nbd_cliente, nbd_servidor, id_mensaje = 0;
    int pesos;
    int res;
    Solicitud cliente;
    char *ip = argv[1];
    int depositos = atoi(argv[2]);

    /*
    srand((unsigned)time(NULL));
    int monto = 0, nbd = 0;
    if (argc != 2)
    {
        cout << "Uso: /.programa numero_solicitude\n"
             << argv[0] << endl;
        exit(0);
    }
    string i = "127.0.0.1";
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    Solicitud sol;
    int num[1], res;
    int num_sol = atoi(argv[1]);
    */


    for (int i = 0; i < depositos; i++)
    {

        srand(time(NULL));
        pesos= 1 + rand() % 9;
        cout << "Rand:" << pesos << endl;

        char *resp= cliente.doOperation(ip, 7200, 3, (char *)&pesos);
        if (resp == (char *)'\0')
        {
            //cout << "El servidor no está disponible, intente más tarde" << endl;
            exit(1);
        }
        else
        {

            memcpy(&res, resp, sizeof(res));
            nbd_cliente+= pesos;
            cout<<"nbd local: "<<nbd_cliente<<endl;
            cout<<"nbd servidor: "<<res<<endl;

            if (nbd_cliente != res)
            {
                cout << "No coinciden las cantidades"<<endl;
                exit(1);
            }
        }
    }
    return 0;
}
