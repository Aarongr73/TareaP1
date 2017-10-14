#ifndef ALGORITMOS2_H
#define ALGORITMOS2_H

//#include"hijomasizq3.h"
//#include"hijomasizq2.h"
#include"hijomasizquierdo.h"
//#include"ArbolLista.h"
//#include "arreglopuntp.h"
#include "Cola.h"
#include "listacola.h"

class Algoritmos{

private:
    void ListPreR(NodoPrincipal,Arbol& arbol);
    void ListPostR(NodoPrincipal, Arbol& arbol);
    void NumNivelesR(NodoPrincipal, int, Arbol& arbol);
    NodoPrincipal AveriguarHIR(NodoPrincipal, NodoPrincipal, Arbol& arbol);
public:

    void ListPost(Arbol& arbol);
    int NumNiveles(Arbol& arbol);
    void AveriguarHI(NodoPrincipal, Arbol arbol);
    void Agrega();
    void ListPre(Arbol& arbol);
    bool Repetidos(Arbol &arbol);
};

#endif // ALGORITMOS2_H
