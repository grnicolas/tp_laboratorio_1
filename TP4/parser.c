#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int validation=0;
    char buffer[4][40];
    int max;
    Employee* auxEmployee=NULL;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {
        max=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(max<4)
        {
            break;
        }
        auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

        if(auxEmployee!=NULL)
        {
            ll_add(pArrayListEmployee,auxEmployee);
            validation=1;
        }
    }
    return validation;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int validation=0;
    int max;
    Employee* employee;

        while(!feof(pFile))
        {
             employee = employee_new();

            if(employee !=NULL)
            {
                max = fread(employee,sizeof(Employee),1,pFile);

                    if(max <1)
                    {
                        break;
                    }
                    else
                    {
                        ll_add(pArrayListEmployee,employee);
                        validation=1;
                    }
            }
        }

    return validation;
}
