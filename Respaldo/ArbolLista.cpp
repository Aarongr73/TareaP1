#include "ArbolLista.h"
#include <iostream>

Arbol::Arbol(int capacidad,NodoPrincipal* raiz)
:Elementos(capacidad)
,raiz(raiz)
{
}

Arbol::~Arbol(){
    this->Destruir();
}

void Arbol::Destruir(){
    NodoPrincipal* ActualPrincipal=this->Raiz();

    while(ActualPrincipal!=nullptr){
        NodeHijos* HijoActual=ActualPrincipal->PrimerHijo;
        while(HijoActual!=nullptr){
            NodeHijos* nodoAux=HijoActual;
                HijoActual=HijoActual->next;
                delete nodoAux;
        }
        NodePrincipal* nodoAux=ActualPrincipal;
        ActualPrincipal=ActualPrincipal->siguiente;
        delete nodoAux;
    }
}
void Arbol::Vaciar(){
    this->Destruir();
    this->Crear();

}

void Arbol::Crear(){
    Arbol* arbol =new Arbol();
}
void Arbol::PonerRaiz(int etiqueta){
    this->raiz=new NodoPrincipal(etiqueta);
    this->Elementos++;
}
NodoPrincipal* Arbol::HMI(NodoPrincipal* nodo){
    return nodo->PrimerHijo->listaPrincipal;
}
NodoPrincipal* Arbol::AgregarHijoI_esimo(NodePrincipal* padre,double Etiqueta,int pos){
     NodoPrincipal* nuevo=new NodoPrincipal(Etiqueta);
     NodeHijos* nuevoHijo=new NodeHijos();

     if(this->Raiz()->siguiente==nullptr){
         this->Raiz()->siguiente=nuevo;
     }else{
        nuevo->siguiente=this->Raiz()->siguiente;
        this->Raiz()->siguiente=nuevo;
     }
     if(padre->PrimerHijo==nullptr ){
         padre->PrimerHijo=nuevoHijo;
         nuevoHijo->listaPrincipal=nuevo;
     }else{
         int cont=1;
         if(pos==1){
             nuevoHijo->next=padre->PrimerHijo;
             padre->PrimerHijo=nuevoHijo;

         }else if(pos==NumHijos(padre)+1){
             NodeHijos* Actual=padre->PrimerHijo;
             while(Actual->next!=nullptr){
                 Actual=Actual->next;
             }
             Actual->next=nuevoHijo;
         }else{
             int cont=1;
             NodeHijos* previo=nullptr;
             NodeHijos* Actual=padre->PrimerHijo;
             while(cont<=pos-1){
                 previo=Actual;
                 Actual=Actual->next;
                 ++cont;
             }
                 nuevoHijo->next=Actual;
                 previo->next=nuevoHijo;
         }
     }
     nuevoHijo->listaPrincipal=nuevo;
     this->Elementos++;
     return nuevo;
 }
NodoPrincipal* Arbol::Raiz(){
    return this->raiz;
}
void Arbol::BorrarHoja(NodoPrincipal* nodo){
    NodoPrincipal* nodoActual=this->Raiz();
    NodoPrincipal* nodoPrevio=nullptr;
    NodeHijos* Actual;
    NodeHijos* Previo;
    bool NoEliminadoLista=true;
    bool NoEliminadoSublista=true;

    while(nodoActual!=nullptr && (NoEliminadoLista || NoEliminadoSublista)){
        if(NoEliminadoLista){
             NoEliminadoLista=this->BorraListPrincipal(nodoActual,nodoPrevio,nodo);
             if(!NoEliminadoLista){
                 nodoActual=nodoPrevio->siguiente;
             }
        }
     if((NoEliminadoLista || NoEliminadoSublista)){
        Actual=nodoActual->PrimerHijo;
        Previo=nullptr;
        while (Actual!=nullptr && NoEliminadoSublista) {
            NodeHijos* nodoAux=Actual;
            if(nodo->Etiqueta==Actual->listaPrincipal->Etiqueta){
                if(nodo->Etiqueta==nodoActual->PrimerHijo->listaPrincipal->Etiqueta){
                    nodoActual->PrimerHijo=Actual->next;
                }else if(Actual->next==nullptr){
                    Previo->next=nullptr;
                }else{
                    Previo->next=Actual->next;
                    Actual->next=nullptr;
                }
                if(!NoEliminadoLista){
                    delete nodoAux->listaPrincipal;
                }
                nodoAux->listaPrincipal=nullptr;
                delete nodoAux;
                NoEliminadoSublista=false;
            }
            Previo=Actual;
            Actual=Actual->next;
        }
        if(nodoActual!=nullptr){
            nodoPrevio=nodoActual;
            nodoActual=nodoActual->siguiente;
        }
     }
    }
    this->Elementos--;
}
NodoPrincipal* Arbol::Buscar(double Etiqueta){
   NodoPrincipal* nodoAux=this->Raiz();
   bool salir=true;
   while(nodoAux!=nullptr && salir){
       if(nodoAux->Etiqueta==Etiqueta){
           return nodoAux;
       }
       else{
           if(nodoAux->siguiente==nullptr)
               return nullptr;
            nodoAux=nodoAux->siguiente;
       }

   }
}
bool Arbol::BorraListPrincipal(NodoPrincipal* nodoActual,NodoPrincipal* nodoPrevio,NodoPrincipal* nodo){
    if(nodoActual==nodo){
       NodoPrincipal* nodoAux=nodoActual;
        if(nodo==this->Raiz()->siguiente){
            this->Raiz()->siguiente=nodoActual->siguiente;
        }else if(nodoActual->siguiente==nullptr){
            nodoPrevio->siguiente=nullptr;
        }else{
            nodoPrevio->siguiente=nodoActual->siguiente;
            nodoActual->siguiente=nullptr;
        }
        return false;
    }
    return true;
}

int Arbol::NumElem(){
    return this->Elementos;
}
int Arbol::NumHijos(NodoPrincipal* padre){
    NodeHijos* nodoAux=padre->PrimerHijo;
    int count=0;
    while(nodoAux!=nullptr){
        ++count;
        nodoAux=nodoAux->next;
    }
    return count;
}
NodoPrincipal* Arbol::HD(NodoPrincipal* nodo){
    NodoPrincipal* iterador=this->Raiz();
    bool encontrado=true;
   NodoPrincipal* hermanoDerecho=nullptr;

    while(iterador!=nullptr && encontrado){
        NodeHijos* hijos=iterador->PrimerHijo;
        while(hijos!=nullptr && encontrado){
            if(nodo->Etiqueta==hijos->listaPrincipal->Etiqueta){
                hermanoDerecho=hijos->next->listaPrincipal;
                encontrado=false;
            }else{
                hijos=hijos->next;
            }
        }
        iterador=iterador->siguiente;
    }
    return hermanoDerecho;
}
NodoPrincipal* Arbol::Padre(NodoPrincipal* nodo){
    NodoPrincipal* iterador=this->Raiz();
    NodoPrincipal* padre;
    bool encontrado=true;

    while(iterador!=nullptr && encontrado){
        NodeHijos* hijos=iterador->PrimerHijo;
        while(hijos!=nullptr && encontrado){
            if(nodo->Etiqueta==hijos->listaPrincipal->Etiqueta){
                padre=iterador;
                encontrado=false;
            }else{
                hijos=hijos->next;
            }

        }
        iterador=iterador->siguiente;
    }
    return padre;

}
bool Arbol::Vacio(){
    if(this->Elementos==0){
        return true;
    }
    return false;
}
bool Arbol::isRaiz(NodoPrincipal* nodo){
    if(nodo==this->Raiz()){
        return true;
    }
    return false;
}
double Arbol::Etiqueta(NodoPrincipal* nodo){
    return nodo->Etiqueta;
}
void Arbol::ModificarEtiqueta(NodoPrincipal* nodo,double etiqueta){
    nodo->Etiqueta=etiqueta;
}





