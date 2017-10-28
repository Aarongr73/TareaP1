#include <iostream>
#include<windows.h>
//#include "ArbolLista.h"
#include "hijomasizquierdo.h"
//#include "hijomasizq3.h"
//#include "hijomasizq2.h"
#include "algoritmos2.h"
#include "Cola.h"
//#include "arreglopuntp.h"

#include <time.h>
#include <stdio.h>
#include <chrono>


using namespace std;
using namespace std::chrono;

void ArbolVertical(long cant, Arbol& vertical){
    vertical.PonerRaiz(1);
    for(long i=2;i<cant;++i){
        vertical.AgregarHijoI_esimo(vertical.Buscar(i-1),i,1);
    }

}
void ArbolBalanceado(long cant, Arbol& balanceado){
  //  Arbol balanceado;
    //balanceado.Crear();
    balanceado.PonerRaiz(1);
    long i=1;
    long nodo=1;
    while(i<cant){
        cout<<nodo<<endl;
        i++;
        balanceado.AgregarHijoI_esimo(balanceado.Buscar(nodo),i,1);
        i++;
        balanceado.AgregarHijoI_esimo(balanceado.Buscar(nodo),i,2);
        ++nodo;
    }

}
void HijoDeRaiz(long cant, Arbol& HRaiz){
  //  Arbol HRaiz;
    //HRaiz.Crear();
    HRaiz.PonerRaiz(1);
    for(long i=2;i<cant;++i){
        cout<<i<<endl;
        HRaiz.AgregarHijoI_esimo(HRaiz.Buscar(1),i,1);
    }
}



void DesplegarMenuArbol(Arbol& arbol){
    long seleccion;

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
            long raiz;
            cout<<"longroduzca un valor para la raiz";
            cin>>raiz;
            arbol.PonerRaiz(raiz);
            cout<<"Agregada la raiz!\n";
        }
        break;
        case 2:
        {
            long etiquetaPadre;
            long etiquetaHijo;
            long pos;
            cout<<"longroduzca el la etiqueta de padre\n";
            cin>>etiquetaPadre;
            cout<<"longroduzca la etiqueta del hijo\n";
            cin>>etiquetaHijo;
            cout<<"seleccione donde\n";
            cin>>pos;
            arbol.AgregarHijoI_esimo(arbol.Buscar(etiquetaPadre),etiquetaHijo,pos);
        }
            break;
        case 3:
        {
            long nodoABorrar;
            cout<<"longrduzca la etiqueta de la hoja a borra\n";
            cin>>nodoABorrar;
            arbol.BorrarHoja(arbol.Buscar(nodoABorrar));
        }
        break;
        case 4:
        {
           long nodo;
           NodoPrincipal hmi;
           cout<<"longroduzca la etiqueta del nodo \n";
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
            long hizq;
            cout<<"longroduzca la etiqueta del nodo\n";
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
            long nodoHijo;
            cout<<"longroduzca la etiqueta del nodo hijo\n";
            cin>>nodoHijo;
            padre=arbol.Padre(arbol.Buscar(nodoHijo));
            cout<<"El padre de "<< nodoHijo+" es: ";
            arbol.MostrarEtiqueta(padre);
            cout<<"\n";
        }
        break;
        case 9:
         {
            long nuevaEtiqueta;
            long nodoActual;
            cout<<"longroduzaca la etiqueta del nodo a modificar\n";
            cin>>nodoActual;
            cout<<"longroduzca la nueva etiqueta\n";
            cin>> nuevaEtiqueta;
            arbol.ModificarEtiqueta(arbol.Buscar(nodoActual),nuevaEtiqueta);
        }
        break;
        case 10:
        {
            long numelem;
            numelem=arbol.NumElem();
            cout<<"La cantidad de elementos es de: "<<numelem<<"\n";
        }
        break;
        case 11:
        {
            long numhijos;
            long elpadre;
            cout<<"longroduzca la etiquta del nodo padre\n";
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
    long seleccion;
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
           long etiqueta;
           cout<<"longroduzca la etiqueta a buscar\n";
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
           long prof;
           long etiqueta;
           cout<<"longroduzca la etiqueta a buscar";
           cin>>etiqueta;
           prof=algoritmos.Profundidad(arbol.Buscar(etiqueta),arbol);
           cout<<"La profundidad del nodo es de : "<<prof<<endl;
       }

           break;
       case 7:
       {
           long niveles=algoritmos.NumNiveles(arbol);
           cout<<"El numeros de niveles es: "<<niveles<<endl;
       }
           break;
       case 8:
       {
           long niveles=algoritmos.NumnNiveles(arbol);
           cout<<"El numeros de niveles es: "<<niveles<<endl;
       }
           break;
       case 9:
       {
           long padre;
           cout<<"longroduzca la etiqueta del padre\n";
           cin>>padre;
           algoritmos.ListadoHijos(arbol,arbol.Buscar(padre));
       }
           break;
       case 10:
       {
           long hermano;
           NodoPrincipal HI;
           cout<<"longroduzca la etiqueta del hermano\n";
           cin>>hermano;
           HI=algoritmos.AveriguarHI(arbol,arbol.Buscar(hermano));
           cout<<arbol.Etiqueta(HI)<<"es el hermano izquierdo de "<< hermano<<endl;
       }
           break;
       case 11:
       {
           long nivel;
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
           long raiz;
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
long seleccion;
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
        Arbol arbol2;
        Arbol arbol3;
        //ArbolVertical(30000,arbol);
        ArbolBalanceado(30000,arbol2);
       // HijoDeRaiz(30000,arbol3);
        Algoritmos alg;

       /* clock_t start = clock();
        //arbol2.Padre(Nprueba);
     //   alg.Busqueda(arbol2, 99999);
          alg.Iguales(arbol2,arbol2);
   //     cout<<arbol2.Etiqueta(arbol2.Padre(arbol2.Buscar(99999)));
        clock_t stop = clock();
        double elapsed = ((double)(stop - start) / CLOCKS_PER_SEC);
       */// printf("Time elapsed in ms: %f", elapsed);
        NodoPrincipal nodo=arbol2.Buscar(29999);
        LARGE_INTEGER start, finish, freq;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&start);
        arbol2.Padre(nodo);
        QueryPerformanceCounter(&finish);
        std::cout << "Execution took "
            << ((finish.QuadPart - start.QuadPart) / (double)freq.QuadPart) << std::endl;










    return 0;
}
