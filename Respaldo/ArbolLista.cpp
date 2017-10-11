#include "ArbolLista.h"
#include <iostream>
using namespace std;

Arbol::Arbol(int capacidad,NodePrincipal* raiz)
:Elementos(capacidad)
,raiz(raiz)
{
}

Arbol::~Arbol(){
    this->Destruir();
}

void Arbol::Destruir(){
    NodePrincipal* ActualPrincipal=this->Raiz();

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
    this->raiz=new NodePrincipal(etiqueta);
    this->Elementos++;
}
NodePrincipal* Arbol::HMI(NodePrincipal* nodo){
    return nodo->PrimerHijo->listaPrincipal;
}
NodePrincipal* Arbol::AgregarHijoI_esimo(NodePrincipal* padre,double Etiqueta,int pos){
     NodePrincipal* nuevo=new NodePrincipal(Etiqueta);
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
NodePrincipal* Arbol::Raiz(){
    return this->raiz;
}
void Arbol::BorrarHoja(NodePrincipal* nodo){
    NodePrincipal* nodoActual=this->Raiz();
    NodePrincipal* nodoPrevio=nullptr;
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
NodePrincipal* Arbol::Buscar(double Etiqueta){
   NodePrincipal* nodoAux=this->Raiz();
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
bool Arbol::BorraListPrincipal(NodePrincipal* nodoActual,NodePrincipal* nodoPrevio,NodePrincipal* nodo){
    if(nodoActual==nodo){
       NodePrincipal* nodoAux=nodoActual;
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
int Arbol::NumHijos(NodePrincipal* padre){
    NodeHijos* nodoAux=padre->PrimerHijo;
    int count=0;
    while(nodoAux!=nullptr){
        ++count;
        nodoAux=nodoAux->next;
    }
    return count;
}
NodePrincipal* Arbol::HD(NodePrincipal* nodo){
    NodePrincipal* iterador=this->Raiz();
    bool encontrado=true;
   NodePrincipal* hermanoDerecho=nullptr;

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
NodePrincipal* Arbol::Padre(NodePrincipal* nodo){
    NodePrincipal* iterador=this->Raiz();
    NodePrincipal* padre;
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
bool Arbol::isRaiz(NodePrincipal *nodo){
    if(nodo==this->Raiz()){
        return true;
    }
    return false;
}
double Arbol::Etiqueta(NodePrincipal *nodo){
    return nodo->Etiqueta;
}
void Arbol::ModificarEtiqueta(NodePrincipal* nodo,double etiqueta){
    nodo->Etiqueta=etiqueta;
}
void Arbol::MostrarEtiqueta(NodePrincipal *nodo){
    cout<<nodo->Etiqueta;
}





