#ifndef ARBOLISTA_H
#define ARBOLISTA_H

struct NodePrincipal;
struct NodeHijos
{
   NodeHijos* next;
   NodePrincipal* listaPrincipal;

  public:
    NodeHijos(NodeHijos* nextHijo = nullptr,NodePrincipal* yo=nullptr)
      : next(nextHijo)
      ,listaPrincipal(yo)
   {
   }
};
struct NodePrincipal
{
   int Etiqueta;
   NodeHijos* PrimerHijo;
   NodePrincipal* siguiente;

  public:
   NodePrincipal( double data=0,NodeHijos* nextHijo = nullptr,NodePrincipal* sig=nullptr)
      : Etiqueta(data)
      , PrimerHijo(nextHijo)
      ,siguiente(sig)
   {
   }
};

typedef NodePrincipal NodoPrincipal;


class Arbol
{
public:
NodoPrincipal* raiz;
int Elementos;

public:
Arbol(int capacidad=0,NodoPrincipal* raiz=nullptr);
~Arbol();

    void PonerRaiz(int etiqueta);
    void Crear();
    NodoPrincipal* HMI(NodoPrincipal* nodo);
    NodoPrincipal* AgregarHijoI_esimo(NodoPrincipal* padre,double Etiqueta,int pos);
    NodoPrincipal* Raiz();
    void BorrarHoja(NodePrincipal *nodo);
    NodePrincipal*Buscar(double Etiqueta);
    void BorraListHijos(NodoPrincipal* nodo);
    bool BorraListPrincipal(NodoPrincipal* nodoActual, NodoPrincipal* nodoPrevio, NodoPrincipal* nodo);
    int NumElem();
    int NumHijos(NodoPrincipal* padre);
    NodoPrincipal* HD(NodoPrincipal* nodo);
    NodoPrincipal* Padre(NodoPrincipal* nodo);
    bool Vacio();
    bool isRaiz(NodoPrincipal* nodo);
    double Etiqueta(NodoPrincipal* nodo);
    void ModificarEtiqueta(NodoPrincipal* nodo,double etiqueta);
    void Destruir();
    void Vaciar();

};

#endif // ARBOLISTA_H
