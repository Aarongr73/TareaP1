/*Agregado metodo EsHoja
*Arreglado HMI
*Arreglado HD*/

#include "hijomasizquierdo.h"
#include <iostream>
using namespace std;
NodoPrincipal NodoNulo=0;

Arbol::Arbol(Node* raiz, long elementos)
    :raiz(raiz)
    ,Elementos(elementos)
{
}
Arbol::~Arbol(){
    Destruir();

}
void Arbol::Vaciar(){
    Destruir();
    Crear();
}

void Arbol::Destruir(){
    DestruirR(raiz);
}
void Arbol::DestruirR(Node *nodo){
    Node* nh=HMI(nodo);
    while(nh!=0){
        DestruirR(nh);
        nh=HMI(nodo);
    }
    BorrarHoja(nodo);
}

void Arbol::Crear(){
    Arbol* arbol=new Arbol();
}
bool Arbol::Vacio(){
   if(this->Elementos==0){
       return true;
   }
   return false;
}
Node *Arbol::HMI(Node* nodo){
    if(nodo->Hmi == 0){
        return 0;
    }else{
        return nodo->Hmi;
    }

}
Node *Arbol::HD(Node* nodo){
    if(nodo->HD == 0){
       return 0;
    }else{
        return nodo->HD;
    }
}

void Arbol::PonerRaiz(long etiqueta){
    this->raiz=new Node();
    raiz->Etiqueta=etiqueta;
    this->Elementos++;
}
Node *Arbol::AgregarHijoI_esimo(Node *padre, long etiqueta, long pos){
    Node* nuevoHijo=new Node();
    nuevoHijo->Etiqueta=etiqueta;
    if(padre->Hmi==0){
        padre->Hmi=nuevoHijo;
    }else{
        if(pos==1){
            nuevoHijo->HD=padre->Hmi;
            padre->Hmi=nuevoHijo;
        }else if(pos==NumHijos(padre)+1){
            Node* Actual=padre->Hmi;
            while(Actual->HD!=0){
                Actual=Actual->HD;
            }
            Actual->HD=nuevoHijo;
        }else{
            long cont=1;
            Node* previo=0;
            Node* Actual=padre->Hmi;
            while(cont<=pos-1){
                previo=Actual;
                Actual=Actual->HD;
                ++cont;
            }
                nuevoHijo->HD=Actual;
                previo->HD=nuevoHijo;
        }

    }
    this->Elementos++;
}
Node* Arbol::Buscar(long etiqueta){
    Node* nodo=0;
    if(!this->Vacio())
        nodo=PreOrdenBusqueda(this->raiz,etiqueta,nodo);
    return nodo;

}
Node* Arbol::PreOrdenBusqueda(Node* Actual, long etiqueta, Node *nodo){
    if(Actual->Etiqueta==etiqueta){
         return Actual;
    }

    Node* nh=HMI(Actual);
    while(nh!=0){
        nodo=PreOrdenBusqueda(nh,etiqueta,nodo);
        if(nodo!=0)
            return nodo;
        nh=HD(nh);
    }
}
Node* Arbol::Padre(Node *nodo){
    Node* padre=0;
    if(!this->Vacio())
        padre=PreOrdenPadre(this->raiz,nodo);
    return padre;
}
Node* Arbol::PreOrdenPadre(Node* Actual,Node* buscado){

    Node* nh=Actual->Hmi;
    while(nh!=0 ){
        Node* padre=PreOrdenPadre(nh,buscado);
        if(nh==buscado){
             return Actual;
        }
        if(padre!=0){
            return padre;
        }
        nh=nh->HD;
    }
}
void Arbol::BorrarHoja(Node *nodo){
    Node* padre=Padre(nodo);
    if(isRaiz(nodo)){
        Node* nodoAux;
        this->raiz=0;
        //delete nodoAux;
    }else{
    if(padre->Hmi==nodo){
        Node* nodoAux=padre->Hmi;
        padre->Hmi=nodoAux->HD;
        nodoAux->HD=0;
        //delete nodoAux;
    }else{
        bool NoEliminado=true;
        Node* Actual=padre->Hmi->HD;
        Node* Previo=padre->Hmi;
        while (Actual!=0 && NoEliminado) {
            if(Actual==nodo){
                Node* nodoAux;
                nodoAux=Actual;
                if(Actual->HD!=0){
                    Previo->HD=Actual->HD;
                }else{
                    Previo->HD=0;
                }
                //delete nodoAux;
                NoEliminado=false;
            }
            Previo=Actual;
            Actual=Actual->HD;
        }
      }
    }
    this->Elementos--;
}
bool Arbol::isRaiz(Node* nodo){
    if(nodo==this->raiz){
        return true;
    }
    return false;
}
long Arbol::Etiqueta(Node *nodo){
    if(nodo==NodoNulo)
        return 0;
    return nodo->Etiqueta;
}
long Arbol::NumHijos(Node* nodo){
    long count=0;
    if(nodo->Hmi==0){
        return 0;
    }else{
        Node* nodoAux=nodo->Hmi;
        while(nodoAux!=0){
            ++count;
            nodoAux=nodoAux->HD;
        }
    }
    return count;
}
long Arbol::NumElem(){
   return this->Elementos;
}
void Arbol::ModificarEtiqueta(Node* nodo, long etiqueta){
    nodo->Etiqueta=etiqueta;
}
Node *Arbol::Raiz(){
    return raiz;
}
void Arbol::MostrarEtiqueta(Node* nodo){
    cout<<nodo->Etiqueta;
}

bool Arbol::EsHoja(Node* nodo){
    if(HMI(nodo) == 0){
        return true;
    }else{
        return false;
    }
}

Node* Arbol::HMD(Node* padre){
    NodoPrincipal nh = padre->Hmi;
    if(nh != NodoNulo){
        while(HD(nh) != NodoNulo){
            nh = HD(nh);
        }
        if(HD(nh) == NodoNulo){
            return nh;
        }
    }else{
        return NodoNulo;
    }
}
