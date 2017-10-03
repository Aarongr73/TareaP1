#ifndef HIJOMASIZQUIERDO_H
#define HIJOMASIZQUIERDO_H

struct Node{
    Node* Hmi;
    Node* HD;
    int Etiqueta;

public:
    Node(Node* HIzq=nullptr,Node* HDer=nullptr,int etique=0)
        :Hmi(HIzq)
        ,HD(HDer)
        ,Etiqueta(etique)
    {
    }
};
typedef Node NodoPrincipal;

class Arbol
{
public:
    NodoPrincipal* raiz;
    int Elementos;

public:
    Arbol(Node* raiz=nullptr,int elementos=0);
    ~Arbol();
    void Destruir();
    NodoPrincipal* Raiz();
    void DestruirR(Node* nodo);
    void PonerRaiz(int etiqueta);
    Node* AgregarHijoI_esimo(Node* padre,int etiqueta);
    void Crear();
    Node *Buscar(int etiqueta);
    Node* PreOrdenBusqueda(Node* nodo,int etiqueta,Node* buscado);
    Node* Padre(Node* nodo);
    Node* PreOrdenPadre(Node* raiz,Node* buscado);
    Node* HMI(Node* nodo);
    Node* HD(Node *nodo);
    bool Vacio();
    void BorrarHoja(Node* nodo);
    bool isRaiz(Node* nodo);
    int Etiqueta(Node* nodo);
    void Vaciar();
    int NumHijos(Node* nodo);
    int NumElem();
    void ModificarEtiqueta(NodoPrincipal* nodo,int etiqueta);

};

#endif // HIJOMASIZQUIERDO_H
