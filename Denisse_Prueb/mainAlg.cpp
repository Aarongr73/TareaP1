#include"Algoritmos.h"
//#include"hijomasizq3.h"
//#include"hijomasizq2.h"
#include<iostream>
#include"hijomasizquierdo.h"
//#include"ArbolLista.h"
using namespace std;

int main(){
    Arbol* arb = new Arbol();
    Algoritmos* alg = new Algoritmos();
    alg->Agrega();
    alg->ListPost();
    alg->NumNiveles();
    //alg->AveriguarHI(arb->Buscar(2));
return 0;
}

