#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode; //Por cada iteración, pNode se convierte en pNextNode, por lo que se va recorriendo la lista de nodos
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode)//corregido// Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev = NULL;
    Node* next = NULL; // No es necesario el malloc

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) //pElement PUEDE ser null, lo que no puede ser null es la lista//
    {
        int size = ll_len(this);
        Node* nuevoNodo = (Node*)malloc(sizeof(Node));//Se crea recién luego de verificar el if
        nuevoNodo->pElement = pElement;
        if(nodeIndex == 0) //Caso donde se quiere enganchar el nodo como primer elemento de la lista
        {
            this -> pFirstNode = nuevoNodo;
            if(size == 0) //Caso donde el nodo a enganchar es el primer elemento existente en la lista
            {
                nuevoNodo->pNextNode = NULL;
            }
            else //Caso donde la lista ya poseía nodos enganchados
            {
                next = getNode(this, nodeIndex+1);
                nuevoNodo->pNextNode = next;
            }
        }

        if(nodeIndex > 0) //Caso donde el nodo se quiere enganchar al medio o al final
        {
            next = getNode(this, nodeIndex+1);
            prev = getNode(this, nodeIndex-1);
            prev->pNextNode = nuevoNodo;
            if(nodeIndex == size) //Caso donde el nodo se engancha al final
            {
                nuevoNodo->pNextNode = NULL;
            }
            else //Caso donde el nodo se quiere enganchar al medio
            {
                nuevoNodo->pNextNode = next;
            }
        }
        returnAux = 0;
        this->size++;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size;
    if(this != NULL)
    {
        size = ll_len(this);
        addNode(this, size, pElement); //Al pasarle size, significa que estoy agregando el elemento en el último espacio
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoActual;
    if(this != NULL)
    {
        nodoActual = getNode(this, index);
        if(nodoActual != NULL)
        {
            returnAux = nodoActual->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoActual;
    if(this != NULL && ll_len(this) >= index && index >= 0)
    {
        nodoActual = getNode(this, index);
        if(nodoActual != NULL)
        {
            nodoActual->pElement = pElement;
            returnAux = 0;
        }

    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* prev;
    Node* nodoActual;
    Node* next;
    if(this != NULL && index >= 0 && ll_len(this) > index)
    {
        nodoActual = getNode(this, index);
        if(nodoActual != NULL)
        {
            next = getNode(this, index+1);
            if(next != NULL && index != 0)
            {
                prev = getNode(this, index-1);
                prev->pNextNode = next;

            }
            else
            {
                this->pFirstNode = next;

            }
            free(nodoActual);
        }
        returnAux = 0;
        this->size--;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int size;
    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0; i<size; i++)
        {
            ll_remove(this, i);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int size;
    if(this != NULL)
    {
        size = ll_len(this);
        for(i=0; i<size; i++)
        {
            if(ll_get(this, i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 1;
        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo;
    if(this != NULL && index >= 0 && ll_len(this) >= index)
    {
        nuevoNodo = addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/

// DOCUMENTACION DE INDEXOF* \return int Retorna  (-1) Error: si el puntero a la lista es NULL
//                        (indice del elemento) Si funciono correctamente

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this, pElement) >= 0) //Puedo usar el indexOf ya que si me devuelve -1, significa que no existe el elemento en la lista
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElementAuxiliar;
    int size1;
    int size2;
    if(this != NULL && this2 != NULL)
    {
        size1 = ll_len(this);
        size2 = ll_len(this2);
        returnAux = 0;
        if(size1 >= size2)
        {
            returnAux = 1;
            for(i=0; i<size2; i++)
            {
                pElementAuxiliar = ll_get(this2, i);
                if(ll_contains(this, pElementAuxiliar) == 0) //tiene que ser igual a 0, así una vez que encuentra uno que no esté contenido, corta el for y no sigue iterando
                {
                    returnAux = 0;
                    break;
                }
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int size = ll_len(this);
    if(this != NULL && from >= 0 && to > from && to <= size)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i=from; i<to; i++)
            {
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int size;
    if(this != NULL)
    {
        size = ll_len(this);
        cloneArray = ll_subList(this, 0, size);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    void* pAux;
    void* pPrimerElemento;
    void* pSegundoElemento;
    int i;
    int j;
    int size;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        size = ll_len(this);
        if(size > 0)
        {
            if(order == 1)
            {
                for(i=0; i<size-1; i++)
                {
                    for(j=i+1; j<size; j++)
                    {
                        pPrimerElemento = ll_get(this, i);
                        pSegundoElemento = ll_get(this, j);
                        if(pFunc(pPrimerElemento, pSegundoElemento) > 0)
                        {
                            pAux = pPrimerElemento;
                            ll_set(this, i, pSegundoElemento);
                            ll_set(this, j, pAux);
                        }
                    }
                }
            }
            else
            {
                for(i=0; i<size-1; i++)
                {
                    for(j=i+1; j<size; j++)
                    {
                        pPrimerElemento = ll_get(this, i);
                        pSegundoElemento = ll_get(this, j);
                        if(pFunc(pPrimerElemento, pSegundoElemento) < 0)
                        {
                            pAux = pPrimerElemento;
                            ll_set(this, i, pSegundoElemento);
                            ll_set(this, j, pAux);
                        }
                    }
                }
            }
            returnAux = 0;
        }
    }
    return returnAux;
}

/*La función “ll_count” recibirá una lista y una función “fn”. Se deberá iterar todos los
elementos de la lista y pasárselos a la funcion “fn”. La función “fn” devolverá la cantidad que
debe contarse. La función “ll_count” almacenará un acumulador al cual sumará el valor de
retorno de “fn” en cada iteración. Al finalizar las iteraciones, la función “ll_count”
devolverá el valor acumulado.
*/

int ll_count(LinkedList* this, int (*fn) (void* element))
{
    int contador = 0;
    int retorno = -1;
    int aux;
    int i;
    int size;
    if(this != NULL && (!ll_isEmpty(this)) && fn != NULL)
    {
        size = ll_len(this);
        for(i=0; i<size; i++)
        {
            aux = fn(ll_get(this, i)); //EN CADA ITERACIÓN voy a estar invocando a la función "fn" que trae como parámetro un void* pElement con la cantidad que debe contarse
            if(aux > -1)
            {
                contador = contador + aux;
            }
        }
        retorno = contador;
    }
    return retorno;
}

/*La función “ll_filter” recibirá una lista y una función “fn”. Se deberá iterar todos los elementos de la lista y
pasárselos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la lista resultado o 0 si no debe agregarse.
La función “ll_filter” generará la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá.*/


LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
    int i;
    int size;
    int aux;
    void* auxElement;
    LinkedList* filteredList = ll_newLinkedList();
    if(this != NULL && fn != NULL && filteredList != NULL)
    {
        size = ll_len(this);
        for(i=0; i<size; i++)
        {
            auxElement = ll_get(this, i);
            aux = fn(auxElement); //DEVUELVE 1 si cumple con el criterio de fn o 0 si no lo cumple
            if(auxElement != NULL && aux == 1)
            {
                ll_add(filteredList, auxElement);
            }
        }
    }
    return filteredList;
}

LinkedList* ll_filter_parametro(LinkedList* this, int (*fn)(void* element, char string[]), char string[])
{
    int i;
    int size;
    int aux;
    void* auxElement;
    LinkedList* filteredList = ll_newLinkedList();
    if(this != NULL && fn != NULL && filteredList != NULL)
    {
        size = ll_len(this);
        for(i=0; i<size; i++)
        {
            auxElement = ll_get(this, i);
            aux = fn(auxElement, string);
            if(auxElement != NULL && aux == 1)
            {
                ll_add(filteredList, auxElement);
            }
        }
    }
    return filteredList;
}
