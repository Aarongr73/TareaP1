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
void Algoritmos::ListPre(Arbol& arbol){
    if(!arbol.Vacio()){
        ListPreR(arbol.Raiz(),arbol);
    }
}
void Algoritmos::ListPreR(NodoPrincipal nodo, Arbol& arbol){
    cout<<"Etiqueta del nodo: "<<arbol.Etiqueta(nodo)<<endl;
    NodoPrincipal nh = arbol.HMI(nodo);
    while(nh != NodoNulo){
        ListPostR(nh,arbol);
        nh = arbol.HD(nh);
    }
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

void Algoritmos::AveriguarHI(NodoPrincipal n,Arbol arbol){
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
}
bool Algoritmos::Repetidos( Arbol &arbol){
    ListaCola<NodoPrincipal>lista;
    NodoPrincipal n;
    NodoPrincipal nh;
    NodoPrincipal nh2;
    int pos=0;
    int recorrido=0;
    int cant=arbol.NumElem();
    lista.Agregar(arbol.Raiz());
    while(pos<cant){
        n=lista.Recuperar(pos);
        nh=arbol.HMI(n);
        while (nh!=NodoNulo) {
            for(int i=0;i<lista.NumElem();i++){
                if(arbol.Etiqueta(nh)==arbol.Etiqueta(lista.Recuperar(i)))
                    return true;
            }
            lista.Agregar(nh);
            nh=arbol.HD(nh);
        }
        ++pos;
    }
    return false;

}
