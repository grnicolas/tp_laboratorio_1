#include "control.h"

#include "LinkedList.h"
#include "controller.h"

int main()
{
    //mostrarMenu();

    //LinkedList* lista = ll_newLinkedList();
    /// TP3

    int banSAVE=0;
    int banTXT=0, banBIN=0;
    LinkedList* employeeList = ll_newLinkedList();

    int option = 0;
    //LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        mostrarMenu();

        ///OPTION
        printf("\n Ingrese Opcion: ");
        scanf("%d",&option);

        switch(option)
        {
            case 0:
                printf("\n0.");
                ///TEST LINKED_LIST
                test_linked_list();
                break;
            case 1:
                printf("\n1.");
                ///controller_loadFromText("data.csv",listaEmpleados);

                if(banTXT == 1) {
                    printf("\nERROR_DATOS CARGADOS");
                    break;
                }

                if(controller_loadFromText("data.csv",employeeList) == 1)
                {
                    printf("\nDATOS_CARGADOS");
                    banTXT = 1;
                } else {
                    printf("ERROR_1\n");
                }
                break;
            case 2:
                printf("\n2.");
                ///controller_loadFromBinary("data.bin",listaEmpleados);

                if(banBIN == 1) {
                    printf("\nERROR_DATOS CARGADOS");
                    break;
                }

                if(controller_loadFromBinary("data.bin",employeeList) == 1)
                {
                    printf("\nDATOS_CARGADOS");
                    banBIN = 1;
                } else {
                    printf("ERROR_2\n");
                }
                break;
            case 3:
                printf("\n3.");
                ///controller_addEmployee(listaEmpleados);
                if(controller_addEmployee(employeeList))
                {
                    banBIN = 1;
                    //banTXT = 1;
                    banSAVE = 1;
                }
                break;
            case 4:
                printf("\n4.");
                ///controller_editEmployee(listaEmpleados);
                controller_editEmployee(employeeList);
                banSAVE = 1;
                break;
            case 5:
                printf("\n5.");
                ///controller_removeEmployee(listaEmpleados);
                controller_removeEmployee(employeeList);
                banSAVE = 1;
                break;
            case 6:
                printf("\n6.");
                ///controller_ListEmployee(listaEmpleados);
                controller_ListEmployee(employeeList);
                banSAVE = 1;
                break;
            case 7:
                printf("\n7.");
                ///controller_sortEmployee(listaEmpleados);
                if(controller_sortEmployee(employeeList))
                {
                    banSAVE = 1;
                    printf("\nOK_7");
                }
                break;
            case 8:
                printf("\n8.");
                ///controller_saveAsText("data2.csv",listaEmpleados);

                if(banSAVE == 0) {
                    printf("\nERROR_NO_INGRESADOS");
                    break;
                }

                if(controller_saveAsText("data.csv",employeeList); == 1)
                {
                    printf("\nOK_8");
                } else {
                    printf("ERROR_8\n");
                }
                break;
            case 9:
                printf("\n9.");
                ///controller_saveAsBinary("data.bin",listaEmpleados);

                if(banSAVE == 0) {
                    printf("\nERROR_NO_INGRESADOS");
                    break;
                }

                if(controller_saveAsBinary("data.bin",employeeList) == 1)
                {
                    printf("\nOK_9");
                } else {
                    printf("\nERROR_9");
                }
                break;
            case 10:
                printf("\nFIN DEL PROGRAMA.");
                break;
            default:
                printf("\nERROR - [Ingrese un numero entre 0 y 10]");
                break;
        }
    }while(option != 10);


    /// TEST
/*


*/


    return 0;
}
