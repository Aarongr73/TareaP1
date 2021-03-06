#ifndef HIJOMASIZQ3
#define HIJOMASIZQ3

struct nodo{
        int Etiqueta;
        nodo* HMI; //HIJO m�s izquierdo
        nodo* HD; //hermano derecho
        nodo* HI; //hermano izquierdo
        nodo* padre;
        public:
            nodo(){
                HMI = 0;
                HD = 0;
                HI = 0;
                padre = 0;
        }
};
typedef nodo* NodoPrincipal;
extern NodoPrincipal NodoNulo;

class Arbol{
private:
    nodo* raiz;
    int numNodos;
    void DestruirR(nodo*);
    nodo* PreOrdenBusqueda(nodo*, int, nodo*);
public:
    Arbol();
    ~Arbol();
     bool EsHoja(nodo*);
    void Crear();
    void Destruir();
    void Vaciar();
    bool Vacio();
    bool esRaiz(nodo*);
    void PonerRaiz(int);
    nodo* AgregarHijoI_esimo(nodo*, int,int);
    void BorrarHoja(nodo*);
    void ModificarEtiqueta(nodo*, int);
    nodo* Raiz();
    nodo* Padre(nodo*);
    nodo* HMI(nodo*);
    nodo* HD(nodo*);
    int Etiqueta(nodo*);
    int NumElem();
    int NumHijos(nodo*);
    nodo* Buscar(int);
    void MostrarEtiqueta(nodo*);
    nodo* HMD(nodo*);
};
#endif // ARBOL_17

