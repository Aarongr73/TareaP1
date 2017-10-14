#include"hijomasizq3.h"
#include<iostream>
using namespace std;
NodoPrincipal NodoNulo=0;

Arbol::Arbol(){
    numNodos = 0;
    raiz = 0;
}

Arbol::~Arbol(){
    Destruir();
}

void Arbol::Vaciar(){
    Destruir();
    Crear();
}

void Arbol::Destruir(){
    if(!Vacio()){
        DestruirR(Raiz());
    }
}

void Arbol::DestruirR(nodo* borrando){
    nodo* nh;
    nh = HMI(borrando);
    while(nh != 0){
        DestruirR(nh);
        nh = HD(nh);
    }
}

void Arbol::Crear(){
    Arbol* arbol = new Arbol();
}

int Arbol::NumElem(){
    return numNodos;
}

void Arbol::BorrarHoja(nodo* hoja){
    nodo* padre;
    if(EsHoja(hoja)){
        padre = Padre(hoja);
        if(hoja == HMI(padre)){
            if(HD(hoja) == 0){
                padre->HMI = 0;
            }else{
                padre->HMI = HD(hoja);
            }
        }else{
            if(HD(hoja) == 0){
                hoja->HI->HD = 0;
            }else{
                nodo* hermano;
                hermano = HD(hoja);
                hermano->HI = hoja->HI;
                hermano->HI->HD = hermano;
            }
        }
    }
}

int Arbol::NumHijos(nodo* padre){
    int hijos = 0;
    nodo* hmi = new nodo();
    hmi = HMI(padre);
    if(hmi != 0){
        ++hijos;
        while(HD(hmi) != 0){
            ++hijos;
            hmi = HD(hmi);
        }
    }
    return hijos;
}

void Arbol::PonerRaiz(int etiqueta){
    raiz = new nodo();
    ++numNodos;
    raiz->Etiqueta = etiqueta;
}

nodo* Arbol::Raiz(){
    return raiz;
}



int Arbol::Etiqueta(nodo* Nodo){
        return Nodo->Etiqueta;
}

void Arbol::ModificarEtiqueta(nodo* Nodo, int etiquetaN){
    Nodo->Etiqueta = etiquetaN;
}

nodo* Arbol::HMI(nodo* padre){
    if(padre->HMI == 0){
        return 0;
    }else{
        return padre->HMI;
    }
}

nodo* Arbol::HD(nodo* hermanoI){
    if(hermanoI->HD == 0){
        return 0;
    }else{
        return hermanoI->HD;
    }
}

nodo* Arbol::Padre(nodo* hijo){
    if(hijo == raiz){
        return 0;
    }else{
        return hijo->padre;
    }
}

nodo *Arbol::AgregarHijoI_esimo(nodo *padre, int etiqueta, int pos){

    nodo* nuevoHijo=new nodo();
    nuevoHijo->padre = padre;
    nuevoHijo->Etiqueta=etiqueta;
    if(padre->HMI==NodoNulo){
        padre->HMI=nuevoHijo;
    }else{
        if(pos==1){
            nuevoHijo->HD=padre->HMI;
            padre->HMI=nuevoHijo;
            nuevoHijo->HI = NodoNulo;
        }else if(pos==NumHijos(padre)+1){
            nodo* Actual=padre->HMI;
            while(Actual->HD!=NodoNulo){
                Actual=Actual->HD;
            }
            Actual->HD=nuevoHijo;
            nuevoHijo->HI = Actual;
        }else{
            int cont=1;
            nodo* previo=NodoNulo;
            nodo* Actual=padre->HMI;
            while(cont<=pos-1){
                previo=Actual;
                Actual=Actual->HD;
                ++cont;
            }
                nuevoHijo->HD=Actual;
                previo->HD=nuevoHijo;
                nuevoHijo->HI = previo;
        }

    }
    this->numNodos++;
}

bool Arbol::Vacio(){
    if(raiz == 0){
        return true;
    }else{
        return false;
    }
}

bool Arbol::EsHoja(nodo* node){
    if(HMI(node) == 0){
        return true;
    }else{
        return false;
    }
}

bool Arbol::esRaiz(nodo* node){
    if(Etiqueta(node) == Etiqueta(Raiz())){
        return true;
    }else{
        return false;
    }
}

nodo* Arbol::Buscar(int etiqueta){
    nodo* node = 0;
    if(!Vacio())
        node = PreOrdenBusqueda(Raiz(), etiqueta, node);
    return node;

}

nodo* Arbol::PreOrdenBusqueda(nodo* actual,int etiqueta, nodo* node){
    if(Etiqueta(actual)==etiqueta){
         return actual;
    }

    nodo* nh = HMI(actual);
    while(nh != 0 ){
        node = PreOrdenBusqueda(nh,etiqueta,node);
        if(node!= 0){
            return node;
        }
        nh = HD(nh);
    }
}
void Arbol::MostrarEtiqueta(nodo* nodo){
    cout<<nodo->Etiqueta;
}

nodo* Arbol::HMD(nodo* padre){
    NodoPrincipal nh = padre->HMI;
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
