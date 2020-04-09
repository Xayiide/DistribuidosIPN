#include "gfx.h"
#include <unistd.h>
using namespace std;

int main(){
    int t;
    gfx_open(900, 700, "Ejemplo Micro Animacion GFX");
    gfx_color(0,200,100);
    for(t = 0; t < 200; t++){
        gfx_clear();
        gfx_line( 100, 100, 150, 150 );
        //gfx_line(t*5+80, t*3+40, t*3+40, t*5+80);
        gfx_flush();
        usleep(41666);  //24 por segundo
    }
    return 0;
}
