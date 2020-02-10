#ifndef FECHA_H_
#define FECHA_H_

class Fecha {
	private:
		int    dia;
		int    mes;
		int    year;
		double darray[8192];
		char   array[8192];
	public:
		Fecha (int = 3, int = 4, int = 2014);

		int getYear();
		int getMes();
		int getDia();

		void inicializaFecha(int, int, int);
		void muestraFecha();
		void aleatorio();
		int  convierte();
		bool leapyr();

};

#endif
