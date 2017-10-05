#ifndef ARREGLO_PP
#define ARREGLO_PP
#define MAX 10
#include <iostream>
using namespace std;

struct Nodo{
	char etiqueta;
	int nodoPadre;
};

typedef Nodo NodoPrincipal;

class Arbol {

	private:
		Nodo Arreglo[MAX];
		int numNodos;

	public:
		Arbol();
    ~Arbol();
		void Crear();
		void Vaciar();
		bool Vacio();
		bool Raiz(Nodo);
		Nodo HijoMasIzq(Nodo);
		Nodo HermanoDer(Nodo);
		Nodo Padre(Nodo);
		Nodo EsHoja(Nodo);
		char Etiqueta(Nodo);
		int NumNodos();
		int NumHijos(Nodo);
		void ModifEtiq(Nodo, char);
		Nodo AgregarHijo(Nodo, char);
		void BorrarHoja(Nodo);
		void PonerRaiz(char);
		int Buscar(char);

};
#endif
