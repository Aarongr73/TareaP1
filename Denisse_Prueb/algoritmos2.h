#ifndef ALGORITMOS2_H
#define ALGORITMOS2_H

#include"Cola.h"
//#include"hijomasizq3.h"
//#include"hijomasizq2.h"
//#include"hijomasizquierdo.h"
#include"ArbolLista.h"
//#include "arreglopuntp.h"

class Algoritmos{

private:
    void ListPostR(NodoPrincipal, Arbol&);
    void NumNivelesR(NodoPrincipal, int, Arbol&);
   // NodoPrincipal AveriguarHIR(NodoPrincipal, NodoPrincipal, Arbol& arbol);
public:
    void ListPost(Arbol&);
    int NumNiveles(Arbol&);
    void Copiar(Arbol&);
   // void AveriguarHI(NodoPrincipal, Arbol arbol);
};

#endif // ALGORITMOS2_H
