#include "Coordenada.h"
#include <iostream>
using namespace std;

Coordenada::Coordenada(int xx, int yy) : x(xx), y(yy){ }

int Coordenada::getX(){
    return this->x;
}
int Coordenada::getY(){    
    return this->y;
}
void Coordenada:: setX(int a){
    this->x = a;
}
void Coordenada:: setY(int b){
    this->y = b;
}