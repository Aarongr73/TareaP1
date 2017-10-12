#ifndef ARREGLO_PP
#define ARREGLO_PP
#define MAX 100
#include <iostream>
using namespace std;

struct Nodo{
    char Etiqueta;
    int nodoPadre;
};

typedef int NodoPrincipal;
extern int NodoNulo;
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
        int Raiz();
        int HMI(int);
        int HD(int);
        int Padre(int);
        bool EsHoja(int);
        char Etiqueta(int);
        int NumElem();
        int NumHijos(int);
        void ModificarEtiqueta(int, char);
        int AgregarHijoI_esimo(int, char,int);
        void BorrarHoja(int);
        void PonerRaiz(char);
        int BuscarIndice(char etiqueta);
        int Buscar(char etiqueta);
        void MostrarEtiqueta(int nodo);

};
#endif
