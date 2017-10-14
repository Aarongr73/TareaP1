#include "algoritmos2.h"

#include<iostream>

using namespace std;


int Max = 0;
NodoPrincipal busc = 0;



void Algoritmos::ListPost(Arbol& arbol){
    if(!arbol.Vacio()){
        ListPostR(arbol.Raiz(),arbol);
    }
}

void Algoritmos::ListPostR(NodoPrincipal nodo, Arbol& arbol){
    NodoPrincipal nh = arbol.HMI(nodo);
    while(nh != NodoNulo){
        ListPostR(nh,arbol);
        nh = arbol.HD(nh);
    }
    cout<<"Etiqueta del nodo: "<<arbol.Etiqueta(nodo)<<endl;
}

int Algoritmos::NumNiveles(Arbol& arbol){
    if(arbol.NumElem() >= 1){
        NumNivelesR(arbol.Raiz(), 1,arbol);
    }
    cout<<Max<<endl;
    return Max;
}

void Algoritmos::NumNivelesR(NodoPrincipal n, int nivel, Arbol &arbol){
    if(arbol.EsHoja(n)){
        if(nivel > Max){
            Max = nivel;
        }
    }else{
        NodoPrincipal nh = arbol.HMI(n);
        while(nh != NodoNulo){
            NumNivelesR(nh, nivel+1,arbol);
            nh = arbol.HD(nh);
        }
    }
}

/*void Algoritmos::AveriguarHI(NodoPrincipal n,Arbol arbol){
    if(!arbol.Vacio()){
        busc = n;
        AveriguarHIR(arbol.Raiz(), 0,arbol);
    }
}

NodoPrincipal Algoritmos::AveriguarHIR(NodoPrincipal n, NodoPrincipal dedondevengo, Arbol &arbol){
    if(busc == NodoNulo){
        cout<<arbol.Etiqueta(dedondevengo)<<endl;
        return dedondevengo;
    }else{
        NodoPrincipal nh = arbol.HMI(n);
        if(busc == nh){
            return NodoNulo;
        }else{
            while(nh != NodoNulo){
                AveriguarHIR(arbol.HD(nh), nh,arbol);
                nh = arbol.HD(nh);
            }
        }
    }
}*/


void Algoritmos::Copiar(Arbol& arbol1){
    Arbol arbolCopia;
    double prueba;
    arbolCopia.Crear();
    if(arbol1.NumElem() != 0){
        Cola<NodoPrincipal> cola1;
        Cola<NodoPrincipal> cola2;
        NodoPrincipal nodo1;
        NodoPrincipal nodo2;
        NodoPrincipal nodoH1;
        NodoPrincipal nodoH2;
        cola1.Crear();
        cola2.Crear();
        arbolCopia.PonerRaiz(arbol1.Etiqueta(arbol1.Raiz()));
        cola1.Encolar(arbol1.Raiz());
        cola2.Encolar(arbolCopia.Raiz());
        while(!cola1.Vacia()){
            nodo1 = cola1.Desencolar();
            nodo2 = cola2.Desencolar();
            nodoH1 = arbol1.HMI(nodo1);
            while(nodoH1 != NodoNulo){
                arbolCopia.AgregarHijoI_esimo(nodo2, arbol1.Etiqueta(nodoH1), arbolCopia.NumHijos(nodo2)+1);
                nodoH2 = arbolCopia.HMD(nodo2);
                cola1.Encolar(nodoH1);
                cola2.Encolar(nodoH2);
                nodoH1 = arbol1.HD(nodoH1);
            }
        }
    }

    cout<<"Salio copiar"<<endl;
    ListPost(arbolCopia);
}


