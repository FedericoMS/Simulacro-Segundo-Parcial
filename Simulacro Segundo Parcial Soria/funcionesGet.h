#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** \brief It gets an int
 *
 * \param mensaje
 * \return An int
 */
int getInt(char message[], char errorMessage[], int min, int max);


/** \brief It capitalizes the first letter
 *
 * \param caracter[]
 * \return void
 */
void stringToUpper(char caracter[]);



/** \brief It verifies if it's a number
 *
 * \param str
 * \return 1 if it's a number, 0 otherwise
 */
int esNumerico (char str[]);




/** \brief It verifies if it's only letters
 *
 * \param str
 * \return 1 if the string is composed by letters
 */
int esSoloLetras (char str[]);





/** \brief It gets a string
 *
 * \param mensaje
 * \param input Array
 * \return void.
 */
void getString(char mensaje[], char input[]);



/** \brief It gets a string that is composed only by letters
 *
 * \param mensaje
 * \param input Array
 * \return 1
 */
int getStringLetras(char mensaje[],char mensajeError[], char input[]);



/** \brief It gets a string that is composed only by numbers
 *
 * \param mensaje
 * \param input
 * \return 1
 */
int getStringNumeros(char mensaje[],char mensajeError[], char input[]);



/** \brief  It gets a letter
 *
 * \param message[] char
 * \param errorMessage[] char
 * \return char
 *
 */
char getLetter(char message[], char errorMessage[]);


