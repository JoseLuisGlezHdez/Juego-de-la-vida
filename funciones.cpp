#include "Celula.h"
#include "Tablero.h"
#include <iostream>
#include <cstdlib>



#define REVIVEN 3
#define MUEREN 2
#define MAXPOBLACION 3

#define MAX 90000


////////////////////////////////////////////////
/******FUNCIONES CLASE CELULA******************/
////////////////////////////////////////////////

void Celula::ActEstado(){

    if(estado)

        if(vecinos < MUEREN || vecinos > MAXPOBLACION)
            estado = false;
           
        
    else 
        if(vecinos == REVIVEN)
            estado = true;
            
     
}

////////////////////////////////////////////////
/******FUNCIONES CLASE TABLERO*****************/
////////////////////////////////////////////////

Tablero::Tablero(int fil, int col){

    int i,j;
    n = col;
    m = fil;

    tablero = new Celula*[n+2];

    for(i=0; i<(n+2); i++){

        tablero[i] = new Celula[m+2];
    }

    for(i=0; i<(n+2); i++){
        for(j=0; j<(m+2); j++){

            tablero[i][j] = Celula();
        }
    }
}

void Tablero::ContarVecinas(int x, int y){

    int Vivos = 0; //VECINOS VIVOS

    if(tablero[x-1][y-1].getEstado())
        Vivos++;

    if(tablero[x-1][y].getEstado())
        Vivos++;

    if(tablero[x-1][y+1].getEstado())
        Vivos++;

    if(tablero[x][y-1].getEstado())
        Vivos++;

    if(tablero[x][y+1].getEstado())
        Vivos++;

    if(tablero[x+1][y-1].getEstado())
        Vivos++;

    if(tablero[x+1][y].getEstado())
        Vivos++;

    if(tablero[x+1][y+1].getEstado())
        Vivos++;


    std::cout << "Celula: " << x << " " << y << ": " << Vivos;
    tablero[x][y].setVecinos(Vivos);
}

void Tablero::ActCelula(int x, int y){

    if(y >= 1 && y <=n && x >= 1 && x <= m)// Activamos la celula q hemos introducido x teclado
        tablero[y][x].setEstado();

}


void Tablero::MostrarTablero(){

  int i,j;
      
    for(i=1; i<=m; i++){

        std::cout << "|";

        for(j=1; j<=n; j++){
            if(tablero[j][i].getEstado())
                std::cout << " X ";
            else
                std::cout << " - ";
        }
        std::cout << "|" << std::endl;
    }

}


void Tablero::Ciclo(){

    int i,j;
    int ciclos = 0;

    while(ciclos++ <= MAX ){//mientras ciclo sea menor o igual al max establecido seguimos 

        system("clear");
        MostrarTablero();//llamamos a mostrar tablero pra q lo muestre 

        for(i=1; i<=n; i++)//recorremos el tablero para ver los vecinos de cada uno y asi llamamos a la funcion para poder analizarlos
            for(j=1; j<=m; j++)
                ContarVecinas(i, j);//analizamos los vecinos de cada uno

        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                tablero[i][j].ActEstado();//actualizamos el estado de cada celula

        usleep(900000);break;
    }
    system("clear");
    MostrarTablero();
}

