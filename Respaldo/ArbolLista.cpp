#include "ArbolLista.h"
#include <iostream>
using namespace std;

NodoPrincipal NodoNulo=0;

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

    while(ActualPrincipal!=0){
        NodeHijos* HijoActual=ActualPrincipal->PrimerHijo;
        while(HijoActual!=0){
            NodeHijos* nodoAux=HijoActual;
                HijoActual=HijoActual->next;

        }
        NodePrincipal* nodoAux=ActualPrincipal;
        ActualPrincipal=ActualPrincipal->siguiente;

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
    if(nodo->PrimerHijo == 0){
        return NodoNulo;
    }else{
        return nodo->PrimerHijo->listaPrincipal;
    }
}
NodePrincipal* Arbol::AgregarHijoI_esimo(NodePrincipal* padre,double Etiqueta,int pos){
     NodePrincipal* nuevo=new NodePrincipal(Etiqueta);
     NodeHijos* nuevoHijo=new NodeHijos();

     if(this->Raiz()->siguiente==0){
         this->Raiz()->siguiente=nuevo;
     }else{
        nuevo->siguiente=this->Raiz()->siguiente;
        this->Raiz()->siguiente=nuevo;
     }
     if(padre->PrimerHijo==0 ){
         padre->PrimerHijo=nuevoHijo;
         nuevoHijo->listaPrincipal=nuevo;
     }else{
         int cont=1;
         if(pos==1){
             nuevoHijo->next=padre->PrimerHijo;
             padre->PrimerHijo=nuevoHijo;

         }else if(pos==NumHijos(padre)+1){
             NodeHijos* Actual=padre->PrimerHijo;
             while(Actual->next!=0){
                 Actual=Actual->next;
             }
             Actual->next=nuevoHijo;
         }else{
             int cont=1;
             NodeHijos* previo=0;
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
    NodePrincipal* nodoPrevio=0;
    NodeHijos* Actual;
    NodeHijos* Previo;
    bool NoEliminadoLista=true;
    bool NoEliminadoSublista=true;

    while(nodoActual!=0 && (NoEliminadoLista || NoEliminadoSublista)){
        if(NoEliminadoLista){
             NoEliminadoLista=this->BorraListPrincipal(nodoActual,nodoPrevio,nodo);
             if(!NoEliminadoLista){
                 nodoActual=nodoPrevio->siguiente;
             }
        }
     if((NoEliminadoLista || NoEliminadoSublista)){
        Actual=nodoActual->PrimerHijo;
        Previo=0;
        while (Actual!=0 && NoEliminadoSublista) {
            NodeHijos* nodoAux=Actual;
            if(nodo->Etiqueta==Actual->listaPrincipal->Etiqueta){
                if(nodo->Etiqueta==nodoActual->PrimerHijo->listaPrincipal->Etiqueta){
                    nodoActual->PrimerHijo=Actual->next;
                }else if(Actual->next==0){
                    Previo->next=0;
                }else{
                    Previo->next=Actual->next;
                    Actual->next=0;
                }

                nodoAux->listaPrincipal=0;
                NoEliminadoSublista=false;
            }
            Previo=Actual;
            Actual=Actual->next;
        }
        if(nodoActual!=0){
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
   while(nodoAux!=0 && salir){
       if(nodoAux->Etiqueta==Etiqueta){
           return nodoAux;
       }
       else{
           if(nodoAux->siguiente==0)
               return 0;
            nodoAux=nodoAux->siguiente;
       }

   }
}
bool Arbol::BorraListPrincipal(NodePrincipal* nodoActual,NodePrincipal* nodoPrevio,NodePrincipal* nodo){
    if(nodoActual==nodo){
       NodePrincipal* nodoAux=nodoActual;
        if(nodo==this->Raiz()->siguiente){
            this->Raiz()->siguiente=nodoActual->siguiente;
        }else if(nodoActual->siguiente==0){
            nodoPrevio->siguiente=0;
        }else{
            nodoPrevio->siguiente=nodoActual->siguiente;
            nodoActual->siguiente=0;
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
    while(nodoAux!=0){
        ++count;
        nodoAux=nodoAux->next;
    }
    return count;
}
NodePrincipal* Arbol::HD(NodePrincipal* nodo){
    NodePrincipal* iterador=this->Raiz();
    bool encontrado=true;
    bool sublista=true;
    NodePrincipal* hermanoDerecho = 0;

    while(iterador!=0 && encontrado){
        sublista=true;
        NodeHijos* hijos=iterador->PrimerHijo;
        while(hijos!=0 && sublista){
            if(hijos->next != 0){
                if(nodo->Etiqueta == hijos->listaPrincipal->Etiqueta){
                    hermanoDerecho=hijos->next->listaPrincipal;
                    encontrado=false;
                    sublista=false;
                }else{
                    hijos=hijos->next;
                }
            }else{
                iterador=iterador->siguiente;
                sublista=false;
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

    while(iterador!=0 && encontrado){
        NodeHijos* hijos=iterador->PrimerHijo;
        while(hijos!=0 && encontrado){
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
    if(nodo != NodoNulo){
        return nodo->Etiqueta;
    }
}
void Arbol::ModificarEtiqueta(NodePrincipal* nodo,double etiqueta){
    nodo->Etiqueta=etiqueta;
}
void Arbol::MostrarEtiqueta(NodePrincipal *nodo){
    cout<<nodo->Etiqueta;
}

bool Arbol::EsHoja(NodePrincipal* nodo){
    if(HMI(nodo) == 0){
        return true;
    }else{
        return false;
    }
}

NodePrincipal* Arbol::HMD(NodePrincipal* padre){
    NodoPrincipal nh = HMI(padre);
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






