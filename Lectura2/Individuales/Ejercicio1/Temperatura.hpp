#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura {
	private:
		float kelvin;
	public:
		Temperatura (float = 0);
		void  setTempKelvin(float);
		void  setTempFahrenheit(float);
		void  setTempCelsius(float);

		float getTempKelvin();
		float getTempFahrenheit();
		float getTempCelsius();
};

#endif
