#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Flights.h"
#include "Pilots.h"
#include "controllerSimulacro.h"

int controller_Soria_loadFromText(char* path, LinkedList* pArrayFlights)
{
    FILE* pFile;
    if(pFile != NULL)
    {
        pFile = fopen(path, "r");
        parser_FlightFromText(pFile, pArrayFlights);
    }
    else
    {
        printf("\nNo existe el archivo\n");
    }
    fclose(pFile);

    return 1;

}

int controller_Soria_loadFromTextPilots(char* path, LinkedList* pArrayPilots)
{
    FILE* pFile;
    if(pFile != NULL)
    {
        pFile = fopen(path, "r");
        parser_PilotsFromText(pFile, pArrayPilots);
    }
    else
    {
        printf("\nNo existe el archivo\n");
    }
    fclose(pFile);

    return 1;

}

int controller_Soria_ListFlightsWithPilots(LinkedList* pArrayListFlights, LinkedList* pArrayListPilots)
{
    int i;
    Flight* aFlight;
    Pilot* aPilot;
    int idVueloAux;
    int idAvionAux;
    int idPilotoAux;
    char nombrePiloto[100];
    char fechaAux[100];
    char destinoAux[100];
    int cantPasajerosAux;
    int horaDespegueAux;
    int horaLlegadaAux;
    int retorno = -1;
    int sizeList = NULL;
    if(pArrayListFlights != NULL && pArrayListPilots != NULL)
    {
        printf("\n IDVUELO--IDAVION ------- NOMBRE --------- FECHA -------- DESTINO --- PASAJEROS --- HORADESPEGUE --- HORALLEGADA\n");
        retorno = 0;
        sizeList = ll_len(pArrayListFlights);
        for(i=0; i< sizeList; i++)
        {
             aFlight = ll_get(pArrayListFlights, i);
             flight_getIdFromAFlight(aFlight, &idVueloAux);

             flight_getIdFromAnAirplane(aFlight, &idAvionAux);

             flight_getIdFromAPilotInAFlight(aFlight,&idPilotoAux);

             aPilot = getPilotById(pArrayListPilots, idPilotoAux);

             pilot_getNombre(aPilot, nombrePiloto);

             flight_getFecha(aFlight, fechaAux);

             flight_getDestino(aFlight, destinoAux);

             flight_getCantPasajeros(aFlight, &cantPasajerosAux);

             flight_getHoraDespegue(aFlight, &horaDespegueAux);

             flight_getHoraLlegada(aFlight, &horaLlegadaAux);
             printf("%5d %8d %20s %14s %15s %9d %12d %15d\n", idVueloAux, idAvionAux, nombrePiloto, fechaAux, destinoAux, cantPasajerosAux, horaDespegueAux, horaLlegadaAux);
        }
    }
    return retorno;
}

int controller_Soria_saveAsText(char* path, LinkedList* pArrayFlights)
{
    FILE* pFile;
    Flight* aFlight;
    int i;
    int* idVueloAux;
    int* idAvionAux;
    int* idPilotoAux;
    char* fechaAux;
    char* destinoAux;
    int* cantPasajerosAux;
    int* horaDespegueAux;
    int* horaLlegadaAux;
    int size;
    if(path != NULL && pArrayFlights != NULL)
    {
        idVueloAux = malloc(sizeof(int));
        idAvionAux = malloc(sizeof(int));
        idPilotoAux = malloc(sizeof(int));
        fechaAux = malloc(sizeof(char)*100);
        destinoAux = malloc(sizeof(char)*100);
        cantPasajerosAux = malloc(sizeof(int));
        horaDespegueAux = malloc(sizeof(int));
        horaLlegadaAux = malloc(sizeof(int));
        pFile = fopen(path, "w");
        fprintf(pFile, "idVuelo,IdAvion,IdPiloto,Fecha,Destino,Pasajeros,HoraDespegue,HoraLlegada\n");
        size = ll_len(pArrayFlights);
        for(i=0; i < size; i++)
        {
             aFlight = ll_get(pArrayFlights, i);
             flight_getIdFromAFlight(aFlight, idVueloAux);
             flight_getIdFromAnAirplane(aFlight, idAvionAux);
             flight_getIdFromAPilotInAFlight(aFlight, idPilotoAux);
             flight_getFecha(aFlight, fechaAux);
             flight_getDestino(aFlight, destinoAux);
             flight_getCantPasajeros(aFlight, cantPasajerosAux);
             flight_getHoraDespegue(aFlight, horaDespegueAux);
             flight_getHoraLlegada(aFlight, horaLlegadaAux);

            fprintf(pFile, "%d,%d,%d,%s,%s,%d,%d,%d\n", *idVueloAux, *idAvionAux, *idPilotoAux, fechaAux, destinoAux, *cantPasajerosAux, *horaDespegueAux, *horaLlegadaAux);
        }

        free(idVueloAux);
        free(idAvionAux);
        free(idPilotoAux);
        free(fechaAux);
        free(destinoAux);
        free(cantPasajerosAux);
        free(horaDespegueAux);
        free(horaLlegadaAux);
        fclose(pFile);
        printf("Se guardaron los datos correctamente\n");
    }
    else
    {
        printf("No se guardó el archivo\n");
    }
    return 1;
}




int controller_Soria_PilotList(LinkedList* pArrayPilots)
{
    int i;
    Pilot* aPilot;
    int idAux;
    char nombreAux[100];
    int retorno = -1;
    if(pArrayPilots != NULL)
    {
        printf(" IDPILOTO   ----   NOMBRE\n");
        for(i=0; i<ll_len(pArrayPilots); i++)
        {
            aPilot = ll_get(pArrayPilots, i);
            pilot_getIdPilot(aPilot, &idAux);
            pilot_getNombre(aPilot, nombreAux);

            printf("%5d %22s\n", idAux, nombreAux);
        }
        retorno = 0;
    }
    return retorno;
}

int controller_Soria_FlightsToIreland(LinkedList* pArrayFlights)
{
    LinkedList* misVuelosAIrlanda = ll_newLinkedList();
    misVuelosAIrlanda = ll_filter(pArrayFlights, filtrarIrlanda);
    int cantidadPasajerosAIrlanda = 0;
    if(misVuelosAIrlanda != NULL)
    {
        cantidadPasajerosAIrlanda = ll_count(misVuelosAIrlanda, cantidadDePasajerosTotales);
        if(cantidadPasajerosAIrlanda > 0)
        {
            printf("La cantidad de pasajeros que vuelan a Irlanda es %d\n", cantidadPasajerosAIrlanda);
        }
        else
        {
            printf("No hay pasajeros que vuelen a Irlanda\n");
        }
        ll_deleteLinkedList(misVuelosAIrlanda);
    }
}

int controller_Soria_FlightsToPortugal(LinkedList* pArrayPilots, LinkedList* pArrayFlights)
{
    LinkedList* misVuelosAPortugal = ll_newLinkedList();
    misVuelosAPortugal = ll_filter(pArrayFlights, filtrarPortugal);
    if(misVuelosAPortugal != NULL)
    {
        controller_Soria_ListFlightsWithPilots(misVuelosAPortugal, pArrayPilots);
    }
    ll_deleteLinkedList(misVuelosAPortugal);
}

int controller_Soria_ShortFlights(LinkedList* pArrayPilots, LinkedList* pArrayFlights)
{
    LinkedList* misVuelosCortos = ll_newLinkedList();
    misVuelosCortos = ll_filter(pArrayFlights, filtrarVuelosCortos);
    int retorno = -1;
    if(misVuelosCortos != NULL)
    {
        controller_Soria_saveAsText("misVuelosCortos.csv", misVuelosCortos);
    }
    ll_deleteLinkedList(misVuelosCortos);
    return retorno;
}

void controller_Soria_CounterOfPassengers(LinkedList* pArrayFlights)
{
    int cantidadPasajeros = 0;
    cantidadPasajeros = ll_count(pArrayFlights, cantidadDePasajerosTotales);
    if(cantidadPasajeros > 0)
    {
        printf("La cantidad de pasajeros es %d\n", cantidadPasajeros);
    }
    else
    {
        printf("No hay pasajeros para ningun vuelo\n");
    }

}

int controller_Soria_FlightsToPortugalWithParameters(LinkedList* pArrayPilots, LinkedList* pArrayFlights)
{
    LinkedList* misVuelosAPortugal = ll_newLinkedList();
    misVuelosAPortugal = ll_filter_parametro(pArrayFlights, filtrarPorPaisParametrizado, "Portugal");
    if(misVuelosAPortugal != NULL)
    {
        controller_Soria_ListFlightsWithPilots(misVuelosAPortugal, pArrayPilots);
    }
    ll_deleteLinkedList(misVuelosAPortugal);
}


void controller_Soria_FlightsWithoutAlexLifeson(LinkedList* pArrayPilots, LinkedList* pArrayFlights)
{
    LinkedList* misVuelosSinAlex = ll_newLinkedList();
    misVuelosSinAlex = ll_filter(pArrayFlights, filtrarAlexLifeson);
    if(misVuelosSinAlex != NULL)
    {
        controller_Soria_ListFlightsWithPilots(misVuelosSinAlex, pArrayPilots);
        ll_deleteLinkedList(misVuelosSinAlex);
    }
}

//EJERCICIO 8
void controller_Soria_PilotFilteredList(LinkedList* pArrayPilots)
{
    LinkedList* listaDePilotosFiltrada = ll_newLinkedList();
    char nombreAux[100];
    if(pArrayPilots != NULL && listaDePilotosFiltrada != NULL)
    {
        controller_Soria_PilotList(pArrayPilots);
        getStringLetras("Ingrese el nombre del piloto a filtrar\n", "Error, nombre no valido\n", nombreAux);
        listaDePilotosFiltrada = ll_filter_parametro(pArrayPilots, filtrarUnPiloto,nombreAux);
        if((ll_len(pArrayPilots) == ll_len(listaDePilotosFiltrada)))
        {
            printf("No se filtro ningun piloto ya que no existe\n");
        }
        else
        {
            controller_Soria_PilotList(listaDePilotosFiltrada);

        }
        ll_deleteLinkedList(listaDePilotosFiltrada);
    }
}
//EJERCICIO 9
void controller_Soria_PilotFromFlightsFilteredList(LinkedList* pArrayPilots, LinkedList* pArrayFlights)
{
    LinkedList* listaDeVuelosFiltrada = ll_newLinkedList();
    char nombreAux[100];
    int idAux;
    controller_Soria_PilotList(pArrayPilots);
    getStringLetras("Ingrese el nombre del piloto a mostrar sus vuelos\n", "Error, nombre no valido\n", nombreAux);
    idAux = getIdByName(pArrayPilots, nombreAux);
    if(idAux > -1 && idAux <= 5)
    {
        listaDeVuelosFiltrada = ll_filter_parametro(pArrayFlights, filtrarUnPilotoDeLosVuelos, idAux);
        controller_Soria_ListFlightsWithPilots(listaDeVuelosFiltrada, pArrayPilots);
        ll_deleteLinkedList(litaDeVuelosFiltrada);
    }
    else
    {
        printf("El piloto ingresado no existe o no tiene vuelos asignados\n");
    }
}
