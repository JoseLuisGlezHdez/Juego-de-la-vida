#ifndef __CELULA_H
#define __CELULA_H

class Celula {
  
  private:
    
    bool estado;
    int vecinos;
    //static int celulasVivas;
    
  public:
    
    Celula() { estado = false; vecinos = 0; }
    
    bool getEstado() { return estado; }	// Obtiene el estado de la celula
    
    void setEstado(){ estado = true; }	//Consulta las celulas vivas y actualiza el estado de la celula

    void resetEstado(){ estado = false; }

    //int getCelulasVivas(){ return celulasVivas; }
    
    int getVecinas() { return vecinos; }	// Obtiene el numero de vecinas vivas
    
    void setVecinos(int _vecinos) { vecinos = _vecinos; } // Actualiza el numero de vecinas vivas
    void ActEstado();

};



#endif