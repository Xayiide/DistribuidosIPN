#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unistd.h>
#include "gfx.h"
#include "Coordenada.h"

using namespace std;

#define VERTICES_MAX 8
#define VERTICES_MIN 12

#define PI 3.141592653

vector<Coordenada> vertices;

class asteroides {
    private:
        Coordenada centro;
        int radio;
        int nVertices;
    public:
        asteroides();
        void formarAsteroide(Coordenada centro, int radio, int nVertices);

};

void dibujarAsteroides(int num_lados){
    int i = 0;
    for(; i < num_lados-1; i++)
        gfx_line(vertices[i].getX(), vertices[i].getY(),vertices[i+1].getX(), vertices[i+1].getY());
    gfx_line(vertices[i].getX(), vertices[i].getY(), vertices[0].getX(), vertices[0].getY());
}

void asteroides::formarAsteroide(Coordenada centro, int radio, int nVertices){
    int angleRange = 360/nVertices;
    int i = 0, angle = 0;
    vertices.reserve(nVertices);
    while(angle < 360){
        vertices[i].setX(centro.getX() + radio * cos(angle));
        vertices[i].setY(centro.getY() + radio * sin(angle));
        angle += angleRange;
        i++;
    }
    dibujarAsteroides(nVertices);
}



int main(){
    int t;
    asteroides ast;
    Coordenada centre(50,50);
    gfx_open(900, 700, "Asteroides");
    gfx_color(0,200,100);
    for(t = 0; t < 200; t++){
        gfx_clear();
        ast.formarAsteroide(centre, 11,8);
        gfx_flush();
        usleep(41666);  //24 por segundo
    }
    return 0;
}