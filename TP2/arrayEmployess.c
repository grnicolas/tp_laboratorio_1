#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "arrayEmployess.h"
#include "validaciones.h"
#define EMPTY 1
#define OCCUPIED 0


int initEmployees(Employee* employees, int lengthEmp)
{

    int i;

    for(i=0; i<lengthEmp; i++)
    {
        employees[i].isEmpty=EMPTY;
    }
    return 0;
}

int mainMenu()
{
    int option;
    char auxOption[3];

    system("cls");
    printf("MENU\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificacion empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n\n");
    printf("Ingrese option: ");
    scanf("%s",auxOption);

    if(isInt(auxOption)==0)
    {
        printf("->Solo numeros<-");
        system("pause");
    }
    else
    {
        option=atoi(auxOption);
    }

    return option;
}

int addEmployee(Employee* employees, int lengthEmp, int id, char name[],char lastName[],float salary,int sector)
{
    int validation=0;
    int index;

    index=findEmptyIndex(employees,lengthEmp);

    employees[index].id=id;
    strcpy(employees[index].name,name);
    strcpy(employees[index].lastName,lastName);
    employees[index].salary=salary;
    employees[index].sector=sector;
    employees[index].isEmpty=OCCUPIED;

    system("cls");
    printf("*** EMPLEADO A DAR DE ALTA ***\n\n");
    printf("%8s %12s %12s %12s %12s\n", "Legajo", "Sector", "Nombre", "Apellido", "Sueldo");
    printEmployee(employees[index]);

    printf("\nAlta efectuada\n\n");

    return validation;
}

int getRandomId(Employee* employees, int lengthEmp, int* requestedRandomId)
{
    int firstRandomId=1000;
    int index;
    int validation=-1;

    index=findEmptyIndex(employees,lengthEmp);

    if(index>=0)
    {
        *requestedRandomId=firstRandomId+index;
        validation=0;
    }
    return validation;
}

int findEmptyIndex(Employee* employees, int lengthEmp)
{
    int index=-1;
    int i;
    for(i=0; i<lengthEmp; i++)
    {
        if(employees[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int findEmployeeById(Employee* employees, int lengthEmp,int id)
{
    int index=-1;
    int i;
    for(i=0; i<lengthEmp; i++)
    {
        if(employees[i].id==id)
        {
            index=i;
        }
    }
    return index;
}

int removeEmployee(Employee* employees, int lengthEmp)
{
    int idEmployee;
    int validation=0;
    int index;
    char confirm;

    printEmployees(employees,lengthEmp);
    printf("Ingrese legajo del empleado a eliminar: ");
    scanf("%d",&idEmployee);

    index=findEmployeeById(employees,lengthEmp,idEmployee);

    if(index==-1)
    {
        printf("No se ha encontrado al empleado\n");
        system("pause");
        validation=-1;
    }
    else
    {
        system("cls");
        printf("*** EMPLEADO A ELIMINAR ***\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Legajo", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);
        printf("Confirma eliminacion?\n");
        fflush(stdin);
        printf("Ingrese s/n: ");
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            employees[index].isEmpty=EMPTY;
            validation=0;
            printf("\nBaja efectuada\n\n");
        }
        else
        {
            validation=-1;
        }
    }
    return validation;
}

int modifyMenu()
{
    int option;

    system("cls");
    printf("Que desea modificar?\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");

    printf("Ingrese opcion: ");
    scanf("%d",&option);

    return option;
}

int modifyEmployee(Employee* employees, int lengthEmp)
{
    int validation=0;
    int index;
    int option;
    int idEmployee;

    printEmployees(employees,lengthEmp);
    printf("Ingrese legajo del empleado a modificar: ");
    scanf("%d",&idEmployee);

    index=findEmployeeById(employees,lengthEmp,idEmployee);

    if(index==-1)
    {
        printf("No se ha encontrado al empleado\n");
        validation=-1;
    }
    else
    {
        option=modifyMenu();

        switch(option)
        {
        case 1:
            modifyNameEmployee(employees,lengthEmp,index);
            break;
        case 2:
            modifyLastNameEmployee(employees,lengthEmp,index);
            break;
        case 3:
            modifySalaryEmployee(employees,lengthEmp,index);
            break;
        case 4:
            modifySectorEmployee(employees,lengthEmp,index);
            break;
        default:
            printf("Opcion Invalida\n");
            break;
        }
    }
    return validation;
}

int modifyNameEmployee(Employee* employees, int lengthEmp, int index)
{
    char auxName[51];
    char confirm;
    int validation;

    validation=getString(auxName,"Ingrese el NUEVO nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation==1)
    {
        system("cls");

        printf("EMPLEADO A MODIFICAR\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Legajo", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);

        printf("Confirma NUEVO nombre: %s? s/n\n",auxName);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            strcpy(employees[index].name,auxName);
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }
    return validation;
}

int modifyLastNameEmployee(Employee* employees, int lengthEmp, int index)
{
    char auxLastName[51];
    char confirm;
    int validation;

    validation=getString(auxLastName,"Ingrese el NUEVO apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation==1)
    {
        system("cls");

        printf("EMPLEADO A MODIFICAR\n\n");
        printf("6%8s %12s %12s %12s %12s\n", "Legajo", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);

        printf("Confirma NUEVO apellido: %s? s/n\n",auxLastName);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            strcpy(employees[index].lastName,auxLastName);
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }

    return validation;
}

int modifySalaryEmployee(Employee* employees, int lengthEmp, int index)
{
    float auxSalary;
    int validation;
    char confirm;

    validation=getFloat(&auxSalary,"Ingrese el NUEVO salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,100000);

    if(validation==1)
    {
        system("cls");

        printf("EMPLEADO A MODIFICAR\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Legajo", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);

        printf("Confirma NUEVO salario: %.2f? s/n\n",auxSalary);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            employees[index].salary=auxSalary;
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }

    return validation;
}

int modifySectorEmployee(Employee* employees, int lengthEmp, int index)
{
    int auxIdSector=0;
    int validation;
    char confirm;


    validation=getInt(&auxIdSector,"Elija el Nuevo sector del empleado","Opcion invalida, rango [0-5]",0,5);

    if(validation==1)
    {
        system("cls");

        printf("EMPLEADO A MODIFICAR\n\n");
        printf("%8s %12s %12s %12s %12s\n", "Legajo", "Sector", "Apellido", "Nombre", "Sueldo");
        printEmployee(employees[index]);

        printf("AUXILIAR SECTORS ID(recibo): %d\n\n",auxIdSector);
        printf("Confirma NUEVO sector ?:s/n\n");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            employees[index].sector=auxIdSector;
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }
    return validation;
}

int sortingMenu(Employee* employees, int lengthEmp)
{
    int order;

    system("cls");
    printf("Ordenar [A-Z] o [Z-A]\n");
    printf("1- [A-Z]\n");
    printf("2- [Z-A]\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    sortEmployeesByName(employees,lengthEmp,order);

    return order;
}

int sortEmployeesByName(Employee* employees, int lengthEmp, int order)
{
    int sortingOk=0;
    int i, j;
    for(i=0; i<lengthEmp-1; i++)
    {
        for(j=i+1; j<lengthEmp; j++)
        {
            if(employees[i].isEmpty==OCCUPIED)
            {
                if(order==1)
                {
                    if(employees[i].sector>employees[j].sector)
                    {
                        bubbleSorting(employees,lengthEmp,i,j);
                    }
                    else
                    {
                        if((employees[i].sector==employees[j].sector)&&(strcmp(employees[i].name,employees[j].name)>0))
                        {
                            bubbleSorting(employees,lengthEmp,i,j);
                        }
                    }
                }
                else if(order==2)
                {
                    if(employees[i].sector<employees[j].sector)
                    {
                        bubbleSorting(employees,lengthEmp,i,j);
                    }
                    else
                    {
                        if((employees[i].sector==employees[j].sector)&&(strcmp(employees[i].name,employees[j].name)<0))
                        {
                            bubbleSorting(employees,lengthEmp,i,j);
                        }
                    }
                }
            }
        }
    }

    return sortingOk;
}

void bubbleSorting(Employee* employees, int length, int i, int j)
{
    Employee auxEmp;

    auxEmp=employees[i];
    employees[i]=employees[j];
    employees[j]=auxEmp;
}

int printEmployees(Employee* employees, int lengthEmp)
{

    int i;

    system("cls");
    printf("EMPLEADOS ACTIVOS\n\n");
    printf("%8s %12s %12s %12s %12s\n", "Legajo", "Sector", "Nombre", "Apellido", "Sueldo");

    for(i=0; i<lengthEmp; i++)
    {
        if(employees[i].isEmpty==OCCUPIED)
        {
            printEmployee(employees[i]);
        }
    }
    return 0;
}

int printEmployee(Employee employee)
{

    printf("%8d %12d %12s %12s %12.2f\n", employee.id,employee.sector,employee.name,employee.lastName,employee.salary);

    return 0;
}

int reportsMenu()
{
    int option;

    system("cls");
    printf("->MENU<- \n\n");
    printf("1- Lista de empleados por orden alfabetico\n");
    printf("2- Lista de total y promedio de salarios\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&option);

    return option;
}

int reports(Employee* employees, int lengthEmp)
{

    int validation=0;

    switch(reportsMenu())
    {
    case 1:
        sortingMenu(employees,lengthEmp);
        printf("EMPLEADOS ORDENADOS ALFABETICAMENTE\n\n");
        printEmployees(employees,lengthEmp);
        break;
    case 2:
        reportsSalary(employees,lengthEmp);
        break;
    default:
        printf("Opcion invalida");
        system("pause");
        validation=-1;
        break;
    }
    return validation;
}

void reportsSalary(Employee* employees, int lengthEmp)
{
    int i;
    float averageSalary=0;
    float accumulateSalary=0;
    int countAverage=0;
    int countEmployees=0;

    for(i=0; i<lengthEmp; i++)
    {
        if(employees[i].isEmpty==OCCUPIED)
        {
            accumulateSalary+=employees[i].salary;
            countEmployees++;
        }
    }

    averageSalary=accumulateSalary/countEmployees;

    for(i=0; i<lengthEmp; i++)
    {
        if(employees[i].isEmpty==OCCUPIED)
        {
            if(employees[i].salary>averageSalary)
            {
                countAverage++;
            }
        }
    }

    system("cls");
    printf("->INFORME<-\n\n");
    printf("TOTAL sueldos: %.2f\n\n",accumulateSalary);
    printf("PROMEDIO sueldos: %.2f\n\n",averageSalary);
    printf("Cant. Emp. que superan el promedio: %d\n\n",countAverage);
}
