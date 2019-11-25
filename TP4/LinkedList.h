#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "control.h"

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;



/** Crea un nuevo LinkedList en memoria de manera dinamica */
LinkedList* ll_newLinkedList(void);

/** Retorna la cantidad de elementos de la lista */
int ll_len(LinkedList* this);

/** Permite realizar el test de la funcion getNode la cual es privada */
Node* test_getNode(LinkedList* this, int nodeIndex);

/** Permite realizar el test de la funcion addNode la cual es privada  */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** Agrega un elemento a la lista */
int ll_add(LinkedList* this, void* pElement);

/** Permite realizar el test de la funcion addNode la cual es privada */
void* ll_get(LinkedList* this, int index);

/** Modifica un elemento de la lista */
int ll_set(LinkedList* this, int index,void* pElement);

/** Elimina un elemento de la lista */
int ll_remove(LinkedList* this,int index);

/** Elimina todos los elementos de la lista */
int ll_clear(LinkedList* this);

/** Elimina todos los elementos de la lista y la lista */
int ll_deleteLinkedList(LinkedList* this);

/** Busca el indice de la primer ocurrencia del elemento pasado como parametro */
int ll_indexOf(LinkedList* this, void* pElement);

/** Indica si la lista esta o no vacia*/
int ll_isEmpty(LinkedList* this);

/** Insertar un nuevo elemento en la lista en la posicion indicada */
int ll_push(LinkedList* this, int index, void* pElement);

/** Elimina el elemento de la posicion indicada y retorna su puntero */
void* ll_pop(LinkedList* this,int index);

/** Determina si la lista contiene o no el elemento pasado como parametro */
int ll_contains(LinkedList* this, void* pElement);

/** Determina si todos los elementos de la lista */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/** Crea y retorna una nueva lista con los elementos indicados */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** Crea y retorna una lista con los elementos de la lista pasada como parametro */
LinkedList* ll_clone(LinkedList* this);

/** Ordena los elementos de la lista utilizando la funcion criterio recebida como parametro */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

#endif // LINKEDLIST_H_INCLUDED
