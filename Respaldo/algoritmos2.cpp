#include "algoritmos2.h"

#include<iostream>
#include "arreglopuntp.h"
//#include"hijomasizq3.h"
//#include"hijomasizq2.h"
//#include"hijomasizquierdo.h"
//#include"ArbolLista.h"
using namespace std;

Arbol arbol;
int Max = 0;
NodoPrincipal busc = 0;

void Algoritmos::Agrega(){
    arbol.Crear();
    arbol.PonerRaiz(1);
    arbol.AgregarHijoI_esimo(arbol.Buscar(1),2,0);

}

void Algoritmos::ListPost(){
    if(!arbol.Vacio()){
        ListPostR(arbol.Raiz());
    }
}

void Algoritmos::ListPostR(NodoPrincipal nodo){
    NodoPrincipal nh = arbol.HMI(nodo);
    while(nh != NodoNulo){
        ListPostR(nh);
        nh = arbol.HD(nh);
    }
    cout<<"Etiqueta del nodo: "<<arbol.Etiqueta(nodo)<<endl;
}

int Algoritmos::NumNiveles(){
    if(arbol.NumElem() >= 1){
        NumNivelesR(arbol.Raiz(), 1);
    }
    cout<<Max<<endl;
    return Max;
}

void Algoritmos::NumNivelesR(NodoPrincipal n, int nivel){
    if(arbol.EsHoja(n)){
        if(nivel > Max){
            Max = nivel;
        }
    }else{
        NodoPrincipal nh = arbol.HMI(n);
        while(nh != NodoNulo){
            NumNivelesR(nh, nivel+1);
            nh = arbol.HD(nh);
        }
    }
}

void Algoritmos::AveriguarHI(NodoPrincipal n){
    if(!arbol.Vacio()){
        busc = n;
        AveriguarHIR(arbol.Raiz(), 0);
    }
}

NodoPrincipal Algoritmos::AveriguarHIR(NodoPrincipal n, NodoPrincipal dedondevengo){
    if(busc == NodoNulo){
        cout<<arbol.Etiqueta(dedondevengo)<<endl;
        return dedondevengo;
    }else{
        NodoPrincipal nh = arbol.HMI(n);
        if(busc == nh){
            return NodoNulo;
        }else{
            while(nh != NodoNulo){
                AveriguarHIR(arbol.HD(nh), nh);
                nh = arbol.HD(nh);
            }
        }
    }
}
