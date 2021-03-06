#include "algoritmos2.h"

#include<iostream>

using namespace std;


int Max = 0; //Variable global para los niveles
int nivelG; //Variable global para listar iésimo nivel



void Algoritmos::ListPost(Arbol& arbol){
    if(!arbol.Vacio()){
        ListPostR(arbol.Raiz(),arbol);
    }
}

void Algoritmos::ListPostR(NodoPrincipal nodo, Arbol& arbol){
    NodoPrincipal nh = arbol.HMI(nodo);
    while(nh != NodoNulo){
        ListPostR(nh,arbol);
        nh = arbol.HD(nh);
    }
    cout<<"Etiqueta del nodo: "<<arbol.Etiqueta(nodo)<<endl; //Impresion al final por ser post orden
}
void Algoritmos::ListPre(Arbol& arbol){
    if(!arbol.Vacio()){
        ListPreR(arbol.Raiz(),arbol);
    }
}
void Algoritmos::ListPreR(NodoPrincipal nodo, Arbol& arbol){
    cout<<"Etiqueta del nodo: "<<arbol.Etiqueta(nodo)<<endl; //Impresion al principio por ser pre orden
    NodoPrincipal nh = arbol.HMI(nodo);
    while(nh != NodoNulo){
        ListPostR(nh,arbol);
        nh = arbol.HD(nh);
    }
}

int Algoritmos::NumNiveles(Arbol& arbol){
    if(arbol.NumElem() >= 1){ //Arbol mas de la raiz
        NumNivelesR(arbol.Raiz(), 1,arbol);
    }
    cout<<Max<<endl; //Se retorna el numero de niveles
    return Max;
}

void Algoritmos::NumNivelesR(NodoPrincipal n, int nivel, Arbol &arbol){
    if(arbol.EsHoja(n)){ //Cuando llegamos a hoja actualizamos el nivel
        if(nivel > Max){
            Max = nivel;
        }
    }else{
        NodoPrincipal nh = arbol.HMI(n); //Recorrido pre orden
        while(nh != NodoNulo){
            NumNivelesR(nh, nivel+1,arbol);
            nh = arbol.HD(nh);
        }
    }
}

NodoPrincipal Algoritmos::AveriguarHI(Arbol& arbol, NodoPrincipal hermano){
    if(!arbol.Vacio()){
        Cola<NodoPrincipal> cola; //Recorrido por niveles. LLenamos la cola de nodos
        cola.Crear();
        cola.Encolar(arbol.Raiz());
        while(!cola.Vacia()){
            NodoPrincipal n = cola.Desencolar();
            if(arbol.HD(n) == hermano){ //Si el buscado es el hermano derecho de este nodo, lo retornamos
                return n;
            }else{
                NodoPrincipal nh = arbol.HMI(n); //Recorrido por niveles
                while(nh != NodoNulo){
                    cola.Encolar(nh);
                    nh = arbol.HD(nh);
                }
            }
        }
        return NodoNulo;
        cola.Destruir();
    }
}

bool Algoritmos::Repetidos( Arbol &arbol){
    ListaCola<NodoPrincipal>lista;
    NodoPrincipal n;
    NodoPrincipal nh;
    NodoPrincipal nh2;
    int pos=0;
    int recorrido=0;
    int cant=arbol.NumElem();
    lista.Agregar(arbol.Raiz());
    while(pos<cant){
        n=lista.Recuperar(pos);
        nh=arbol.HMI(n);
        while (nh!=NodoNulo) {
            for(int i=0;i<lista.NumElem();i++){
                if(arbol.Etiqueta(nh)==arbol.Etiqueta(lista.Recuperar(i)))
                    return true;
            }
            lista.Agregar(nh);
            nh=arbol.HD(nh);
        }
        ++pos;
    }
    return false;

}
bool Algoritmos::Busqueda(Arbol& arbol, int etiqueta){ //Busqueda implementada en pre orden
    bool found = 0;
    if(!arbol.Vacio())
        found = BusquedaR(arbol.Raiz(), etiqueta, found,arbol);
    return found;

}

bool Algoritmos::BusquedaR(NodoPrincipal actual,int etiqueta, bool node,Arbol& arbol){
    if(arbol.Etiqueta(actual)==etiqueta){
        cout<<"encontrado"<<endl;
         return true;
    }

    NodoPrincipal nh = arbol.HMI(actual);
    while(nh != NodoNulo ){
        node = BusquedaR(nh,etiqueta,node,arbol);
        if(node){
            return node;
        }
        nh = arbol.HD(nh);
    }
}
void  Algoritmos::ListadoHijos(Arbol arbol,NodoPrincipal nodo){
    NodoPrincipal n=arbol.HMI(nodo); //Se busca el hmi del nodo enviado y en caso de no ser nulo, se listan sus hermanos
    while(n!=NodoNulo){
        cout<<arbol.Etiqueta(n)<<" ";
        n=arbol.HD(n);
    }
    cout<<endl;
}

void Algoritmos::ListarIesimo(Arbol& arbol, int nivel){
    nivelG = nivel; //Igualar global al parámetro
    if(!arbol.Vacio()){
        ListarIesimoR(arbol, 1, arbol.Raiz());
    }
}

void Algoritmos::ListarIesimoR(Arbol& arbol, int actual, NodoPrincipal nodo){
    if(actual == nivelG){ //Cuando encontremos el nivel nos metemos al if que muestre la etiqueta
        cout<<arbol.Etiqueta(nodo)<<endl;
    }else{
        NodoPrincipal nh = arbol.HMI(nodo); //Recorrido por niveles
        while(nh != NodoNulo){
            ListarIesimoR(arbol, actual+1, nh);
            nh = arbol.HD(nh);
        }
    }
}

Arbol Algoritmos::Copiar(Arbol& arbol1, Arbol& arbolCopia){ //Se envia la copia como parametro para retornarla luego
    arbolCopia.Crear();
    if(arbol1.NumElem() != 0){
        Cola<NodoPrincipal> cola1; //Cola arbol original
        Cola<NodoPrincipal> cola2; //Cola arbol copia
        NodoPrincipal nodo1;
        NodoPrincipal nodo2;
        NodoPrincipal nodoH1;
        NodoPrincipal nodoH2;
        cola1.Crear();
        cola2.Crear();
        arbolCopia.PonerRaiz(arbol1.Etiqueta(arbol1.Raiz())); //Creamos la raiz de la copia con la otra etiqueta
        cola1.Encolar(arbol1.Raiz());
        cola2.Encolar(arbolCopia.Raiz());
        while(!cola1.Vacia()){ //Recorrido por niveles
            nodo1 = cola1.Desencolar();
            nodo2 = cola2.Desencolar();
            nodoH1 = arbol1.HMI(nodo1);
            while(nodoH1 != NodoNulo){
                arbolCopia.AgregarHijoI_esimo(nodo2, arbol1.Etiqueta(nodoH1), arbolCopia.NumHijos(nodo2)+1); //Agregar al final del arbol
                nodoH2 = arbolCopia.HMD(nodo2); //Metodo implementado Hijo Mas Derecho
                cola1.Encolar(nodoH1);
                cola2.Encolar(nodoH2);
                nodoH1 = arbol1.HD(nodoH1);
            }
        }
    }

    return arbolCopia;
}

void Algoritmos::ListadoPN(Arbol& arbol) {
  Cola<NodoPrincipal> cola;
  if (!arbol.Vacio()) {
    cola.Crear();
    cola.Encolar(arbol.Raiz());
    while (!cola.Vacia()) { //Recorrido por niveles
      NodoPrincipal n = cola.Desencolar();
     cout<<"Etiqueta del nodo: "<<arbol.Etiqueta(n)<<endl; //Listado
      NodoPrincipal nh = arbol.HMI(n);
      while (nh !=NodoNulo) {
        cola.Encolar(nh);
        nh = arbol.HD(nh);
      }
    }
  }
}

bool Algoritmos::Iguales(Arbol &arbol1, Arbol &arbol2) {
 Cola<NodoPrincipal> cola1; //Cola arbol 1
 Cola<NodoPrincipal> cola2; //Cola arbol 2
  if (!arbol1.Vacio() && !arbol2.Vacio()) {
    cola1.Crear();
    cola2.Crear();
    if (arbol1.Etiqueta(arbol1.Raiz()) == arbol2.Etiqueta(arbol2.Raiz())) { //Mientras las etiquetas sean iguales encolamos
      cola1.Encolar(arbol1.Raiz());
      cola2.Encolar(arbol2.Raiz());
      while (!cola1.Vacia() && !cola2.Vacia()) {
        NodoPrincipal n1 = cola1.Desencolar();
        NodoPrincipal n2 = cola2.Desencolar();
        NodoPrincipal nh1 = arbol1.HMI(n1);
        NodoPrincipal nh2 = arbol2.HMI(n2);
        while (nh1 != NodoNulo && nh2 != NodoNulo  && arbol1.Etiqueta(nh1) == arbol2.Etiqueta(nh2)) {
          cola1.Encolar(nh1);
          cola2.Encolar(nh2);
          nh1 = arbol1.HD(nh1);
          nh2 = arbol2.HD(nh2);
          if (arbol1.Etiqueta(nh1) != arbol2.Etiqueta(nh2) && nh2!=NodoNulo && nh1!=NodoNulo) {
            return false;    //Si ninguno de los nodos es nulo, pero su etiqueta es diferente retornamos false
          }
        }
      }
      return true; //Si no sale del while es porque todas las etiquetas son iguales
    }
  }
}

int Algoritmos::NumnNiveles(Arbol &arbol) {
  Cola<NodoPrincipal> cola;
   NodoPrincipal n;
    NodoPrincipal nh;
  if (!arbol.Vacio()) {
    cola.Crear();
    cola.Encolar(arbol.Raiz());
    while (!cola.Vacia()) {
     n = cola.Desencolar();
     nh = arbol.HMI(n);
      while (nh != NodoNulo ) {
        cola.Encolar(nh);
        nh = arbol.HD(nh);
      }
    }
  }
  return Profundidad(n, arbol);
}

void Algoritmos::BorrarSubArbol(NodoPrincipal nodo, Arbol& arbol) {
  NodoPrincipal nh = arbol.HMI(nodo);
  while (nh != NodoNulo) {
    BorrarSubArbol(nh, arbol);
    nh=arbol.HMI(nodo);
  }
  arbol.BorrarHoja(nodo);
}

int Algoritmos::Profundidad(NodoPrincipal nodo, Arbol &arbol) {
  int conta = 1;
  while (arbol.Padre(nodo)!= arbol.Raiz()) {
    nodo = arbol.Padre(nodo);
    ++conta;
  }
  return conta+1;
}

