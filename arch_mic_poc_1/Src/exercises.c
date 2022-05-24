/*
 ============================================================================
 Name        : ejercises.c
 Author      : gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * exercises.c
 *
 *  Created on: 21 May 2022
 *      Author: gonzalo
 */

#include <stdint.h>

// -------------------------------------------------------------------------------------------------------
// ej-1 - zeros
// -------------------------------------------------------------------------------------------------------

void zeros(uint32_t *vector, uint32_t size) {

	int i;
	for (i = 0; i < size; i++) {
		vector[i] = 0;
	}
}

// -------------------------------------------------------------------------------------------------------
// ej-2 - productoEscalar32
// -------------------------------------------------------------------------------------------------------

void scalarProduct32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t size, uint32_t scalarNumber) {

	int i;
	for (i = 0; i < size; i++) {
		vectorOut[i] = scalarNumber * vectorIn[i];
	}
}

// -------------------------------------------------------------------------------------------------------
// ej-3
// -------------------------------------------------------------------------------------------------------

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t longitud, uint16_t escalar) {

}

// -------------------------------------------------------------------------------------------------------
// ej-4
// -------------------------------------------------------------------------------------------------------

void productoEscalar12(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t longitud, uint16_t escalar) {

}

void printVector(uint32_t *vec, uint32_t size) {

	printf("------------------------------------------------\n");
	int i;
	for (i = 0; i < size; i++) {
		printf("%i-%i\n", i, vec[i]);
	}
}

int main() {

	//----------------------------------- ejercicio 1 ----------------------------------------------------------
	//
	//
	// inicializamos un vector
	//
	uint32_t vec[16];

	//
	// imprimimos los valores iniciales
	//
	printVector(vec, 16);

	//
	// ponemos los valores en cero
	//
	zeros(vec, 16);

	//
	// imprimimos los valores despues de cambiarlos
	//
	printVector(vec, 16);

	//----------------------------------- ejercicio 2 ----------------------------------------------------------
	//

	return 0;
}

