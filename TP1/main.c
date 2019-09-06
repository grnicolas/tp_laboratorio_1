#include "cabecera.h"

int main()
{
    hello();

    float op1, op2;
    int menu;
    float resultado;

    do {

        printf("\nINGRESAR PRIMERO OPERADOR: ");
        scanf("%d",&op1);
        printf("\nINGRESAR SEGUNDO OPERADOR: ");
        scanf("%d",&op2);

        mostrar_menu();
        scanf("%d",&menu);

        switch(menu){

        case 0:
            printf("\nFIN DEL PROGRAMA");
            break;
        case 1:
            resultado = calcular_suma(op1,op2);
            printf("\n“El resultado de A+B es: %f",resultado);
            break;
        case 2:
            resultado = calcular_resta(op1,op2);
            printf("\n““El resultado de A-B es: %f",resultado);
            break;
        case 3:
            if (op2 != 0){
                resultado = calcular_division(op1,op2);
                printf("\nEl resultado de A/B es: %f",resultado);
            } else {
                printf("\nNo es posible dividir por cero");
            }
            break;
        case 4:
            resultado = calcular_multiplicacion(op1,op2);
            printf("\n“El resultado de A*B es: %f",resultado);
            break;
        case 5:
            printf("\n“El factorial de A es: %f y El factorial de B es: %f",calcular_factorial(op1),calcular_factorial(op2));
            break;
        }

    } while(menu > 0 && menu <= 5);

    return 0;
}
