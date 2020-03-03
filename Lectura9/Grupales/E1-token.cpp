#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

char buffer[BUFSIZ];


int main(int argc, char *argv[]) {
	int         n = 26 * 26 * 26 * 100;
	int         i, j, k, f;
	std::string linea;


	if (argc != 2) {
		std::cout << "Uso: " << argv[0] << " <fichero>" << std::endl;
		exit(1);
	}


	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; /* 26 */
	std::string big   = "";

	std::cout << "\n\nCreando palabras..." << std::endl;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			k = std::rand() % alpha.length() + 1;
			big += alpha[k];
		}
		big += " ";
	}

	std::cout << "Palabras creadas" << std::endl;
	std::cout << "Tamaño de big: " << big.size() << std::endl;

	if ((f = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1) {
		perror(argv[1]);
		exit(2);
	}

	// Medir tiempo aqui
	int  cont = 0;
	char token[4];
	for (char &c : big) {
		token[cont] = c;
		cont++;
		if (c == ' ') {
			cont = 0;
			write(f, token, 4);
		}
	}

	
	// Medir tiempo aqui e imprimir diferencia


	fsync(f);
	close(f);

	return 0;
}
