#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <iostream>
#include <math.h>


void cpu() {
	double i = 0;
	double _sin = 0, _cos = 0, _tan = 0, _log = 0, _sqrt = 0;

	while (i < 100000000) {
		_sin  += sin(i);
		_cos  += cos(i);
		_tan  += tan(i);
		_log  += log(i);
		_sqrt += sqrt(i);
		i++;
	}

	std::cout << "Sin : " << _sin  << std::endl;
	std::cout << "Cos : " << _cos  << std::endl;
	std::cout << "tan : " << _tan  << std::endl;	
	std::cout << "Log : " << _log  << std::endl;
	std::cout << "sqrt: " << _sqrt << std::endl;

	return;
}

int main() {
	std::thread th1(cpu), th2(cpu);
	std::cout << "Waiting...\n";
	th1.join();
	th2.join();

	return 0;

}
