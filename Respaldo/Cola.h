#ifndef COLA_ED
#define COLA_ED
#define MAX 10
#include <iostream>
using namespace std;
template <typename DataType> class Cola{

private:
    DataType vec_circ[MAX];
    DataType elemento;
    int* entrada;
    int* salida;
    int numElem;
public:
    void Crear(){
        salida = &vec_circ[0];
        entrada = salida;
        numElem = 0;
    }

    void Destruir(){

    }

    void Vaciar(){
        salida = &vec_circ[0];
        entrada = salida;
        numElem = 0;
    }

    bool Vacia(){
        if(salida == entrada){
            return true;
        }else{
            return false;
        }
    }

    DataType Desencolar(){
        if(entrada == salida){
            cout<<"Pila vacia."<<endl;
        }
        elemento = *salida;
        if(*salida > MAX-1){
            salida = 0;
        }else{
            salida++;
        }
        numElem--;
        return elemento;
    }

    void Encolar(int elemento){
        if(salida == entrada+1){
            cout<<"Pila llena."<<endl;
            return;
        }
        *entrada = elemento;
        if(*entrada > MAX-1){
            entrada = 0;
        }else{
            entrada++;
        }
        numElem++;
    }

    DataType Frente(){
        return *salida;
    }
};
#endif // COLA_E
