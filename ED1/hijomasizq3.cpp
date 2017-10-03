#include"hijomasizq3.h"
#include<iostream>
using namespace std;

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
    nh = HijoMasIzquierdo(borrando);
    delete borrando;
    while(nh != 0){
        DestruirR(nh);
        nh = HermanoDerecho(nh);
    }
}

void Arbol::Crear(){
    Arbol* arbol = new Arbol();
}

int Arbol::NumNodos(){
    return numNodos;
}

void Arbol::BorrarHoja(nodo* hoja){
    nodo* padre;
    if(EsHoja(hoja)){
        padre = Padre(hoja);
        if(hoja == HijoMasIzquierdo(padre)){
            if(HermanoDerecho(hoja) == 0){
                padre->HMI = 0;
            }else{
                padre->HMI = HermanoDerecho(hoja);
            }
        }else{
            if(HermanoDerecho(hoja) == 0){
                hoja->HI->HD = 0;
            }else{
                nodo* hermano;
                hermano = HermanoDerecho(hoja);
                hermano->HI = hoja->HI;
                hermano->HI->HD = hermano;
            }
        }
    }
}

int Arbol::NumHijos(nodo* padre){
    int hijos = 0;
    nodo* hmi = new nodo();
    hmi = HijoMasIzquierdo(padre);
    if(hmi != 0){
        ++hijos;
        while(HermanoDerecho(hmi) != 0){
            ++hijos;
            hmi = HermanoDerecho(hmi);
        }
    }
    return hijos;
}

void Arbol::PonerRaiz(int etiqueta){
    raiz = new nodo();
    ++numNodos;
    raiz->etiqueta = etiqueta;
}

nodo* Arbol::Raiz(){
    return raiz;
}

nodo* Arbol::AgregarHijoI_esimo(nodo* padre, int etiqueta){
    nodo* nuevoHijo = new nodo();
    nuevoHijo->etiqueta = etiqueta;
    nuevoHijo->padre = padre;
    ++numNodos;
    if(padre->HMI==0){
        padre->HMI = nuevoHijo;
    }else{
        if(nuevoHijo->etiqueta < padre->HMI->etiqueta){
            nuevoHijo->HD = padre->HMI;
            padre->HMI = nuevoHijo;
            nuevoHijo->HD->HI = nuevoHijo;
        }else{
            nodo* nodoAux = padre->HMI;
            bool Noinsertado = true;
            while(nodoAux != 0 && Noinsertado){
                if(nodoAux->HD != 0){
                    if(nuevoHijo->etiqueta > nodoAux->etiqueta && nuevoHijo->etiqueta < nodoAux->HD->etiqueta){
                        nuevoHijo->HD = nodoAux->HD;
                        nodoAux->HD = nuevoHijo;
                        nuevoHijo->HI = nodoAux;
                        Noinsertado=false;
                    }
                }else{
                        nodoAux->HD = nuevoHijo;
                        nuevoHijo->HI = nodoAux;
                        Noinsertado = false;
                }
                nodoAux = nodoAux->HD;
            }
        }
    }
    return nuevoHijo;
}

int Arbol::Etiqueta(nodo* Nodo){
        return Nodo->etiqueta;
}

void Arbol::ModificarEtiqueta(nodo* Nodo, int etiquetaN){
    Nodo->etiqueta = etiquetaN;
}

nodo* Arbol::HijoMasIzquierdo(nodo* padre){
    if(padre->HMI == 0){
        return 0;
    }else{
        return padre->HMI;
    }
}

nodo* Arbol::HermanoDerecho(nodo* hermanoI){
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

bool Arbol::Vacio(){
    if(raiz == 0){
        return true;
    }else{
        return false;
    }
}

/*void Arbol::MostrarArbolR(nodo* node){
    nodo* nh = new nodo();
    cout<<"Nodos: "<<node->etiqueta<<endl;
    nh = node->HMI;
    while(nh != 0){
        MostrarArbolR(nh);
        nh = HermanoDerecho(nh);
    }
}

void Arbol::MostrarArbol(){
    if(!Vacio()){
        MostrarArbolR(Raiz());
    }
}*/

bool Arbol::EsHoja(nodo* node){
    if(HijoMasIzquierdo(node) == 0){
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

    nodo* nh = HijoMasIzquierdo(actual);
    while(nh != 0 ){
        node = PreOrdenBusqueda(nh,etiqueta,node);
        if(node!= 0){
            return node;
        }
        nh = HermanoDerecho(nh);
    }
}

