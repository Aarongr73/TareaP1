#include "Algoritmos.h"

void Algoritmos::ListadoPN(Arbol arbol) {
  Cola cola;
  if (!arbol.Vacio()) {
    cola.Iniciar();
    cola.Encolar(arbol.Raiz());
    while (!cola.Vacia()) {
      Nodo n = cola.Desencolar();
      arbol.MostrarEtiqueta(n);
      Nodo nh = arbol.HMI(n);
      while (nh != /*nodoNulo*/ 0) {
        cola.Encolar(nh);
        nh = arbol.HD(nh);
      }
    }
  }
}

bool Algoritmos::Iguales(Arbol arbol1, Arbol arbol2) {
  Cola cola1;
  Cola cola2;
  if (!arbol1.Vacio() && !arbol2.Vacio()) {
    cola1.Iniciar();
    cola2.Iniciar();
    if (arbol1.Raiz() == arbol2.Raiz()) {
      cola1.Encolar(arbol1.Raiz());
      cola2.Encolar(arbol2.Raiz());
      while (!cola1.Vacia() && !cola2.Vacia()) {
        Nodo n1 = cola1.Desencolar();
        Nodo n2 = cola2.Desencolar();
        Nodo nh1 = arbol1.HMI(n1);
        Nodo nh2 = arbol2.HMI(n2);
        while (nh1 != /*nodoNulo*/ 0 && nh2 != /*nodoNulo*/ 0 && nh1 == nh2) {
          cola1.Encolar(nh1);
          cola2.Encolar(nh2);
          nh1 = arbol1.HD(nh1);
          nh2 = arbol2.HD(nh2);
        }
        if (nh1 != nh2) {
          return false;
        }
      }
      return true;
    }
  }
}

int Algoritmos::NumnNiveles(Arbol arbol) {
  Cola cola;
  if (!arbol.Vacio()) {
    cola.Iniciar();
    cola.Encolar(arbol.Raiz());
    while (!cola.Vacia()) {
      Nodo n = cola.Desencolar();
      Nodo nh = arbol.HMI(n);
      while (nh != /*nodoNulo*/ 0) {
        cola.Encolar(nh);
        nh = arbol.HD(nh);
      }
    }
  }
  return Profundidad(n, arbol);
}

void Algoritmos::BorrarSubArbol(Nodo nodo, Arbol arbol) {
  Nodo nh = arbol.HMI(nodo);
  while (nh != /*nodoNulo*/ 0) {
    BorrarSubArbol(nh, arbol);
  }
  arbol.BorrarHoja(nodo);
}

int Algoritmos::Profundidad(Nodo nodo, Arbol arbol) {
  int conta = 1;
  while (nodo.nodoPadre != arbol.Raiz()) {
    nodo = nodo.nodoPadre;
    ++conta;
  }
  return conta;
}
