#include"utn.h"

int getInt(int *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    int buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%d",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = 0;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;
}

float getFloat(float *pResultado,
          char *pMensaje,
          char *pMensajeError,
          float minimo,
          float maximo,
          int reintentos)
{
    int retorno = -1;
    float buffer;

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%f",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = EXIT_SUCCESS;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >= 0);

    }
    return retorno;
}

int getChar(  char *pResultado,
			  char *pMensaje,
			  char *pMensajeError,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);
			if(scanf("%c",&buffer)==1)
			{
				if(buffer == 'f' || buffer == 'm')
				{
					retorno = 0;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int getString(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
       {
           do
           {
               printf("%s",pMensaje);
               fflush(stdin);
               fgets(buffer,sizeof(buffer),stdin);

               buffer[strlen(buffer)-1] = '\0';
               if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
               {
                   strncpy(pResultado,buffer,maximo+1);
                   retorno = 0;
                   break;
               }

               printf("%s",pMensajeError);
               reintentos--;

           }while(reintentos >=0);
       }
    return retorno;
}

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9');
        return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
           &&(str[i] < 'a' || str[i] > 'z')
           &&(str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esAlfanumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
           &&(str[i] < 'a' || str[i] > 'z')
           &&(str[i] < 'A' || str[i] > 'Z')
           &&(str[i] < '0' || str[i] > '9'))
           return 0;
        i++;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i = 0;
    int contadorDeGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
           &&(str[i] != '-')
           &&(str[i] < '0' || str[i] > '9'))
           return 0;
        if(str[i] == '-')
            contadorDeGuiones ++;
        i++;
    }
    return 1;
}

int getPhone(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
       {
           do
           {
               printf("%s",pMensaje);
               fflush(stdin);
               fgets(buffer,sizeof(buffer),stdin);

               buffer[strlen(buffer)-1] = '\0';
               if(strlen(buffer)>=minimo && strlen(buffer)<=maximo )
               {
                   if(esNumerico(buffer)!=1)
                   {
                   strncpy(pResultado,buffer,maximo+1);
                   retorno = 0;
                   break;
                   }
               }

               printf("%s",pMensajeError);
               reintentos--;

           }while(reintentos >=0);
       }
    return retorno;
}

int getNameOrLastName(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos)
{
    int retorno = -1;
    char buffer[500];

    if(pResultado != NULL &&
       pMensaje != NULL &&
       pMensajeError != NULL &&
       minimo < maximo &&
       reintentos >=0)
       {
           do
           {
               printf("%s",pMensaje);
               fflush(stdin);
               fgets(buffer,sizeof(buffer),stdin);

               buffer[strlen(buffer)-1] = '\0';
               if(strlen(buffer)>=minimo && strlen(buffer)<=maximo )
               {
                   if(esSoloLetras(buffer)==1)
                   {
                   strncpy(pResultado,buffer,maximo+1);
                   retorno = 0;
                   break;
                   }
               }

               printf("%s",pMensajeError);
               reintentos--;

           }while(reintentos >=0);
       }
    return retorno;
}
