
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Flights.h"
#include "Pilots.h"
int parser_FlightFromText(FILE* pFile, LinkedList* pArrayFlights)
{
    int retorno = 0;
    char idVuelo[50], idAvion[50], idPiloto[50], fecha[50], destino[50], cantPasajeros[50], horaDespegue[50], horaLlegada[50];
    Flight* aFlight;
    int band = 1;
    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }

    do
    {
        if(band)
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            band = 0;
        }
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        printf("Lei: %s--%s--%s--%s--%s--%s--%s--%s\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);

        aFlight = flight_newParametros(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        if(aFlight != NULL)
        {
            ll_add(pArrayFlights, aFlight);
            retorno = 1;

        }
    }while(!feof(pFile));

    return retorno;

}

int parser_PilotsFromText(FILE* pFile, LinkedList* pArrayPilots)
{
    int retorno = 0;
    char ID[50], Nombre[100];
    Pilot* aPilot;
    int band = 1;
    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }

    do
    {
        if(band)
        {
            fscanf(pFile, "%[^,],%[^\n]\n", ID, Nombre);
            band = 0;
        }
        fscanf(pFile, "%[^,],%[^\n]\n", ID, Nombre);
        printf("Lei: %s--%s\n", ID, Nombre);

        aPilot = pilot_newParametros(ID, Nombre);
        if(aPilot != NULL)
        {
            ll_add(pArrayPilots, aPilot);
            retorno = 1;

        }
    }while(!feof(pFile));

    return retorno;

}

