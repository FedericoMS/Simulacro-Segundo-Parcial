
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[100];
    char destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}Flight;

Flight* flight_new();

Flight* flight_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr);

int flight_setIdToFlight(Flight* this,int idVuelo);

int flight_getIdFromAFlight(Flight* this,int* idVuelo);

int flight_setIdToAnAirplane(Flight* this,int idAvion);

int flight_getIdFromAnAirplane(Flight* this,int* idAvion);

int flight_setIdToAPilotInAFlight(Flight* this,int idPiloto);

int flight_getIdFromAPilotInAFlight(Flight* this,int* idPiloto);

int flight_setFecha(Flight* this,char* fecha);

int flight_getFecha(Flight* this,char* fecha);

int flight_setDestino(Flight* this,char* destino);

int flight_getDestino(Flight* this,char* destino);

int flight_setCantPasajeros(Flight* this,int cantPasajeros);

int flight_getCantPasajeros(Flight* this,int* cantPasajeros);

int flight_setHoraDespegue(Flight* this,int horaDespegue);

int flight_getHoraDespegue(Flight* this,int* horaDespegue);

int flight_setHoraLlegada(Flight* this,int horaLlegada);

int flight_getHoraLlegada(Flight* this,int* horaLlegada);

int cantidadDePasajerosTotales(void* pElement);

int filtrarIrlanda(void* pElement);

int filtrarPortugal(void* pElement);

int filtrarVuelosCortos(void* pElement);

int filtrarAlexLifeson(void* pElement);

int filtrarUnPilotoDeLosVuelos(void* pElement, int idPiloto);

int filtrarUnPiloto(void* pElement, char nombrePiloto[]);

int filtrarPorPaisParametrizado(void* pElement, char string[]);
