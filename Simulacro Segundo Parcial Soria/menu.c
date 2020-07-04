#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "funcionesGet.h"
int mainMenu()
{
    int option;
    printf("1. Cargar archivo\n\n");
    printf("2. Imprimir vuelos: Se imprimira por pantalla la tabla con los datos de los vuelos indicando el nombre del piloto (no el numero).\n\n");
    printf("3. Cantidad de pasajeros totales\n\n");
    printf("4. Cantidad de pasajeros a irlanda\n\n");
    printf("5. Filtrar y guardar en un archivo los vuelos cortos (duracion menor a 3 horas)\n\n");
    printf("6. Listar vuelos a Portugal\n\n");
    printf("7. Filtrar a Alex Lifeson\n\n");
    printf("8. Filtrar piloto en lista de pilotos\n\n");
    printf("9. Filtrar piloto en lista de vuelos\n\n");
    printf("10. Salir\n\n");
    option = getInt("Ingrese la opcion deseada: ", "No ha ingresado una opcion valida, intente de nuevo: ", 1, 10);
    return option;
}




