#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

char buffer[BUFSIZ];

int main(int argc, char *argv[]) {

	int    f;
	string linea;

	if (argc != 2) {
		cout << "Uso: " << argv[0] << " <fichero>\n";
		exit(1);
	}

	cout << "Texto [max " << BUFSIZ << " chars]\n";

	getline(cin, linea);
	strcpy(buffer, linea.c_str());
	
	if ((f = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1) {
		perror(argv[1]);
		exit(2);
	}

	write(f, buffer, strlen(buffer));
	fsync(f);
	close(f);
}
