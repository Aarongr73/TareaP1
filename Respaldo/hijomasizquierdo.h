#ifndef HIJOMASIZQUIERDO_H
#define HIJOMASIZQUIERDO_H

struct Node{
    Node* Hmi;
    Node* HD;
    long Etiqueta;

public:
    Node(Node* HIzq=0,Node* HDer=0,long etique=0)
        :Hmi(HIzq)
        ,HD(HDer)
        ,Etiqueta(etique)
    {
    }
};
typedef Node* NodoPrincipal;
extern NodoPrincipal NodoNulo;

class Arbol
{
public:
    Node* raiz;
    long Elementos;

public:
    Arbol(Node* raiz=0,long elementos=0);
    ~Arbol();
    void Destruir();
    Node* Raiz();
    void DestruirR(Node* nodo);
    void PonerRaiz(long etiqueta);
    Node* AgregarHijoI_esimo(Node* padre, long etiqueta, long pos);
    void Crear();
    Node *Buscar(long etiqueta);
    Node* PreOrdenBusqueda(Node* nodo,long etiqueta,Node* buscado);
    Node* Padre(Node* nodo);
    Node* PreOrdenPadre(Node* raiz,Node* buscado);
    Node* HMI(Node* nodo);
    Node* HD(Node *nodo);
    bool Vacio();
    bool EsHoja(Node*);
    void BorrarHoja(Node* nodo);
    bool isRaiz(Node* nodo);
    long Etiqueta(Node* nodo);
    void Vaciar();
    long NumHijos(Node* nodo);
    long NumElem();
    void ModificarEtiqueta(Node* nodo,long etiqueta);
    void MostrarEtiqueta(Node* nodo);
    Node* HMD(Node*);

};

#endif // HIJOMASIZQUIERDO_H
