#ifndef ARREGLO_PP
#define ARREGLO_PP
#define MAX 100
#include <iostream>
using namespace std;

struct Nodo{
    char etiqueta;
    int nodoPadre;
    Nodo(char etiq=' ',int padre=-1)
        :etiqueta(etiq)
        ,nodoPadre(padre)
    {

    }
};

typedef int NodoPrincipal;
extern int NodoNulo;
class Arbol {

    private:
        Nodo Arreglo[MAX];
        int numNodos;

    public:
        Arbol();
        void Crear();
        void Vaciar();
        void Destruir();
        bool Vacio();
        int Raiz();
        int HMI(int nodo);
        int HD(int);
        int Padre(int);
        bool EsHoja(int nodo);
        char Etiqueta(int nodo);
        int NumElem();
        int NumHijos(int nodo);
        void ModificarEtiqueta(int nodo, char etiq);
        int AgregarHijoI_esimo(int nodo, char etiq, int);
        void BorrarHoja(int);
        void PonerRaiz(char);
        int BuscarIndice(char etiq);
        int Buscar(char etiqueta);
        void MostrarEtiqueta(int nodo);
        int HMD(int);

};
#endif
