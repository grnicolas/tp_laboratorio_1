#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include "control.h"

/** Solicita un número al usuario y lo valida */
int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);

/** Solicita un número (flotante) al usuario y lo valida */
float getFloat(float *pResultado,char *pMensaje, char *pMensajeError, float minimo, float maximo, int reintentos);

/** Solicita un caracter al usuario y lo valida */
int getChar( char *pResultado, char *pMensaje, char *pMensajeError, char minimo, char maximo, int reintentos);

/** Solicita una cadena de caracteres al usuario y lo valida */
int getString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);

/** */
int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfanumerico(char str[]);
int esSoloLetras(char str[]);

/** */
int getPhone(char *pResultado,char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);

/** */
int getNameOrLastName(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);

#endif // UTN_H_INCLUDED
