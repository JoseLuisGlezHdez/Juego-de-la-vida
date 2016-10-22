#ifndef __TABLERO_H
#define __TABLERO_H


#include "Celula.h"

class Tablero {

    private:

        Celula ** tablero;
	int n, m;

    public:

        Tablero(int, int);
	
	void MostrarTablero();
	void ActCelula(int, int);
	void ContarVecinas(int, int);
	void Ciclo();
	


};

#endif