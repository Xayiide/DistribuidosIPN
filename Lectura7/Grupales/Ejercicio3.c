#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; /* 26 */

char *concat(char *big, char *word, int biglen) {
	/* 4 chars for "ABC " and one more char for \0 */
	big = (char *) realloc(big, (biglen + 4 + 1) * sizeof(char));
	if (!big) {
		free(big);
		printf("realloc() failed\n");
		exit(1);
	}
	memcpy(big + biglen, word, 5);
	free(word);
	return big;
}

char *createword() {
	int   j, k;
	char *tmp = (char *) malloc(5);
	for (j = 0; j < 3; j++) {
		k = rand() % 26; /* k -> [0, 25] */
		tmp[j] = alpha[k];
	}
	tmp[3] = ' ';
	tmp[4] = '\0';

	return tmp;
}

int main() {
	int   i;
	int   numchars = 0;
	int   n = 5000000;
	char *word;
	
	srand(time(NULL));
	printf("Creando palabras...\n");

	char *big = createword();
	numchars += 4; /* "ABC " */

	for (i = 0; i < n; i++) {
		word = createword();
		big  = concat(big, word, numchars);
		numchars += 4;
	}

	printf("Palabras creadas\n");
	printf("Tamaño de big: %d\n", numchars);
	printf("Encontrando ocurrencias de IPN...\n");

	int cont = 0;
	while (big = strstr(big, "IPN")) {
		cont++;
		big += 4;
	}
	printf("Numero de apariciones de IPN: %d\n", cont);

	free(big);
	return 0;
}
