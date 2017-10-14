#include "algoritmos2.h"

#include<iostream>

using namespace std;


int Max = 0;
int nivelG;


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

void Algoritmos::Copiar(Arbol& arbol1){
    Arbol arbolCopia;
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
    ListPost(arbolCopia);
}

void Algoritmos::ListarIesimo(Arbol& arbol, int nivel){
    nivelG = nivel;
    if(!arbol.Vacio()){
        ListarIesimoR(arbol, 1, arbol.Raiz());
    }
}

void Algoritmos::ListarIesimoR(Arbol& arbol, int actual, NodoPrincipal nodo){
    if(actual == nivelG){
        cout<<arbol.Etiqueta(nodo)<<endl;
    }else{
        NodoPrincipal nh = arbol.HMI(nodo);
        while(nh != NodoNulo){
            ListarIesimoR(arbol, actual+1, nh);
            nh = arbol.HD(nh);
        }
    }
}

NodoPrincipal Algoritmos::AveriguarHI(Arbol& arbol, NodoPrincipal hermano){
    if(!arbol.Vacio()){
        Cola<NodoPrincipal> cola;
        cola.Crear();
        cola.Encolar(arbol.Raiz());
        while(!cola.Vacia()){
            NodoPrincipal n = cola.Desencolar();
            if(arbol.HD(n) == hermano){
                return n;
            }else{
                NodoPrincipal nh = arbol.HMI(n);
                while(nh != NodoNulo){
                    cola.Encolar(nh);
                    nh = arbol.HD(nh);
                }
            }
        }
        cola.Destruir();
    }
}
