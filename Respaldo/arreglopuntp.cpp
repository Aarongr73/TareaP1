#include "arreglopuntp.h"

int NodoNulo=-1;
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

int Arbol::Raiz(){
    Arreglo[0].nodoPadre=10000000000;
    return 0;
}

int Arbol::HMI(int n){
    int pos = n;
    int i = pos+1;
    while(Arreglo[i].nodoPadre!=pos){
        ++i;
        if(i>NumElem()){
            return NodoNulo;
        }
    }
    return i;
}

int Arbol::HD(int n){
    int pos = n;
    int i=pos+1;
    while(Arreglo[i].nodoPadre!=Arreglo[n].nodoPadre){
        i++;
        if(i>NumElem()){
            return NodoNulo;
        }
    }
    return i;
}

int Arbol::Padre(int n){
    return Arreglo[n].nodoPadre;
}

bool Arbol::EsHoja(int n){
    int pos = n;
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

char Arbol::Etiqueta(int n) {
    return Arreglo[n].Etiqueta;
}

int Arbol::NumElem() {
    return numNodos;
}

int Arbol::NumHijos(int n){
    int numh = 0;
    int pos2=n;
    int i=pos2+1;
    int hijos=0;
    while(Arreglo[i].nodoPadre==pos2){
        ++i;
        ++hijos;

    }
    return hijos;
}

void Arbol::ModificarEtiqueta(int n, char e){
    Arreglo[n].Etiqueta = e;
}

int Arbol::AgregarHijoI_esimo(int n, char e, int p){
    int pos =n;
    int i = pos;
    int numhij=NumHijos(n);
    int contador = 0;
    int j = NumElem();
    int posF=0;

    Nodo nuevo;
    nuevo.nodoPadre = pos;
    nuevo.Etiqueta = e;
    if(NumHijos(n)==0 || p==numhij+1){
        Arreglo[j]=nuevo;
        posF=j;
    }else{
        int hijo=HMI(n);
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
    Arreglo[0].Etiqueta = e;
}

int Arbol::BuscarIndice(char e) {
    int i = 0;
    while (Arreglo[i].Etiqueta != e) {
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
    cout<<Arreglo[nodo].Etiqueta;
}
