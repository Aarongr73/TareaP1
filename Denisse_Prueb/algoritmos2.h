#ifndef ALGORITMOS2_H
#define ALGORITMOS2_H

#include"Cola.h"
//#include"hijomasizq3.h"
//#include"hijomasizq2.h"
//#include"hijomasizquierdo.h"
#include"ArbolLista.h"
//
//#include "arreglopuntp.h"
/*HI arreglado
*Listar Iesimo nivel implementado*/
class Algoritmos{

private:
    void ListPostR(NodoPrincipal, Arbol&);
    void NumNivelesR(NodoPrincipal, int, Arbol&);
    void ListarIesimoR(Arbol&, int, NodoPrincipal);
public:
    void ListPost(Arbol&);
    int NumNiveles(Arbol&);
    void Copiar(Arbol&);
    void ListarIesimo(Arbol&, int);
    NodoPrincipal AveriguarHI(Arbol&, NodoPrincipal);
};

#endif // ALGORITMOS2_H
