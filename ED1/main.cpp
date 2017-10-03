#include <iostream>
//#include "ArbolLista.h"
#include "hijomasizquierdo.h"
//#include "hijomasizq3.h"
//#include "hijomasizquierdo.h"
//#include "hijomasizq3.h"
#include "Cola.h"
//#include "ArbolLista.h"
using namespace std;

void DesplegarMenuArbol(){
    Arbol arbol;
    arbol.Crear();
    int seleccion;

do{
        cout<<"Seleccione una opcion\n"
              "(1)Raiz\n"
              "(2)Poner Raiz\n"
              "(3)AgregarHijo\n"
              "(4)Borrar Hoja\n"
              "(5)Hijo Mas Izquierdo\n"
              "(6)Hermano Derecho\n"
              "(7)Vacio?\n"
              "(8)Vaciar\n"
              "(9)Padre\n"
              "(10)Modificar Etitqueta\n"
              "(11)Numero de elementos en el arbol\n"
              "(12) Numeros de hijos de un nodo\n"
              "(0)Salir\n";
    cin>>seleccion;
    switch(seleccion){
        case 0:
            arbol.Destruir();
         break;
        case 1:
            NodoPrincipal* agregado;
            agregado=arbol.Raiz();
            cout<<agregado->Etiqueta;
        break;
        case 2:
            cout<<"introduzca la nueva etiqueta\n";
            int etiqueta;
            cin>>etiqueta;
            arbol.PonerRaiz(etiqueta);
        break;
        case 3:
            int etiquetaPadre;
            int etiquetaHijo;
            cout<<"Introduzca el la etiqueta de padre\n";
            cin>>etiquetaPadre;
            cout<<"Introduzca la etiqueta del hijo\n";
            cin>>etiquetaHijo;
            arbol.AgregarHijoI_esimo(arbol.Buscar(etiquetaPadre),etiquetaHijo);
            break;
        case 4:
            int nodoABorrar;
            cout<<"Intrduzca la etiqueta de la hoja a borra\n";
            cin>>nodoABorrar;
            arbol.BorrarHoja(arbol.Buscar(nodoABorrar));
        break;
        case 5:
           int Padre;
           NodoPrincipal* hmi;
           cout<<"Introduzca la etiqueta del nodo padre\n";
           cin>>Padre;
           hmi=arbol.HMI(arbol.Buscar(Padre));
           cout<<"Hijo mas izquierdo es: "<<hmi->Etiqueta<<"\n";
        break;
        case 6:
            NodoPrincipal* hder;
            int hizq;
            cout<<"Introduzca la etiqueta del nodo\n";
            cin>>hizq;
            hder=arbol.HD(arbol.Buscar(hizq));
        break;
        case 7:
            bool vacio;
            vacio=arbol.Vacio();
            if(!vacio)
                cout<<"No vacio\n";
            else
                cout<<"Vacio!!\n";
        break;
        case 8:
            arbol.Vaciar();
            cout<<"Arbol vaciado!!\n";
        break;
        case 9:
            NodoPrincipal* padre;
            int nodoHijo;
            cout<<"Introduzca la etiqueta del nodo hijo\n";
            cin>>nodoHijo;
            padre=arbol.Padre(arbol.Buscar(nodoHijo));
            cout<<"El padre de "<< nodoHijo+" es: "<<padre->Etiqueta+"\n";
        break;
        case 10:
            int nuevaEtiqueta;
            int nodoActual;
            cout<<"Introduzaca la etiqueta del nodo a modificar\n";
            cin>>nodoActual;
            cout<<"Introduzca la nueva etiqueta\n";
            cin>> nuevaEtiqueta;
            arbol.ModificarEtiqueta(arbol.Buscar(nodoActual),nuevaEtiqueta);
        break;
        case 11:
            int numelem;
            numelem=arbol.NumElem();
            cout<<"La cantidad de elementos es de: "<<numelem<<"\n";
        break;
        case 12:
            int numhijos;
            int elpadre;
            cout<<"Introduzca la etiquta del nodo padre\n";
            cin>>elpadre;
            numhijos=arbol.NumHijos(arbol.Buscar(elpadre));
            cout<<padre->Etiqueta+"tiene"<<numhijos<<"hijos\n";
        break;

        default:
        cout<<"Error\n";
        }

   }while(seleccion!=0);
}
void DesplegarMenuCola(){
    Cola cola;
    cola.Crear();
    int seleccion;
    do{
        cout<<"Seleccione alguna opcion\n"
              "(1)Encolar\n"
              "(2)Desencolar\n"
              "(3)Frente\n"
              "(4)Vacio?\n"
              "(5)Vaciar\n"
              "(0)Salir\n";
        cin>>seleccion;
        switch (seleccion) {
        case 0:
            break;
        case 1:
            int encolado;
            cout<<"Introduzca el valor a encolar\n";
            cin>>encolado;
            cola.Encolar(encolado);
            cout<<encolado<<" Encolado! \n";
            break;
        case 2:
            int desencolado;
            desencolado=cola.Desencolar();
            cout<<desencolado<<" fue desencolado\n";
            break;
        case 3:
            int frente;
            frente=cola.Frente();
            cout<<frente<<" es el frente de la cola\n";
        case 4:
            bool vacio;
            vacio=cola.Vacia();
            if(vacio)
                cout<<"Esta vacia la colaaaaa!!!\n";
            else
                cout<<"La cola no esta vacia\n";
            break;
        case 5:
            cola.Vaciar();
            cout<<"Cola vaciada!\n";
            break;

        default:
            cout<<"Entrada invalida\n";
            break;
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
        case 2:
            DesplegarMenuCola();
    }
}while(seleccion!=0);
}

int main()
{
      /* Cola cola;
      cola.Crear();
      cola.Encolar(8);
      cola.Desencolar();*/
      menu();





    cout<<"hola";
    return 0;
}
