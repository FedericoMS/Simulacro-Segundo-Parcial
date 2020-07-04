#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilots.h"

Pilot* pilot_new()
{
    Pilot* aPilot;
    return aPilot = (Pilot*)malloc(sizeof(Pilot));
}
Pilot* pilot_newParametros(char* idPiloto,char* nombre)
{
    Pilot* aPilot;
    aPilot = pilot_new();

    int auxIdPiloto;

    auxIdPiloto = atoi(idPiloto);

    if(aPilot != NULL)
    {
        pilot_setIdPilot(aPilot, auxIdPiloto);
        pilot_setNombre(aPilot, nombre);
    }

    return aPilot;
}

Pilot* getPilotById(LinkedList* pArrayPilots, int idPiloto)
{
    int i;
    int size = ll_len(pArrayPilots);
    Pilot* aPilot;
    int idAux;
    if(pArrayPilots != NULL)
    {
        for(i=0; i<size; i++)
        {
            aPilot = ll_get(pArrayPilots, i);
            pilot_getIdPilot(aPilot, &idAux);
            if(idPiloto == idAux)
            {
                break;
            }
        }
    }
    return aPilot;
}

int piloto_FiltroAlexLifeson(Pilot* aPilot)
{
    int retorno = -1;
    char nombreAux[100];
    pilot_getNombre(aPilot, nombreAux);
    printf("nombreaux es %s\n", nombreAux);

    if(strcmpi(nombreAux, "Alex Lifeson") == 0)
    {
        retorno = 0;
    }
    return retorno;
}

int getIdByName(LinkedList* pArrayPilots, char nombre[])
{
    int i;
    int retorno = -1;
    char nombreAux[50];
    int size;
    Pilot* aPilot;
    if(pArrayPilots != NULL)
    {
        size = ll_len(pArrayPilots);
        for(i=0; i<size; i++)
        {
            aPilot = ll_get(pArrayPilots, i);
            pilot_getNombre(aPilot, nombreAux);
            if(strcmpi(nombreAux, nombre) == 0)
            {
                pilot_getIdPilot(aPilot, &retorno);
                break;
            }
        }
    }
    return retorno;
}

////////////////////////SETTERS Y GETTERS////////////////////////////

int pilot_setIdPilot(Pilot* this,int idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto != NULL)
    {
        this->idPiloto =  idPiloto;
        retorno = 0;
    }
    return retorno;
}


int pilot_getIdPilot(Pilot* this,int* idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto != NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 0;
    }
    return retorno;
}

int pilot_setNombre(Pilot* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int pilot_getNombre(Pilot* this,char* nombre)
{
    int retorno = -1;
    if(this!= NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
