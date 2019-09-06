#include "cabecera.h"

void hello(){
    printf("Hello");
}

void mostrar_menu(){

    printf("\nMENU\n"

    "\n0. Salir"
    "\n1. Calcular Suma"
    "\n2. Calcular Resta"
    "\n3. Calcular Division"
    "\n4. Calcular Multiplicacion"
    "\n5. Calcular Factorial");
}

float calcular_suma(op1,op2) {

    float res;
    return res = op1 + op2;
}

float calcular_resta(op1,op2) {

    float res;
    return res = op1 - op2;
}

float calcular_division(op1,op2) {

    float res;
    return res = op1 / op2;
}

float calcular_multiplicacion(op1,op2) {

    float res;
    return res = op1 * op2;
}

float calcular_factorial(n) {

    float res;
    int i;

    for (i = n; i >= 1; i--)
    {
        res = res*i;
    }

    return res;
}


/**
*   FUNCION QUE CALCULA Y MUESTRA LOS RESULTADOS DE LAS OPERACIONES MATEMATICAS
*/
void calcular_y_mostrar_resultados(op1,op2){
}
