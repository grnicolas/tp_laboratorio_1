#include "LinkedList.h"

/** Obtiene un nodo de la lista */
static Node* getNode(LinkedList* this, int nodeIndex);

/** Agrega y enlaza un nuevo nodo a la lista */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=(LinkedList*) malloc(sizeof(LinkedList));
    if(this==NULL)
    {
        printf("error");
    }
    else
    {
        this->size=0;
        this->pFirstNode=NULL;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo=NULL;
    int len=ll_len(this);

    if(this!=NULL && nodeIndex>=0 && nodeIndex<len)
    {
        nodo=this->pFirstNode;

        while(nodeIndex>0)
        {
            nodo=nodo->pNextNode;
            nodeIndex--;
        }
    }

    return nodo;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    Node* anterior=NULL;
    Node* siguiente=NULL;
    Node* nodo;

    int contador=1;

    if(this!=NULL && nodeIndex>=0 &&  nodeIndex<=len)
    {
        nodo=(Node*) malloc(sizeof(Node));

        if(nodo!=NULL)
        {
            nodo->pElement=(Node*) pElement;
            nodo->pNextNode=NULL;

            if(nodeIndex==0)
            {
                nodo->pNextNode=this->pFirstNode;
                this->pFirstNode=nodo;
            }
            else
            {
                anterior=this->pFirstNode;
                siguiente=anterior->pNextNode;

                while(nodeIndex>contador)
                {
                    anterior=siguiente;
                    siguiente=anterior->pNextNode;
                    contador++;
                }

                anterior->pNextNode=nodo;
                nodo->pNextNode=siguiente;
            }

            this->size++;
            returnAux=0;
        }
    }

    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL)
    {
        if(addNode(this,len,pElement)==0)
        {
            returnAux=0;
        }
    }

    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    Node* nodo=NULL;
    if(this!=NULL && index>=0 && index<=len)
    {
        nodo=getNode(this,index);

        if(nodo!=NULL)
        {
            return nodo->pElement;
        }
    }

    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodo=NULL;

    int len=ll_len(this);

    if(this!=NULL && index>=0 && index<=len)
    {
        nodo=getNode(this,index);

        if(nodo!=NULL)
        {
            nodo->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* nodo=NULL;
    Node* nodoAnterior=NULL;
    Node* nodoSiguiente=NULL;

    if(this!=NULL && index>=0 && index<=len)
    {
        nodo=getNode(this,index);

        if(nodo!=NULL)
        {
            if(index==0)
            {
                this->pFirstNode=nodo->pNextNode;
                free(nodo);
                this->size--;
                returnAux=0;
            }
            else
            {
                nodoAnterior=getNode(this,index-1);
                nodoSiguiente=getNode(this,index+1);

                nodoAnterior->pNextNode=nodoSiguiente;
                free(nodo);
                (this->size)--;

                returnAux=0;
            }
        }
    }

    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        this->size=0;
        this->pFirstNode=NULL;

        returnAux=0;
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this);
        returnAux=0;
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodo=NULL;
    int len=ll_len(this);
    int i;

    if(this!=NULL)
    {
        for(i=0; i<len; i++)
        {
            nodo=getNode(this,i);

            if(nodo->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size==0)
        {
            returnAux=1;
        }
        if(this->size>0)
        {
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL && index>=0 && index<=len)
    {
        returnAux=addNode(this,index,pElement);
    }

    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    //Node* nodoRetorno=NULL;

    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        if(index>=0 && index<=len)
        {
            returnAux=ll_get(this,index);
            ll_remove(this,index);
        }
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len1=ll_len(this);
    int len2=ll_len(this2);
    Node* auxNode=NULL;
    int i;

    if(this !=NULL && this2!=NULL)
    {
        returnAux=0;
        if(len1>=len2)
        {
            for(i=0; i<len2; i++)
            {
                auxNode=getNode(this,i);

                if(ll_contains(this2,auxNode->pElement)==1)
                {
                    returnAux=1;
                }
            }
        }
        //returnAux=0;
    }

    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode=NULL;

    int i;

    int len=ll_len(this);

    if(this!=NULL && (from>=0 && from<=len) && (to>=from && to<=len) )
    {
        cloneArray=ll_newLinkedList();

        if(cloneArray!=NULL)
        {
            for(i=0; i<len; i++)
            {
                auxNode=getNode(this,i);

                if(auxNode!=NULL)
                {
                    addNode(cloneArray,i,auxNode->pElement);
                }
            }
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int len=ll_len(this);


    if(this!=NULL)
    {
        cloneArray=ll_subList(this,0,len);
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int len=ll_len(this);
    void* aux;
    int i,j;

    if(this!=NULL && pFunc!=NULL)
    {

        for(i=0; i<len-1; i++)
        {

            for(j=i+1; j<len; j++)
            {

                if(pFunc(ll_get(this,i),ll_get(this,j))<0 && order ==0)
                {
                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);
                    returnAux=0;

                }
                else if(pFunc(ll_get(this,i),ll_get(this,j))>0 && order ==1)
                {
                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);
                    returnAux=0;

                }
            }
        }
    }

    return returnAux;
}
