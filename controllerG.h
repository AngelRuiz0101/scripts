#include <iostream>
using namespace std;

int secuenciaFibonacci(int posicion){
    int aux1 = 0, aux2 = 1, resultado_fib;

    if(posicion == 1){
        return aux1;
        }

    else if(posicion == 2){
        return aux2;
        }

    else{
        for(int i = 3; i <= posicion; i++){
            resultado_fib = aux1 + aux2;
            aux1 = aux2;
            aux2 = resultado_fib;
    }
    return resultado_fib;
    }
}