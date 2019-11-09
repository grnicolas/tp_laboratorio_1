#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pEmployee;
    Employee empl;

    pEmployee=fopen(path,"rt");

     while(!feof(pEmployee))
    {
        //trozarCamposVariable(&linea,&notas);
        //fread(&empl,sizeof(Employee),1,Employee);
        //pArrayListEmployee
    }

    return 1;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    while(pArrayListEmployee->pFirstNode != NULL)
    {

    }

    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* arch_txt;
    arch_txt = fopen(path,"wt");

    while(pArrayListEmployee->pFirstNode != NULL)
    {

        fprintf(arch_txt,"",);
    }

    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

