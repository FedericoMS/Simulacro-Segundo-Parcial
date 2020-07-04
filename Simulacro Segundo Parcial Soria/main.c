#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "controllerSimulacro.h"
#include "Flights.h"
#include "menu.h"
#include "funcionesGet.h"
#include "Pilots.h"

int main()
{
    LinkedList* misVuelos = ll_newLinkedList();
    LinkedList* misPilotos = ll_newLinkedList();
    int primeraVez = 0;
    char option;
    do
    {
        option = mainMenu();
        switch(option)
        {
        case 1:
            system("cls");
            if(primeraVez == 0)
            {
                controller_Soria_loadFromText("Vuelos.csv", misVuelos);
                controller_Soria_loadFromTextPilots("Pilotos.csv", misPilotos);
                primeraVez = 1;
            }
            else
            {
                ll_clear(misVuelos);
                ll_deleteLinkedList(misVuelos);
                ll_clear(misPilotos);
                ll_deleteLinkedList(misPilotos);
                misVuelos = ll_newLinkedList();
                controller_Soria_loadFromText("Vuelos.csv", misVuelos);
                controller_Soria_loadFromTextPilots("Pilotos.csv", misPilotos);
            }
            break;

        case 2:
            system("cls");
            controller_Soria_ListFlightsWithPilots(misVuelos, misPilotos);
            break;

        case 3:
            system("cls");
            controller_Soria_CounterOfPassengers(misVuelos);
            break;

        case 4:
            system("cls");
            controller_Soria_FlightsToIreland(misVuelos);
            break;

        case 5:
            system("cls");
            controller_Soria_ShortFlights(misPilotos, misVuelos);
            break;

        case 6:
            system("cls");
            controller_Soria_FlightsToPortugalWithParameters(misPilotos, misVuelos);
            break;

        case 7:
            system("cls");
            controller_Soria_FlightsWithoutAlexLifeson(misPilotos, misVuelos);
            break;

        case 8:
            system("cls");
            controller_Soria_PilotFilteredList(misPilotos);
            break;

        case 9:
            system("cls");
            controller_Soria_PilotFromFlightsFilteredList(misPilotos, misVuelos);
            break;

        case 10:
            system("cls");
            printf("Saliendo\n");
            break;

        default:
            printf("Opcion incorrecta, por favor ingrese una opcion valida\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(option < 10);
}



