#include "Temperatura.hpp"
#include <iostream>
#include <math.h>

Temperatura::Temperatura(float k) {
	kelvin = k;
}

void Temperatura::setTempKelvin(float k) {
	kelvin = k;
}

void Temperatura::setTempFahrenheit(float f) {
	kelvin = round((f + 459.67) * (5.0/9.0));
}

void Temperatura::setTempCelsius(float c) {
	kelvin = round(c + 273.15);
}

float Temperatura::getTempKelvin() {
	std::cout << "Kelvin: " << kelvin << std::endl;
	return kelvin;
}

float Temperatura::getTempFahrenheit() {
	float v = kelvin * (9.0/5.0) - 459.67;
	std::cout << "Fahrenheit: " << v << std::endl;
	return v;
}

float Temperatura::getTempCelsius() {
	float v = kelvin - 273.15;
	std::cout << "Celsius: " << v << std::endl;
	return v;
}



