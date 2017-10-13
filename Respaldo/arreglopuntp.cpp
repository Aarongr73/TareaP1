#include "arreglopuntp.h"

int NodoNulo=-1;
Arbol::Arbol(){
    PonerRaiz(' ');
    Arreglo[0].nodoPadre = 0;
    numNodos = 1;
}



void Arbol::Crear(){
    Arbol arbol=Arbol();
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

int Arbol::Raiz(){
    return 0;
}

int Arbol::HMI(int nodo){
    int pos = nodo;
    int i = pos+1;
    while(Arreglo[i].nodoPadre!=pos){
        ++i;
        if(i>NumElem()){
            return NodoNulo;
        }
    }
    return i;
}

int Arbol::HD(int nodo){
    int pos = nodo;
    int i=pos+1;
    while(Arreglo[i].nodoPadre!=Arreglo[nodo].nodoPadre){
        i++;
        if(i>NumElem()){
            return NodoNulo;
        }
    }
    return i;
}

int Arbol::Padre(int nodo){
    return Arreglo[nodo].nodoPadre;
}

bool Arbol::EsHoja(int nodo){
    int pos = nodo;
    int i = pos;
    while(Arreglo[i].nodoPadre != pos && pos <= NumElem()) {
        ++i;
        if(i>NumElem())
            return true;
    }
    if (i == NumElem() && Arreglo[NumElem()].nodoPadre != pos) {
        return true;
    }else{
        return false;
    }
}

char Arbol::Etiqueta(int nodo) {
    return Arreglo[nodo].etiqueta;
}

int Arbol::NumElem() {
    return numNodos;
}

int Arbol::NumHijos(int nodo){
    int numh = 0;
    int pos2=nodo;
    int i=pos2+1;
    int hijos=0;
    while(Arreglo[i].nodoPadre==pos2){
        ++i;
        ++hijos;

    }
    return hijos;
}

void Arbol::ModificarEtiqueta(int nodo, char etiq){
    Arreglo[nodo].etiqueta = etiq;
}

int Arbol::AgregarHijoI_esimo(int nodo, char etiq, int p){
    int pos =nodo;
    int i = pos;
    int numhij=NumHijos(nodo);
    int contador = 0;
    int j = NumElem();
    int posF=0;

    Nodo nuevo;
    nuevo.nodoPadre = nodo;
    nuevo.etiqueta = etiq;
    if(NumHijos(nodo)==0 || p==numhij+1){
        Arreglo[j]=nuevo;
        posF=j;
    }else{
        int hijo=HMI(nodo);
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
        Arreglo[hijo].nodoPadre=nodo;
        posF=hijo;

    }


++numNodos;
return posF;

}

void Arbol::BorrarHoja(int n){
    int pos =n;
    int i = pos;
    while (i <= NumElem()) {
        Arreglo[i] = Arreglo[i+1];
        ++i;
        Arreglo[i+1].nodoPadre=Arreglo[i+1].nodoPadre-1;
    }
     --numNodos;
}

void Arbol::PonerRaiz(char e){
    Arreglo[0].etiqueta = e;
    Arreglo[0].nodoPadre=-1;
}

int Arbol::BuscarIndice(char etiq) {
    int i = 0;
    while (Arreglo[i].etiqueta != etiq) {
        ++i;
    }
    return i;
}
int Arbol::Buscar(char e){
    int i = BuscarIndice(e);
    return i;
}

void Arbol::Destruir(){

}
void Arbol::MostrarEtiqueta(int nodo){
    cout<<Arreglo[nodo].etiqueta;
}
