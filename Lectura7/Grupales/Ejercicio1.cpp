#include <iostream>
#include <string>

#include <ios>
#include <limits>

using namespace std;

/* No se limpia el buffer de std::cin y el salto de linea \n se queda
 * al leer el entero en n. Luego, cuando se llama a getline, getline lee
 * el salto de linea lo primero y se detiene */ 

int main() {
	string line;
	int    n;

	cin >> n; /*  Error */

	// cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, line);

	cout << "n: " << n << endl;
	cout << "line: " << line << endl;

	return 0;
}
