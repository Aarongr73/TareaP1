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
    Arreglo[NumNodos()].nodoPadre = 0;
    numNodos = 0;
}

bool Arbol::Vacio(){
    if (Arreglo[NumNodos()].nodoPadre == 0) {
        return 1;
    }
    return 0;
}

bool Arbol::Raiz(Nodo n){
    if(Arreglo[0].etiqueta == n.etiqueta) {
        return true;
    } else {
        return false;
    }
}

Nodo Arbol::HMI(Nodo n){
    int pos = Buscar(n.etiqueta);
    int i = pos;
    while (Arreglo[i].nodoPadre != pos) {
        i++;
    }
    return Arreglo[i];
}

Nodo Arbol::HD(Nodo n){
    int pos = Buscar(n.etiqueta) + 1;
    if ( pos == n.nodoPadre ) {
        return Arreglo[pos];
    }else{
        return n;
    }
}

Nodo Arbol::Padre(Nodo n){
    return Arreglo[n.nodoPadre];
}

bool Arbol::EsHoja(Nodo n){
    int pos = Buscar(n.etiqueta);
    int i = pos;
    while(Arreglo[i].nodoPadre != pos && pos <= NumNodos()) {
        ++i;
    }
    if (i == NumNodos() && Arreglo[NumNodos()].nodoPadre != pos) {
        return true;
    }else{
        return false;
    }
}

char Arbol::Etiqueta(Nodo n) {
    return n.etiqueta;
}

int Arbol::NumNodos() {
    return numNodos;
}

int Arbol::NumHijos(Nodo n){
    int numh = 0;
    int pos = Buscar(HMI(n).etiqueta);
    int i = pos;
    while (Arreglo[i].nodoPadre == pos) {
        ++numh;
        ++i;
    }
    return numh;
}

void Arbol::ModificarEtiqueta(Nodo n, char e){
    n.etiqueta = e;
}

Nodo Arbol::AgregarHijo(Nodo n, char e){
    int pos = Buscar(n.etiqueta);
    int i = pos;
    int contador = 0;
    int j = NumNodos();

    Nodo nuevo;
    nuevo.nodoPadre = pos;
    nuevo.etiqueta = e;

    while (Arreglo[i].nodoPadre == pos && contador <= p) {
        ++contador;
    }

    while (j >= pos) {
        Arreglo[j+1] = Arreglo[j];
        --j;
    }

    Arreglo[pos] = nuevo;
    ++numNodos;

return n;

}

void Arbol::BorrarHoja(Nodo n){
    int pos = Buscar(n.etiqueta);
    int i = pos;
    while (i <= NumNodos()) {
        Arreglo[i+1] = Arreglo[i];
    }
    --numNodos;
}

void Arbol::PonerRaiz(char e){
    Arreglo[0].etiqueta = e;
}

int Arbol::Buscar(char e) {
    int i = 0;
    while (Arreglo[i].etiqueta != n.etiqueta) {
        ++i;
    }
    return i;
}
