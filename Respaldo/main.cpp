#include <iostream>
#include "ArbolLista.h"
//#include "hijomasizquierdo.h"
//#include "hijomasizq3.h"
//#include "hijomasizq2.h"
#include "algoritmos2.h"
#include "Cola.h"
//#include "arreglopuntp.h"
using namespace std;

void DesplegarMenuArbol(){
    Arbol arbol;
    arbol.Crear();
    int seleccion;

do{
        cout<<"Seleccione una opcion\n"
              "(1)Poner Raiz\n"
              "(2)AgregarHijo\n"
              "(3)Borrar Hoja\n"
              "(4)Hijo Mas Izquierdo\n"
              "(5)Hermano Derecho\n"
              "(6)Vacio?\n"
              "(7)Vaciar\n"
              "(8)Padre\n"
              "(9)Modificar Etitqueta\n"
              "(10)Numero de elementos en el arbol\n"
              "(11) Numeros de hijos de un nodo\n"
              "(0)Salir\n";
    cin>>seleccion;
    switch(seleccion){
        case 0:
            arbol.Destruir();
         break;
        case 1:
        {
            int raiz;
            cout<<"introduzca un valor para la raiz";
            cin>>raiz;
            arbol.PonerRaiz(raiz);
            cout<<"Agregada la raiz!\n";
        }
        break;
        case 2:
        {
            int etiquetaPadre;
            int etiquetaHijo;
            int pos;
            cout<<"Introduzca el la etiqueta de padre\n";
            cin>>etiquetaPadre;
            cout<<"Introduzca la etiqueta del hijo\n";
            cin>>etiquetaHijo;
            cout<<"seleccione donde\n";
            cin>>pos;
            arbol.AgregarHijoI_esimo(arbol.Buscar(etiquetaPadre),etiquetaHijo,pos);
        }
            break;
        case 3:
        {
            int nodoABorrar;
            cout<<"Intrduzca la etiqueta de la hoja a borra\n";
            cin>>nodoABorrar;
            arbol.BorrarHoja(arbol.Buscar(nodoABorrar));
        }
        break;
        case 4:
        {
           int nodo;
           NodoPrincipal hmi;
           cout<<"Introduzca la etiqueta del nodo \n";
           cin>>nodo;
           hmi=arbol.HMI(arbol.Buscar(nodo));
           cout<<"Hijo mas izquierdo es: ";
           arbol.MostrarEtiqueta(hmi);
           cout<<"\n";
        }
        break;
        case 5:
        {
            NodoPrincipal hder;
            int hizq;
            cout<<"Introduzca la etiqueta del nodo\n";
            cin>>hizq;
            hder=arbol.HD(arbol.Buscar(hizq));
        }
        break;
        case 6:
        {
            bool vacio;
            vacio=arbol.Vacio();
            if(!vacio)
                cout<<"No vacio\n";
            else
                cout<<"Vacio!!\n";
        }
        break;
        case 7:
        {
            arbol.Vaciar();
            cout<<"Arbol vaciado!!\n";
        }
        break;
        case 8:
        {
            NodoPrincipal padre;
            int nodoHijo;
            cout<<"Introduzca la etiqueta del nodo hijo\n";
            cin>>nodoHijo;
            padre=arbol.Padre(arbol.Buscar(nodoHijo));
            cout<<"El padre de "<< nodoHijo+" es: ";
            arbol.MostrarEtiqueta(padre);
            cout<<"\n";
        }
        break;
        case 9:
         {
            int nuevaEtiqueta;
            int nodoActual;
            cout<<"Introduzaca la etiqueta del nodo a modificar\n";
            cin>>nodoActual;
            cout<<"Introduzca la nueva etiqueta\n";
            cin>> nuevaEtiqueta;
            arbol.ModificarEtiqueta(arbol.Buscar(nodoActual),nuevaEtiqueta);
        }
        break;
        case 10:
        {
            int numelem;
            numelem=arbol.NumElem();
            cout<<"La cantidad de elementos es de: "<<numelem<<"\n";
        }
        break;
        case 11:
        {
            int numhijos;
            int elpadre;
            cout<<"Introduzca la etiquta del nodo padre\n";
            cin>>elpadre;
            numhijos=arbol.NumHijos(arbol.Buscar(elpadre));
            arbol.MostrarEtiqueta(arbol.Buscar(elpadre));
            cout<<" tiene"<<numhijos<<"hijos\n";
        }
        break;

        default:
        cout<<"Error\n";
        }

   }while(seleccion!=0);
}


void menu(){
int seleccion;
do{
    cout<<"Puede seleccionar entre Arbol(1) "
          "Cola(2) (0)Salir\n";
    cin>>seleccion;

    switch(seleccion){
        case 0:
            cout<<"SALIENDO\n";
        break;
        case 1:
            DesplegarMenuArbol();
        break;

    }
}while(seleccion!=0);
}

int main()
{
      /* Cola cola;
      cola.Crear();
      cola.Encolar(8);
      cola.Desencolar();*/
    //  menu();

    Arbol arbol;
    Algoritmos alg;
    NodoPrincipal x;
    arbol.Crear();
    arbol.PonerRaiz(1);
    x=arbol.AgregarHijoI_esimo(arbol.Buscar(1),2,1);
    x=arbol.AgregarHijoI_esimo(arbol.Buscar(1),3,2);
    x=arbol.AgregarHijoI_esimo(arbol.Buscar(3),4,1);
    x=arbol.AgregarHijoI_esimo(arbol.Buscar(3),5,2);
    alg.NumNiveles(arbol);
    alg.ListPost(arbol);
    alg.ListadoHijos(arbol,arbol.Buscar(3));
    cout<<arbol.HD(arbol.Buscar(4))->Etiqueta;











    return 0;
}
