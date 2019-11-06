#include "cabecera.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        mostrarMenu();

        ///OPTION
        printf("\n Ingrese Opcion: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                printf("\n1.");
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                printf("\n2.");
                controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 3:
                printf("\n3.");
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                printf("\n4.");
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                printf("\n5.");
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                printf("\n6.");
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                printf("\n7.");
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                printf("\n8.");
                controller_saveAsText("data2.csv",listaEmpleados);
                break;
            case 9:
                printf("\n9.");
                break;
            case 10:
                printf("\nFIN DEL PROGRAMA.");
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
            default:
                printf("\nERROR - [Ingrese un numero entre 1 y 10]");
                break;
        }
    }while(option != 10);
    return 0;
}
