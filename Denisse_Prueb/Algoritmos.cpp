/*Obvio agrega hay que quitarlo es porque usé otro main de prueba
*Hijo Izquierdo no sirve
*No sé si los includes pueden ir aquí, cualquier cosa me dicen
*couts de prueba*/
#include"Algoritmos.h"
#include<iostream>
//#include"hijomasizq3.h"
//#include"hijomasizq2.h"
#include"hijomasizquierdo.h"
//#include"ArbolLista.h"
using namespace std;

Arbol* arb = new Arbol();
int Max = 0;
NodoPrincipal busc = 0;

void Algoritmos::Agrega(){
    arb->PonerRaiz(8);
    arb->AgregarHijoI_esimo(arb->Buscar(8), 2, 0);
    arb->AgregarHijoI_esimo(arb->Buscar(8), 5, 1);
    arb->AgregarHijoI_esimo(arb->Buscar(8), 4, 2);
    arb->AgregarHijoI_esimo(arb->Buscar(2), 7, 0);
}

void Algoritmos::ListPost(){
    if(!arb->Vacio()){
        ListPostR(arb->Raiz());
    }
}

void Algoritmos::ListPostR(NodoPrincipal nodo){
    NodoPrincipal nh = arb->HMI(nodo);
    while(nh != 0){
        ListPostR(nh);
        nh = arb->HD(nh);
    }
    cout<<"Etiqueta del nodo: "<<arb->Etiqueta(nodo)<<endl;
}

int Algoritmos::NumNiveles(){
    if(arb->NumElem() >= 1){
        NumNivelesR(arb->Raiz(), 1);
    }
    cout<<Max<<endl;
    return Max;
}

void Algoritmos::NumNivelesR(NodoPrincipal n, int nivel){
    if(arb->EsHoja(n)){
        if(nivel > Max){
            Max = nivel;
        }
    }else{
        NodoPrincipal nh = arb->HMI(n);
        while(nh != 0){
            NumNivelesR(nh, nivel+1);
            nh = arb->HD(nh);
        }
    }
}

void Algoritmos::AveriguarHI(NodoPrincipal n){
    if(!arb->Vacio()){
        busc = n;
        AveriguarHIR(arb->Raiz(), 0);
    }
}

NodoPrincipal Algoritmos::AveriguarHIR(NodoPrincipal n, NodoPrincipal dedondevengo){
    if(busc == n){
        cout<<arb->Etiqueta(dedondevengo)<<endl;
        return dedondevengo;
    }else{
        NodoPrincipal nh = arb->HMI(n);
        if(busc == nh){
            return 0;
        }else{
            while(nh != 0){
                AveriguarHIR(arb->HD(nh), nh);
                nh = arb->HD(nh);
            }
        }
    }
}
