#ifndef COLA_ED
#define COLA_ED
#define MAX 100
#include <iostream>
using namespace std;
template <typename Datatype>
class Cola{
public:
    void Crear();
    void Destruir();
    void Vaciar();
    bool Vacia();
    void Encolar(const Datatype&);
    Datatype Desencolar();
    Datatype Frente();
private:
    Datatype vec_circ[MAX];
    Datatype elemento;
    Datatype* entrada;
    Datatype* salida;
    int numElem;
};
    template <typename Datatype>

    void Cola<Datatype>::Crear(){
        salida = &vec_circ[0];
        entrada = salida;
        numElem = 0;
    }
    template <typename Datatype>

    void Cola<Datatype>::Destruir(){

    }
    template <typename Datatype>

    void Cola<Datatype>::Vaciar(){
        salida = &vec_circ[0];
        entrada = salida;
        numElem = 0;
    }

    template <typename Datatype>

    bool Cola<Datatype>::Vacia(){
        if(numElem == 0){
            return true;
        }else{
            return false;
        }
    }

    template <typename Datatype>

    Datatype Cola<Datatype>::Desencolar(){
        if(numElem == 0){
            cout<<"Pila vacia."<<endl;
        }else{
            elemento = *salida;
            if(numElem > MAX-1){ //Si el dato que sale se va por un extremo hay que hacer que dé la vuelta.
                salida = 0;
            }else{
                salida++;
            }
            numElem--;
            return elemento;
            }
    }

    template <typename Datatype>

    void Cola<Datatype>::Encolar(const Datatype& elemento){
        if(numElem == MAX){
            cout<<"Pila llena."<<endl;
        }else{
            *entrada = elemento; //Si el dato que sale se va por un extremo hay que hacer que dé la vuelta.
            if(numElem > MAX-1){
                entrada = 0;
            }else{
                entrada++;
            }
            numElem++;
        }
    }
    template <typename Datatype>

    Datatype Cola<Datatype>::Frente(){
        return *salida;
    }

#endif // COLA_E
