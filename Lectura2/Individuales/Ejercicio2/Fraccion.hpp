#ifndef FRACCION_H_
#define FRACCION_H_

class Fraccion {
	private:
		int num;
		int den;
	public:
		Fraccion (int = 1, int = 1);
		double calcular();
		double reducir();
};


#endif
