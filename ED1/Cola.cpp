#include "Cola.h"
#include<iostream>

using namespace std;

void Cola::Crear(){
    salida = &vec_circ[0];
    entrada = salida;
}

void Cola::Destruir(){

}

void Cola::Vaciar(){
    salida = &vec_circ[0];
    entrada = salida;
}

bool Cola::Vacia(){
    if(salida == entrada){
        return true;
    }else{
        return false;
    }
}

int Cola::Desencolar(){
    if(entrada == salida){
        cout<<"Pila vacia."<<endl;
    }
    elemento = *salida;
    ++salida;
    return elemento;
}

void Cola::Encolar(int elemento){
    if(salida == entrada+1){
        cout<<"Pila llena."<<endl;
        return;
    }
    *entrada = elemento;
    ++entrada;
}

int Cola::Frente(){
    return *salida;
}
