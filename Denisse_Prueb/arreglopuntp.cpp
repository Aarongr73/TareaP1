#include "arreglopuntp.h"

Arbol::Arbol(){
    PonerRaiz(' ');
    Arreglo[0].nodoPadre = 0;
    numNodos = 1;
}

Arbol::~Arbol(){
    //Como es estático no se necesita destructor.
}

void Arbol::Crear(){
    Arbol();
}

void Arbol::Vaciar(){
    Arreglo[NumElem()].nodoPadre = 0;
    numNodos = 0;
}

bool Arbol::Vacio(){
    if (Arreglo[NumElem()].nodoPadre == 0) {
        return 1;
    }
    return 0;
}

Nodo Arbol::Raiz(){
    Arreglo[0].nodoPadre=10000000000;
    return Arreglo[0];
}

Nodo Arbol::HMI(Nodo n){
    int pos = BuscarIndice(n.Etiqueta);
    int i = pos+1;
    while(Arreglo[i].nodoPadre!=pos){
        ++i;
    }
    return Arreglo[i];
}

Nodo Arbol::HD(Nodo n){
    int pos = BuscarIndice(n.Etiqueta);
    int i=pos+1;
    while(Arreglo[i].nodoPadre!=n.nodoPadre){
        i++;
    }
    return Arreglo[i];
}

Nodo Arbol::Padre(Nodo n){
    return Arreglo[n.nodoPadre];
}

bool Arbol::EsHoja(Nodo n){
    int pos = BuscarIndice(n.Etiqueta);
    int i = pos;
    while(Arreglo[i].nodoPadre != pos && pos <= NumElem()) {
        ++i;
    }
    if (i == NumElem() && Arreglo[NumElem()].nodoPadre != pos) {
        return true;
    }else{
        return false;
    }
}

char Arbol::Etiqueta(Nodo n) {
    return n.Etiqueta;
}

int Arbol::NumElem() {
    return numNodos;
}

int Arbol::NumHijos(Nodo n){
    int numh = 0;
    int pos2=BuscarIndice(n.Etiqueta);
    int i=pos2+1;
    int hijos=0;
    while(Arreglo[i].nodoPadre==pos2){
        ++i;
        ++hijos;

    }
    return hijos;
}

void Arbol::ModificarEtiqueta(Nodo n, char e){
    n.Etiqueta = e;
}

Nodo Arbol::AgregarHijoI_esimo(Nodo n, char e, int p){
    int pos = BuscarIndice(n.Etiqueta);
    int i = pos;
    int numhij=NumHijos(n);
    int contador = 0;
    int j = NumElem();

    Nodo nuevo;
    nuevo.nodoPadre = pos;
    nuevo.Etiqueta = e;
    if(NumHijos(n)==0 || p==numhij+1){
        Arreglo[j]=nuevo;
    }else{
        int hijo=BuscarIndice(HMI(n).Etiqueta);
        int mismoPadre=1;
        while(mismoPadre<p){
            if(Arreglo[hijo].nodoPadre==pos){
                   ++mismoPadre;
            }
            ++hijo;
        }
        int cont=20;
        while(cont>hijo){
            Arreglo[cont]=Arreglo[ cont-1];
            --cont;
        }
        Arreglo[hijo]=nuevo;

    }

++numNodos;
return nuevo;

}

void Arbol::BorrarHoja(Nodo n){
    int pos = BuscarIndice(n.Etiqueta);
    int i = pos;
    while (i <= NumElem()) {
        Arreglo[i] = Arreglo[i+1];
        ++i;
    }
     --numNodos;
}

void Arbol::PonerRaiz(char e){
    Arreglo[0].Etiqueta = e;
}

int Arbol::BuscarIndice(char e) {
    int i = 0;
    while (Arreglo[i].Etiqueta != e) {
        ++i;
    }
    return i;
}
Nodo Arbol::Buscar(char e){
    int i = BuscarIndice(e);
    return Arreglo[i];
}

void Arbol::Destruir(){

}
void Arbol::MostrarEtiqueta(Nodo nodo){
    cout<<nodo.Etiqueta;
}
