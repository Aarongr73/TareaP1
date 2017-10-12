#include "Cola.h"
#include<iostream>

using namespace std;

void Cola::Crear(){
    salida = &vec_circ[0];
    entrada = salida;
    numElem = 0;
}

void Cola::Destruir(){

}

void Cola::Vaciar(){
    salida = &vec_circ[0];
    entrada = salida;
    numElem = 0;
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
    if(*salida > MAX-1){
        salida = 0;
    }else{
        salida++;
    }
    numElem--;
    return elemento;
}

void Cola::Encolar(int elemento){
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

int Cola::Frente(){
    return *salida;
}
