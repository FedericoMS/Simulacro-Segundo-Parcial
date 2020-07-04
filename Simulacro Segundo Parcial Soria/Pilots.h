#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
typedef struct
{
    int idPiloto;
    char nombre[100];
}Pilot;

Pilot* getPilotById(LinkedList* pArrayPilots, int idPiloto);

Pilot* pilot_newParametros(char* idPiloto,char* nombre);

Pilot* pilot_new();

Pilot* getPilotById(LinkedList* pArrayPilots, int idPiloto);

int pilot_setIdPilot(Pilot* this,int idPiloto);

int pilot_getIdPilot(Pilot* this,int* idPiloto);

int pilot_setNombre(Pilot* this,char* nombre);

int pilot_getNombre(Pilot* this,char* nombre);

int getIdByName(LinkedList* pArrayPilots, char nombre[]);

int piloto_FiltroAlexLifeson(Pilot* aPilot);

