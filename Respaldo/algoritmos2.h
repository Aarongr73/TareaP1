#ifndef ALGORITMOS2_H
#define ALGORITMOS2_H

//#include"hijomasizq3.h"
#include"hijomasizq3.h"
//#include"hijomasizquierdo.h"
//#include"ArbolLista.h"
//#include "arreglopuntp.h"

class Algoritmos{

private:
    void ListPostR(NodoPrincipal);
    void NumNivelesR(NodoPrincipal, int);
    NodoPrincipal AveriguarHIR(NodoPrincipal, NodoPrincipal);
public:
    void ListPost();
    int NumNiveles();
    void AveriguarHI(NodoPrincipal);
    void Agrega();
};

#endif // ALGORITMOS2_H
