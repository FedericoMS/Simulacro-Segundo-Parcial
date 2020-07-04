#include "Flights.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Flight* flight_new()
{
    Flight* aFlight;
    return aFlight = (Flight*)malloc(sizeof(Flight));
}
Flight* flight_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr)
{
    Flight* aFlight;
    aFlight = flight_new();

    int auxIdVuelo;
    int auxIdAvion;
    int auxIdPiloto;
    int auxCantPasajeros;
    int auxHoraDespegue;
    int auxHoraLlegada;

    auxIdVuelo = atoi(idVueloStr);
    auxIdAvion = atoi(idAvionStr);
    auxIdPiloto = atoi(idPilotoStr);
    auxCantPasajeros = atoi(cantPasajerosStr);
    auxHoraDespegue = atoi(horaDespegueStr);
    auxHoraLlegada = atoi(horaLlegadaStr);

    if(aFlight != NULL)
    {

     flight_setIdToFlight(aFlight , auxIdVuelo);
     flight_setIdToAnAirplane(aFlight, auxIdAvion);
     flight_setIdToAPilotInAFlight(aFlight, auxIdPiloto);
     flight_setFecha(aFlight, fechaStr);
     flight_setDestino(aFlight, destinoStr);
     flight_setCantPasajeros(aFlight , auxCantPasajeros);
     flight_setHoraDespegue(aFlight , auxHoraDespegue);
     flight_setHoraLlegada(aFlight , auxHoraLlegada);
    }

    return aFlight;
}


//////////////////////GETTERS Y SETTERS/////////////////////////
int flight_setIdToFlight(Flight* this,int idVuelo)
{
    int retorno = -1;
    if(this != NULL && idVuelo != NULL)
    {
        this->idVuelo =  idVuelo;
        retorno = 0;
    }
    return retorno;
}


int flight_getIdFromAFlight(Flight* this,int* idVuelo)
{
    int retorno = -1;
    if(this != NULL && idVuelo != NULL)
    {
        *idVuelo = this->idVuelo;
        retorno = 0;
    }
    return retorno;
}

int flight_setIdToAnAirplane(Flight* this,int idAvion)
{
    int retorno = -1;
    if(this != NULL && idAvion != NULL)
    {
        this->idAvion =  idAvion;
        retorno = 0;
    }
    return retorno;
}


int flight_getIdFromAnAirplane(Flight* this,int* idAvion)
{
    int retorno = -1;
    if(this != NULL && idAvion != NULL)
    {
        *idAvion = this->idAvion;
        retorno = 0;
    }
    return retorno;
}



int flight_setIdToAPilotInAFlight(Flight* this,int idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto != NULL)
    {
        this->idPiloto =  idPiloto;
        retorno = 0;
    }
    return retorno;
}


int flight_getIdFromAPilotInAFlight(Flight* this,int* idPiloto)
{
    int retorno = -1;
    if(this != NULL && idPiloto != NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 0;
    }
    return retorno;
}

int flight_setFecha(Flight* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strcpy(this->fecha, fecha);
        retorno = 0;
    }
    return retorno;
}

int flight_getFecha(Flight* this,char* fecha)
{
    int retorno = -1;
    if(this!= NULL && fecha != NULL)
    {
        strcpy(fecha, this->fecha);
        retorno = 0;
    }
    return retorno;
}

int flight_setDestino(Flight* this,char* destino)
{
    int retorno = -1;
    if(this != NULL && destino != NULL)
    {
        strcpy(this->destino, destino);
        retorno = 0;
    }
    return retorno;
}

int flight_getDestino(Flight* this,char* destino)
{
    int retorno = -1;
    if(this!= NULL && destino != NULL)
    {
        strcpy(destino, this->destino);
        retorno = 0;
    }
    return retorno;
}

int flight_setCantPasajeros(Flight* this,int cantPasajeros)
{
    int retorno = -1;
    if(this != NULL && cantPasajeros != NULL)
    {
        this->cantPasajeros = cantPasajeros;
        retorno = 0;
    }
    return retorno;
}

int flight_getCantPasajeros(Flight* this,int* cantPasajeros)
{
    int retorno = -1;
    if(this != NULL && cantPasajeros != NULL)
    {
        *cantPasajeros = this->cantPasajeros;
        retorno = 0;
    }
    return retorno;

}


int flight_setHoraDespegue(Flight* this,int horaDespegue)
{
    int retorno = -1;
    if(this != NULL && horaDespegue != NULL)
    {
        this->horaDespegue =  horaDespegue;
        retorno = 0;
    }
    return retorno;
}
int flight_getHoraDespegue(Flight* this,int* horaDespegue)
{
    int retorno = -1;
    if(this != NULL && horaDespegue != NULL)
    {
        *horaDespegue = this->horaDespegue;
        retorno = 0;
    }
    return retorno;

}

int flight_setHoraLlegada(Flight* this,int horaLlegada)
{
    int retorno = -1;
    if(this != NULL && horaLlegada != NULL)
    {
        this->horaLlegada = horaLlegada;
        retorno = 0;
    }
    return retorno;
}
int flight_getHoraLlegada(Flight* this,int* horaLlegada)
{
    int retorno = -1;
    if(this != NULL && horaLlegada != NULL)
    {
        *horaLlegada = this->horaLlegada;
        retorno = 0;
    }
    return retorno;
}

int cantidadDePasajerosTotales(void* pElement)
{
    int cantidad = 0;
    if(pElement != NULL)
    {
        flight_getCantPasajeros(pElement, &cantidad);
    }
    return cantidad;
}
////////////////////////////////////////////////////////////////////


///////////////////////////////////FILTROS////////////////////////////////////////
int filtrarIrlanda(void* pElement)
{
    int returnAux = 0;
    char destinoAux[50];
    if(pElement != NULL)
    {
        flight_getDestino(pElement, destinoAux);
        if(strcmpi(destinoAux, "Irlanda") == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int filtrarPortugal(void* pElement)
{
    int returnAux = 0;
    char destinoAux[50];
    if(pElement != NULL)
    {
        flight_getDestino(pElement, destinoAux);
        if(strcmpi(destinoAux, "Portugal") == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int filtrarVuelosCortos(void* pElement)
{
    int returnAux = 0;
    int despegueAux;
    int llegadaAux;
    if(pElement != NULL)
    {
        flight_getHoraDespegue(pElement, &despegueAux);
        flight_getHoraLlegada(pElement, &llegadaAux);
        if((llegadaAux - despegueAux) < 3)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int filtrarAlexLifeson(void* pElement)
{
    int returnAux = 0;
    int idAux;
    if(pElement != NULL)
    {
        flight_getIdFromAPilotInAFlight(pElement, &idAux);
        if(idAux != 1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int filtrarUnPilotoDeLosVuelos(void* pElement, int idPiloto)
{
    int returnAux = 0;
    int idAux;
    if(pElement != NULL)
    {
        flight_getIdFromAPilotInAFlight(pElement, &idAux);
        if(idAux == idPiloto)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}


int filtrarUnPiloto(void* pElement, char nombrePiloto[])
{
    int returnAux = 0;
    char nombreAux[50];

    if(pElement != NULL)
    {
        pilot_getNombre(pElement, nombreAux);
        if(strcmpi(nombreAux, nombrePiloto) != 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int filtrarPorPaisParametrizado(void* pElement, char string[])
{
    int returnAux = 0;
    char destinoAux[50];
    if(pElement != NULL)
    {
        flight_getDestino(pElement, destinoAux);
        if(strcmpi(destinoAux, string) == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
