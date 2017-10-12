#ifndef COLA_ED
#define COLA_ED
#define MAX 10
class Cola{

private:
    int vec_circ[MAX];
    int elemento;
    int* entrada;
    int* salida;
    int numElem;
public:
    void Crear();
    void Destruir();
    void Vaciar();
    bool Vacia();
    void Encolar(int);
    int Desencolar();
    int Frente();
};
#endif // COLA_E
