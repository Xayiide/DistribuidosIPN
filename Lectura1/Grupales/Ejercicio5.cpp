#include <iostream>

int main() {
	int n   = 2;
	int res = n + (++n);

	std::cout << "El resultado da: " << res << std::endl;

	return 0;
}
