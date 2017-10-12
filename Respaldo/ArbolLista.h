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
typedef NodePrincipal* NodoPrincipal;


class Arbol
{
public:
NodePrincipal* raiz;
int Elementos;

public:
Arbol(int capacidad=0, NodePrincipal *raiz=nullptr);
~Arbol();

    void PonerRaiz(int etiqueta);
    void Crear();
    NodePrincipal* HMI(NodePrincipal* nodo);
    NodePrincipal* AgregarHijoI_esimo(NodePrincipal* padre,double Etiqueta,int pos);
    NodePrincipal* Raiz();
    void BorrarHoja(NodePrincipal *nodo);
    NodePrincipal*Buscar(double Etiqueta);
    void BorraListHijos(NodePrincipal* nodo);
    bool BorraListPrincipal(NodePrincipal* nodoActual, NodePrincipal* nodoPrevio, NodePrincipal* nodo);
    int NumElem();
    int NumHijos(NodePrincipal *padre);
    NodePrincipal* HD(NodePrincipal *nodo);
    NodePrincipal* Padre(NodePrincipal* nodo);
    bool Vacio();
    bool isRaiz(NodePrincipal* nodo);
    double Etiqueta(NodePrincipal* nodo);
    void ModificarEtiqueta(NodePrincipal* nodo,double etiqueta);
    void Destruir();
    void Vaciar();
    void MostrarEtiqueta(NodePrincipal* nodo);

};

#endif // ARBOLISTA_H
