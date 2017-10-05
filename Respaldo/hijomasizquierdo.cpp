#include "hijomasizquierdo.h"

Arbol::Arbol(Node *raiz, int elementos)
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
    while(nh!=nullptr){
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
    return nodo->Hmi;
}
Node *Arbol::HD(Node* nodo){
    return nodo->HD;
}

void Arbol::PonerRaiz(int etiqueta){
    this->raiz=new NodoPrincipal();
    raiz->Etiqueta=etiqueta;
    this->Elementos++;
}
Node *Arbol::AgregarHijoI_esimo(Node *padre, int etiqueta, int pos){
    NodoPrincipal* nuevoHijo=new NodoPrincipal();
    nuevoHijo->Etiqueta=etiqueta;
    if(padre->Hmi==nullptr){
        padre->Hmi=nuevoHijo;
    }else{
        if(pos==1){
            nuevoHijo->HD=padre->Hmi;
            padre->Hmi=nuevoHijo;
        }else if(pos==NumHijos(padre)+1){
            NodoPrincipal* Actual=padre->Hmi;
            while(Actual->HD!=nullptr){
                Actual=Actual->HD;
            }
            Actual->HD=nuevoHijo;
        }else{
            int cont=1;
            NodoPrincipal* previo=nullptr;
            NodoPrincipal* Actual=padre->Hmi;
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
Node* Arbol::Buscar(int etiqueta){
    Node* nodo=nullptr;
    if(!this->Vacio())
        nodo=PreOrdenBusqueda(this->raiz,etiqueta,nodo);
    return nodo;

}
Node* Arbol::PreOrdenBusqueda(Node* Actual, int etiqueta, Node *nodo){
    if(Actual->Etiqueta==etiqueta){
         return Actual;
    }

    Node* nh=HMI(Actual);
    while(nh!=nullptr){
        nodo=PreOrdenBusqueda(nh,etiqueta,nodo);
        if(nodo!=nullptr)
            return nodo;
        nh=HD(nh);
    }
}
Node* Arbol::Padre(Node *nodo){
    NodoPrincipal* padre=nullptr;
    if(!this->Vacio())
        padre=PreOrdenPadre(this->raiz,nodo);
    return padre;
}
NodoPrincipal* Arbol::PreOrdenPadre(NodoPrincipal* Actual,Node* buscado){

    Node* nh=Actual->Hmi;
    while(nh!=nullptr ){
        Node* padre=PreOrdenPadre(nh,buscado);
        if(nh==buscado){
             return Actual;
        }
        if(padre!=nullptr){
            return padre;
        }
        nh=nh->HD;
    }
}
void Arbol::BorrarHoja(Node *nodo){
    NodoPrincipal* padre=Padre(nodo);
    if(isRaiz(nodo)){
        NodoPrincipal* nodoAux;
        this->raiz=nullptr;
        delete nodoAux;
    }else{
    if(padre->Hmi==nodo){
        NodoPrincipal* nodoAux=padre->Hmi;
        padre->Hmi=nodoAux->HD;
        nodoAux->HD=nullptr;
        delete nodoAux;
    }else{
        bool NoEliminado=true;
        NodoPrincipal* Actual=padre->Hmi->HD;
        NodoPrincipal* Previo=padre->Hmi;
        while (Actual!=nullptr && NoEliminado) {
            if(Actual==nodo){
                NodoPrincipal* nodoAux;
                nodoAux=Actual;
                if(Actual->HD!=nullptr){
                    Previo->HD=Actual->HD;
                }else{
                    Previo->HD=nullptr;
                }
                delete nodoAux;
                NoEliminado=false;
            }
            Previo=Actual;
            Actual=Actual->HD;
        }
      }
    }
    this->Elementos--;
}
bool Arbol::isRaiz(NodoPrincipal* nodo){
    if(nodo==this->raiz){
        return true;
    }
    return false;
}
int Arbol::Etiqueta(Node *nodo){
    return nodo->Etiqueta;
}
int Arbol::NumHijos(Node* nodo){
    int count=0;
    if(nodo->Hmi==nullptr){
        return 0;
    }else{
        Node* nodoAux=nodo->Hmi;
        while(nodoAux!=nullptr){
            ++count;
            nodoAux=nodoAux->HD;
        }
    }
    return count;
}
int Arbol::NumElem(){
   return this->Elementos;
}
void Arbol::ModificarEtiqueta(Node* nodo,int etiqueta){
    nodo->Etiqueta=etiqueta;
}
NodoPrincipal* Arbol::Raiz(){
    return raiz;
}


