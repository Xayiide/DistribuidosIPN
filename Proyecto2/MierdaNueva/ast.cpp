#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unistd.h>
#include "gfx.h"

using namespace std;

#define VERTICES_MAX 8
#define VERTICES_MIN 12

#define PI 3.141592653

vector<vector<int>> vertices;

class Asteroides {
    private:
        int *centro = new int[2]();
        int radio;
        int nVertices;
    public:
        //Asteroides();
        void setCentro(int, int);
        void formarAsteroide( int radio, int nVertices);

};

void dibujarAsteroides(int num_lados){
    int i = 0;
    for(; i < num_lados-1; i++)
        gfx_line(vertices[i][0], vertices[i][1],vertices[i+1][0], vertices[i+1][1]);
    gfx_line(vertices[i][0], vertices[i][1], vertices[0][0], vertices[0][1]);
}
void Asteroides::setCentro(int x, int y){
    centro[0] = x;
    centro[1] = y;
}

void Asteroides::formarAsteroide(int radio, int nVertices){
    int angleRange = 360/nVertices;
    int i = 0, angle = 0;
    //vertices.reserve(nVertices);
    // while(angle < 360){
    //     vertices[i][0]=centro[0] + radio * cos(angle);
    //     vertices[i][1]=centro[1] + radio * sin(angle);
    //     angle += angleRange;
    //     i++;
    // }
    // dibujarAsteroides(nVertices);
}



int main(){
    int t;
    Asteroides ast;
    ast.setCentro(50,50);
    gfx_open(900, 700, "Asteroides");
    gfx_color(0,200,100);
    for(t = 0; t < 200; t++){
        gfx_clear();
        ast.formarAsteroide(11,8);
        gfx_flush();
        usleep(41666);  //24 por segundo
    }
    return 0;
}