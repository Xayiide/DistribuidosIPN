#include <iostream>
#include <stdlib.h> /* strtol */
#include <errno.h>  /* errno */
#include <stdlib.h> /* random */
#include <time.h>   /* init random */
#include <unistd.h> /* (u)sleep */

#include "headers/gfx.h"
#include "headers/asteroid.h"
#include "headers/coord.h"

/*****************************************************************************/
#define WINNAME    "Asteroids"
#define FRAMERATE  10000 /* Update screen every n microseconds */

const int WWDTH = 300;
const int WHGHT = 300;


void         printUsage(char **);
unsigned int checkArguments(int, char **);

void drawAsteroid(Asteroid);
void moveAsteroid(Asteroid);



// TODO: Create vector of Asteroids
//     · For every asteroid, move it
//     · For every asteroid, draw it
//     · For every asteroid, check its bounds
//              -> If out of bounds, delete it
//     · Hacer que los asteroides no crucen segmentos al dibujarse






int main(int argc, char *argv[]) {
	unsigned int          numasts; /* Number of asteroids                */
	std::vector<Asteroid> asts;    /* Vector containing all asteroids    */


	srand(time(NULL));
	numasts = checkArguments(argc, argv);
	asts.resize(numasts);


	for (auto &ast: asts) {
		ast = Asteroid(FRAMERATE);
	}

	gfx_open(WWDTH, WHGHT, WINNAME);
	gfx_color(0, 200, 100);


	while (1) {
		gfx_clear();
		for (auto &ast: asts) {
			drawAsteroid(ast);
			moveAsteroid(ast);
		}
		gfx_flush();
		usleep(FRAMERATE);
	}

}






void drawAsteroid(Asteroid ast) {
	int  ncoords              = ast.getncoords();
	std::vector<Coord> coords = ast.getcoords();

	for (int i = 0; i < ncoords; i++) {
		gfx_line(coords[i].getx(), coords[i].gety(),
					coords[(i+1)%ncoords].getx(), coords[(i+1)%ncoords].gety());
	}
}

void moveAsteroid(Asteroid ast) {
	for (auto &c: ast.getcoords()) {
		c.setx(c.getx() + ast.getxsp());
		c.sety(c.gety() + ast.getysp());
	}
}



void printUsage(char *argv[]) {
	std::cerr << "Usage: " << argv[0] << " <# of asteroids>" << std::endl;
}

unsigned int checkArguments(int argc, char *argv[]) {
	long  numAsteroids = 0;
	char *endptr;

	errno = 0;

	if (argc != 2) {
		printUsage(argv);
		exit(EXIT_FAILURE);
	}

	numAsteroids = strtol(argv[1], &endptr, 10);

	if (endptr == argv[1]) {
		std::cerr << "Argument must be an integer" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (numAsteroids < 0) {
		std::cerr << "Argument must be >= 0" << std::endl;
		exit(EXIT_FAILURE);
	}

	return (unsigned int) numAsteroids;
}
