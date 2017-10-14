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
bool Algoritmos::Busqueda(Arbol& arbol, int etiqueta){
    bool found = 0;
    if(!arbol.Vacio())
        found = BusquedaR(arbol.Raiz(), etiqueta, found,arbol);
    return found;

}

bool Algoritmos::BusquedaR(NodoPrincipal actual,int etiqueta, bool node,Arbol& arbol){
    if(arbol.Etiqueta(actual)==etiqueta){
         return true;
    }

    NodoPrincipal nh = arbol.HMI(actual);
    while(nh != NodoNulo ){
        node = BusquedaR(nh,etiqueta,node,arbol);
        if(node){
            return node;
        }
        nh = arbol.HD(nh);
    }
}
void  Algoritmos::ListadoHijos(Arbol arbol,NodoPrincipal nodo){
    NodoPrincipal n=arbol.HMI(nodo);
    while(n!=NodoNulo){
        cout<<arbol.Etiqueta(n)<<" ";
        n=arbol.HD(n);
    }
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
