#include <iostream>
//#include "ArbolLista.h"
//#include "hijomasizquierdo.h"
//#include "hijomasizq3.h"
//#include "hijomasizq2.h"
#include "algoritmos2.h"
#include "Cola.h"
#include "arreglopuntp.h"
using namespace std;


void DesplegarMenuArbol(Arbol& arbol){
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
void menuAlgoritmos(Arbol& arbol,Arbol& arbol2){
    int seleccion;
    Algoritmos algoritmos;
    do{
       cout<<"\nSeleccion alguna de las siguientes opciones:\n"
             "(1)Listado en Pre Orden\n"
             "(2)Listado en Post Orden\n"
             "(3)Listado por Niveles\n"
             "(4)Iguales?\n"
             "(5)Buscar etiqueta\n"
             "(6)Profundidad\n"
             "(7)Numero de niveles en Pre Orden\n"
             "(8)Numero de niveles en recorrido por niveles\n"
             "(9))Listado de Hijos\n"
             "(10)Hermano Izquierdo\n"
             "(11)Listar Iesimo nivel\n"
             "(12)Hay repetidos?\n"
             "(13)Eliminar un sub Arbol\n"
             "(14)Copiar el arbol actual\n"
             "(0)SALIR\n";
       cin>>seleccion;
       switch(seleccion){
       case 1:
           algoritmos.ListPre(arbol);
           break;
       case 2:
           algoritmos.ListPost(arbol);
           break;
       case 3:
           algoritmos.ListadoPN(arbol);
           break;
       case 4:
       {
           bool iwales=algoritmos.Iguales(arbol,arbol2);
           if(iwales)
               cout<<"Son iguales\n";
           else
               cout<<"No son iguales\n";
       }
           break;
       case 5:
       {
           int etiqueta;
           cout<<"Introduzca la etiqueta a buscar\n";
           cin>>etiqueta;
           bool found=algoritmos.Busqueda(arbol,etiqueta);
           if(found)
               cout<<"encontrado!\n";
           else
               cout<<"no encontrado!\n";
       }
           break;
       case 6:
       {
           int prof;
           int etiqueta;
           cout<<"Introduzca la etiqueta a buscar";
           cin>>etiqueta;
           prof=algoritmos.Profundidad(arbol.Buscar(etiqueta),arbol);
           cout<<"La profundidad del nodo es de : "<<prof<<endl;
       }

           break;
       case 7:
       {
           int niveles=algoritmos.NumNiveles(arbol);
           cout<<"El numeros de niveles es: "<<niveles<<endl;
       }
           break;
       case 8:
       {
           int niveles=algoritmos.NumnNiveles(arbol);
           cout<<"El numeros de niveles es: "<<niveles<<endl;
       }
           break;
       case 9:
       {
           int padre;
           cout<<"Introduzca la etiqueta del padre\n";
           cin>>padre;
           algoritmos.ListadoHijos(arbol,arbol.Buscar(padre));
       }
           break;
       case 10:
       {
           int hermano;
           NodoPrincipal HI;
           cout<<"Introduzca la etiqueta del hermano\n";
           cin>>hermano;
           HI=algoritmos.AveriguarHI(arbol,arbol.Buscar(hermano));
           cout<<arbol.Etiqueta(HI)<<"es el hermano izquierdo de "<< hermano<<endl;
       }
           break;
       case 11:
       {
           int nivel;
           cout<<"selecciones el nivel a buscar\n";
           cin>>nivel;
           algoritmos.ListarIesimo(arbol,nivel);
       }
           break;
       case 12:
       {
           bool repetidos=algoritmos.Repetidos(arbol);
           if(repetidos)
               cout<<"HAY REPETIDOS!\N";
           else
               cout<<"NO HAY REPETIDOS\N";
       }
           break;
       case 13:
       {
           int raiz;
           cout<<"Seleccione el nodo donde comienza el sub arbol a borrar\n";
           cin>>raiz;
           algoritmos.BorrarSubArbol(arbol.Buscar(raiz),arbol);
       }
           break;
       case 14:
       {
           Arbol copia;
           copia.Crear();
           algoritmos.Copiar(arbol,copia);
       }

           break;
       default:
           break;

       }
    }while(seleccion!=0);


}

void menu(Arbol &arbol,Arbol& arbol2){
int seleccion;
do{
    cout<<"Puede seleccionar entre Arbol(1) "
          "Algoritmos(2) (0)Salir\n";
    cin>>seleccion;

    switch(seleccion){
    case 0:
            cout<<"SALIENDO\n";
        break;
   case 1:
            DesplegarMenuArbol(arbol);
        break;
    case 2:
        menuAlgoritmos(arbol,arbol2);
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
        Arbol arbolP2;
        Arbol arbol2; //Copia de cualquiera de los árboles
        Algoritmos alg;
       // NodoPrincipal x;
        arbol.PonerRaiz(1);
        arbol.AgregarHijoI_esimo(arbol.Buscar(1), 5, 1);
        arbol.AgregarHijoI_esimo(arbol.Buscar(5), 8, 1);
        arbol.AgregarHijoI_esimo(arbol.Buscar(5), 2, 2);
        arbol.AgregarHijoI_esimo(arbol.Buscar(5), 3, 3);
        arbol.AgregarHijoI_esimo(arbol.Buscar(2), 0, 1);
        arbol.AgregarHijoI_esimo(arbol.Buscar(3), 11, 1);
        arbol.AgregarHijoI_esimo(arbol.Buscar(3), 9, 2);

        arbolP2.PonerRaiz(2);
        arbolP2.AgregarHijoI_esimo(arbolP2.Buscar(2), 3, 1);
        arbolP2.AgregarHijoI_esimo(arbolP2.Buscar(3), 7, 1);
        arbolP2.AgregarHijoI_esimo(arbolP2.Buscar(3), 1, 2);
        arbolP2.AgregarHijoI_esimo(arbolP2.Buscar(3), 5, 3);
        arbolP2.AgregarHijoI_esimo(arbolP2.Buscar(1), 11, 1);
        arbolP2.AgregarHijoI_esimo(arbolP2.Buscar(5), 10, 1);
        arbolP2.AgregarHijoI_esimo(arbolP2.Buscar(5), 9, 2);

        menu(arbol,arbolP2);












    return 0;
}
