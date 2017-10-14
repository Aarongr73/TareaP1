#ifndef LISTACOLA_H
#define LISTACOLA_H
 #define MAX 1000



template <typename DataType>class ListaCola
{
private:
   DataType Arreglo[MAX];
   int ultimo;
   int numelem;

public:
   ListaCola()

   {
       ultimo=0;

   }
   ~ListaCola(){

   }

   void Agregar(DataType nodo){
       Arreglo[ultimo]=nodo;
       ++ultimo;
       ++numelem;
   }
   DataType Siguiente(int pos){
       return Arreglo[pos+1];
   }
   DataType Recuperar(int pos){
       return Arreglo[pos];
   }
   int NumElem(){
       return numelem;
   }

};

#endif // LISTACOLA_H
