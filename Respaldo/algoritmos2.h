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
    void ListarIesimoR(Arbol&, int, NodoPrincipal);
public:

    void ListPost(Arbol& arbol);
    int NumNiveles(Arbol& arbol);
    void ListarIesimo(Arbol&, int);
//    void Agrega();
    void ListPre(Arbol& arbol);
    bool Repetidos(Arbol &arbol);
    bool BusquedaR(NodoPrincipal actual, int etiqueta, bool node, Arbol &arbol);
    bool Busqueda(Arbol&,int etiqueta);
    void ListadoHijos(Arbol arbol,NodoPrincipal nodo);
    NodoPrincipal AveriguarHI(Arbol&, NodoPrincipal);
    Arbol Copiar(Arbol&, Arbol &arbolCopia);
    void ListadoPN(Arbol&);
    bool Iguales(Arbol&, Arbol&);
    int NumnNiveles(Arbol&);
    void BorrarSubArbol(NodoPrincipal, Arbol&);
    int Profundidad(NodoPrincipal, Arbol&);
};

#endif // ALGORITMOS2_H
