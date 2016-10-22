#include <iostream>
#include <cstdlib>

#include "Celula.h"
#include "Tablero.h"


using namespace std;

int main(){

    int n, m, x, y,i,opc;
    int numeroCelulas;
    Tablero * Juego;
    
    cout <<"*******************************************************"<< endl;
    cout <<"************************JUEGO**************************"<< endl;
    cout <<"**********************DE LA VIDA***********************"<< endl;
    cout <<"*******************************************************"<< endl;
    
    
    cout << "Introduza las dimensiones del tablero "<< endl;
    cout << "\n-FILAS:";
    cin >> n;
    cout << "\n-COLUMNAS:";
    cin >> m;

    Juego = new Tablero(n,m);

    cout << " -> Introduzca el numero de celulas vivas: ";
    cin >> numeroCelulas;

    cout << " ** Introduzca las coordenadas de la célula" << endl;

    for(i=0; i<numeroCelulas; i++){
        cout << "\nCoordenadas celula " << i+1 << endl;
	cout << "\n-Fila:";
	cin >> x;
	cout << "\n-Columna:";
        cin >> y;

        Juego->ActCelula(x, y);
    }

  do
  {
    cout<<endl;
    cout <<"**********************MENU***************************"<< endl;
    cout <<"**                                                 **"<< endl;
    cout <<"**-Pulse 1 para mostrar tablero                    **"<< endl;
    cout <<"**-Pulse 2 para pasar al siguiente turno           **"<< endl;
    cout <<"**-Pulse 3 para limpiar pantalla                   **"<< endl;
    cout <<"**-Pulse 4 para salir                              **"<< endl;
    cout <<"**                                                 **"<< endl;
    cout <<"*****************************************************"<< endl;
    cout <<"\nIntroduzca su opcción: ";
    cin>>opc;
    switch(opc)
    {
      case 1:
	      Juego->MostrarTablero();
	      break;
      case 2:
	      Juego->Ciclo();
	      break;
      case 3: 
	      system("clear");
	      break;
      case 4:
	      Juego->~Tablero();
    }
  }while(opc<4);
}
    
    