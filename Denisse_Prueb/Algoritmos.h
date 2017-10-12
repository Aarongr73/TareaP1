#ifndef ALG_17
#define ALG_17
//#include"hijomasizq3.h"
//#include"hijomasizq2.h"
#include"hijomasizquierdo.h"
//#include"ArbolLista.h"
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
#endif // ALG_17

