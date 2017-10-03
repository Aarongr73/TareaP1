#ifndef HIJOMASIZQ3
#define HIJOMASIZQ3

struct nodo{
        int etiqueta;
        nodo* HMI; //HIJO más izquierdo
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
    nodo* HijoMasIzquierdo(nodo*);
    nodo* HermanoDerecho(nodo*);
    int Etiqueta(nodo*);
    int NumNodos();
    int NumHijos(nodo*);
    void MostrarArbol();
    nodo* Buscar(int);
};
#endif // ARBOL_17

