#include "ArregloPP.h"

ArregloPP::ArregloPP(){
	PonerRaiz(' ');
	Arreglo[0].nodoPadre = 0;
}

ArregloPP::~ArregloPP(){
	//Como es estático no se necesita destructor.
}

void ArregloPP::Vaciar(){
	Arreglo[NumNodos()].nodoPadre = 0;
	// Preguntar
}

bool ArregloPP::Vacio(){
	if (Arreglo[NumNodos()].nodoPadre == 0) {
		return 1;
	}
	return 0;
}

bool ArregloPP::Raiz(Nodo n){
	if(Arreglo[0].etiqueta == n.etiqueta) {
		return true;
	}else{
		return false;
	}
}

Nodo ArregloPP::HijoMasIzq(Nodo n){
	int pos = Buscar(n.etiqueta);
	int i = pos;
	while (Arreglo[i].nodoPadre != pos) {
		i++;
	}
	return Arreglo[i];
}

Nodo ArregloPP::HermanoDer(Nodo n){
	int pos = Buscar(n) + 1;
	if ( Arreglo[pos] == n.nodoPadre ) {
		return Arreglo[pos];
	}else{
		return n;
	}
}

Nodo ArregloPP::Padre(Nodo n){
	return Arreglo[n.nodoPadre];
}

Nodo ArregloPP::EsHoja(Nodo n){
	int pos = Buscar(n.etiqueta);
	int i = pos;
	while(Arreglo[i].nodoPadre != pos && pos <= NumnNodos()) {
		++i;
	}
	if (i == NumNodos() && Arreglo[NumNodos()].nodoPadre != pos) {
		return true;
	}else{
		return false;
	}
}

char ArregloPP::Etiqueta(Nodo n) {
	return n.etiqueta;
}

int ArregloPP::NumNodos() { //Preguntar porque es O(1)
	return contador;
}

int ArregloPP::NumHijos(Nodo n){
	int numh = 0;
	int pos = Buscar(HijoMasIzq(n).etiqueta);
	int i = pos;
	while (Arreglo[i].nodoPadre == pos) {
		++numh;
		++i;
	}
	return numh;
}

void ArregloPP::ModifEtiq(Nodo n, char e){
	n.etiqueta = e;
}

void ArregloPP::AgregarHijo(Nodo n, char e, int p){
	int pos = Buscar(n.etiqueta);
	int i = pos;
	int contador = 0;

	Nodo nuevo;
	nuevo.nodoPadre = pos;
	nuevo.etiqueta = e;

	while (Arreglo[i].nodoPadre == pos && contador <= p) {
		++contador;
	}

}

void ArregloPP::BorrarHoja(Nodo n){

}

void ArregloPP::PonerRaiz(char e){
	Arreglo[0].etiqueta = e;
}

int ArregloPP::Buscar(char e) {
	int i = 0;
	while(Arreglo[i].etiqueta != n.etiqueta) {
		++i;
	}
	return i;
}
