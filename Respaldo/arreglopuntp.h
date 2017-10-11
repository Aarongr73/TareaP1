#ifndef ARREGLO_PP
#define ARREGLO_PP
#define MAX 100
#include <iostream>
using namespace std;

struct Nodo{
    char Etiqueta;
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
        void Destruir();
        bool Vacio();
        Nodo Raiz();
        Nodo HMI(Nodo);
        Nodo HD(Nodo);
        Nodo Padre(Nodo);
        bool EsHoja(Nodo);
        char Etiqueta(Nodo);
        int NumElem();
        int NumHijos(Nodo);
        void ModificarEtiqueta(Nodo, char);
        Nodo AgregarHijoI_esimo(Nodo, char,int);
        void BorrarHoja(Nodo);
        void PonerRaiz(char);
        int BuscarIndice(char etiqueta);
        Nodo Buscar(char etiqueta);
        void MostrarEtiqueta(Nodo nodo);

};
#endif
