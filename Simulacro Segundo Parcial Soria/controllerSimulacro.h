#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int controller_Soria_loadFromText(char* path, LinkedList* pArrayFlights);
int controller_Soria_loadFromTextPilots(char* path, LinkedList* pArrayPilots);
int controller_Soria_ListFlightsWithPilots(LinkedList* pArrayListFlights, LinkedList* pArrayListPilots);
int controller_Soria_ShortFlights(LinkedList* pArrayPilots, LinkedList* pArrayFlights);
int controller_Soria_FlightsToPortugal(LinkedList* pArrayPilots, LinkedList* pArrayFlights);
int controller_Soria_FlightsToIreland(LinkedList* pArrayFlights);
void controller_Soria_CounterOfPassengers(LinkedList* pArrayFlights);
void controller_Soria_FlightsWithoutAlexLifeson(LinkedList* pArrayPilots, LinkedList* pArrayFlights);
int controller_Soria_PilotList(LinkedList* pArrayPilots);
int controller_Soria_saveAsText(char* path, LinkedList* pArrayFlights);
void controller_Soria_PilotFromFlightsFilteredList(LinkedList* pArrayPilots, LinkedList* pArrayFlights);
int controller_Soria_FlightsToPortugalWithParameters(LinkedList* pArrayPilots, LinkedList* pArrayFlights);
void controller_Soria_PilotFilteredList(LinkedList* pArrayPilots);

