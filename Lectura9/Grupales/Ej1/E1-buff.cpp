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
			k = std::rand() % alpha.length();
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

	unsigned int  cont = 0;
	while (cont < big.size()) { /* 7030400 */
		big.copy(buffer, BUFSIZ, cont);
		cont += BUFSIZ;
		write(f, buffer, strlen(buffer));
	}

	struct stat fileinfo;
	int data = fstat(f, &fileinfo);
	if (data != 0) {
		perror("fstat");
		exit(3);
	}
	fileinfo.st_size % BUFSIZ == 0 ?
		std::cout << "Tamaño cuadra"    << std::endl :
		std::cout << "Tamaño no cuadra" << std::endl;


	fsync(f);
	close(f);

	return 0;
}
