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

class ArregloPP {

	private:
		struct Nodo Arreglo[MAX];
		int contador;

	public:
		ArregloPP();
    ~ArregloPP();
		void Vaciar();
		bool Vacio();
		bool Raiz(Nodo);
		struct Nodo HijoMasIzq(Nodo);
		struct Nodo HermanoDer(Nodo);
		struct Nodo Padre(Nodo);
		struct Nodo EsHoja(Nodo);
		char Etiqueta(Nodo);
		int NumNodos();
		int NumHijos(Nodo);
		void ModifEtiq(Nodo, char);
		void AgregarHijo(Nodo, char);
		void BorrarHoja(Nodo);
		void PonerRaiz(char);
		int Buscar(char);

};
#endif
