#ifndef HIJOMASIZQ2
#define HIJOMASIZQ2

struct nodo{
        int Etiqueta;
        nodo* HMI; //HIJO m�s izquierdo
        nodo* HD; //hermano derecho
        nodo* padre;
        public:
            nodo(){
                HMI = 0;
                HD = 0;
                padre = 0;
        }
};
typedef nodo NodoPrincipal;

class Arbol{
private:
    nodo* raiz;
    int numNodos;
    void DestruirR(nodo*);
    void MostrarArbolR(nodo*);
    bool EsHoja(nodo*);
    nodo* PreOrdenBusqueda(nodo*, int, nodo*);
public:
    Arbol();
    ~Arbol();
    void Crear();
    void Destruir();
    void Vaciar();
    bool Vacio();
    bool esRaiz(nodo*);
    void PonerRaiz(int);
    nodo* AgregarHijoI_esimo(nodo*, int);
    void BorrarHoja(nodo*);
    void ModificarEtiqueta(nodo*, int);
    nodo* Raiz();
    nodo* Padre(nodo*);
    nodo* HMI(nodo*);
    nodo* HD(nodo*);
    int Etiqueta(nodo*);
    int NumElem();
    int NumHijos(nodo*);
    void MostrarArbol();
    nodo* Buscar(int);
};
#endif // ARBOL_17

