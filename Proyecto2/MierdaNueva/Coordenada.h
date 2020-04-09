#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada
{
private:
    int x, y;
public:
    Coordenada(int = 0, int = 0);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
};

#endif
