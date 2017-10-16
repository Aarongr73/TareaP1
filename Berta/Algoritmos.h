#ifndef ALGORTMOS_2017
#define ALGORITMOS_2017
#include <iostream>
using namespace std;

class Algoritmos {

private:

public:
  void ListadoPN(Arbol);
  bool Iguales(Arbol, Arbol);
  int NumnNiveles(Arbol);
  void BorrarSubArbol(Nodo, Arbol);
  int Profundidad(Nodo, Arbol);
};
#endif
