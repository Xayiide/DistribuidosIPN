#include "Fecha.hpp"
#include <iostream>

int main() {
	// Fecha a(32, 1, 1970); /* Dia debe estar entre 1 y 31 */
	// Fecha b(30, 0, 1970); /* Mes debe estar entre 1 y 12 */
	// Fecha d(1, 1, 2021);  /* Year debe estar entre 0 y 2020 */
	Fecha c(1, 1, 0); /* OK */
	c.muestraFecha();


	return 0;
}
