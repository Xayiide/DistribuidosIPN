class PaqueteDatagrama {
public:
PaqueteDatagrama(char *dat, unsigned int tam, char  *ipp, int puertos);
PaqueteDatagrama(unsigned int );
PaqueteDatagrama();
~PaqueteDatagrama();
char *obtieneDireccion();
unsigned int obtieneLongitud();
int obtienePuerto();
char *obtieneDatos();
void inicializaPuerto(int);
void inicializaIp(char *);
void inicializaDatos(char *);
private:
char *datos;
//Almacena los datos
char ip[16];
//Almacena la IP
unsigned int longitud;
//Almacena la longitude de la cadena de datos
int puerto;
//Almacena el puerto
};
