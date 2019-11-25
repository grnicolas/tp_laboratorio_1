#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "control.h"

/** Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto). */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario). */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
