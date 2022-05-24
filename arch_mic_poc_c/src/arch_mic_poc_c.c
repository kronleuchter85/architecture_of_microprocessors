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

	while (size) {
		vector[size] = 0;
		size--;
	}

}

// -------------------------------------------------------------------------------------------------------
// ej-2 - productoEscalar32
// -------------------------------------------------------------------------------------------------------

void scalarProduct32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t size, uint32_t scalarNumber) {

	while (size) {
		vectorOut[size] = scalarNumber * vectorIn[size];
		size--;
	}

}

// -------------------------------------------------------------------------------------------------------
// ej-3 - productoEscalar16
// -------------------------------------------------------------------------------------------------------

void scalarProduct16(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t size, uint16_t scalarNumber) {

	while (size) {
		vectorOut[size] = scalarNumber * vectorIn[size];
		size--;
	}
}

// -------------------------------------------------------------------------------------------------------
// ej-4 - productoEscalar12
// -------------------------------------------------------------------------------------------------------

void scalarProduct12(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t size, uint16_t scalarNumber) {

	while (size) {
		vectorOut[size] = scalarNumber * vectorIn[size];

		if (vectorOut[size] > 4095) {
			vectorOut[size] = 4095;
		}

		size--;
	}

}

// -------------------------------------------------------------------------------------------------------
// utils
// -------------------------------------------------------------------------------------------------------

void set_val(uint32_t *vector, uint32_t size, uint32_t val) {

	while (size) {
		vector[size] = val;
		size--;
	}
}

void printVector(uint32_t *vec, uint32_t size) {

	printf("------------------------------------------------\n");

	while (size) {
		printf("%i-%i\n", size, vec[size]);
		size--;
	}

}

// -------------------------------------------------------------------------------------------------------
// tests
// -------------------------------------------------------------------------------------------------------

void test_exercise_1() {

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
}

void test_exercise_2() {

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
	// ponemos los valores en 2
	//
	set_val(vec, 16, 2);

	//
	// multiplicamos todos los valores por 2
	//
	uint32_t vec2[16];
	scalarProduct32(vec, vec2, 16, 2);

	//
	// imprimimos los valores despues de cambiarlos
	//
	printVector(vec2, 16);
}

void test_exercise_3() {

	uint32_t size;

	//
	//
	// inicializamos un vector
	//
	uint16_t vec[16];

	//
	// imprimimos los valores iniciales
	//
	printf("------------------------------------------------\n");
	size = 16;
	while (size) {
		printf("%i-%i\n", size, vec[size]);
		size--;
	}
	//
	// ponemos los valores en 2
	//
	size = 16;
	while (size) {
		vec[size] = 2;
		size--;
	}

	//
	// multiplicamos todos los valores por 2
	//
	uint16_t vec2[16];
	scalarProduct16(vec, vec2, 16, 2);

	//
	// imprimimos los valores despues de cambiarlos
	//
	printf("------------------------------------------------\n");
	size = 16;
	while (size) {
		printf("%i-%i\n", size, vec2[size]);
		size--;
	}
}

void test_exercise_4() {

	uint32_t size;

	//
	//
	// inicializamos un vector
	//
	uint16_t vec[16];

	//
	// imprimimos los valores iniciales
	//
	printf("------------------------------------------------\n");
	size = 16;
	while (size) {
		printf("%i-%i\n", size, vec[size]);
		size--;
	}
	//
	// ponemos los valores en un numero random
	//
	size = 16;
	while (size) {
		vec[size] = rand() % 11;
		size--;
	}

	//
	// multiplicamos todos los valores por 700 sabiendo que saturan cuando alcanzan 12 bits (4095)
	//
	uint16_t vec2[16];
	scalarProduct12(vec, vec2, 16, 700);

	//
	// imprimimos los valores despues de cambiarlos
	//
	printf("------------------------------------------------\n");
	size = 16;
	while (size) {
		printf("%i-%i\n", size, vec2[size]);
		size--;
	}
}

// -------------------------------------------------------------------------------------------------------
// main
// -------------------------------------------------------------------------------------------------------

int main() {

	//
	// ejercicio 1...
	//
	// test_exercise_1();

	//
	// ejercicio 2...
	//
	// test_exercise_2();

	//
	// ejercicio 3...
	//
	//test_exercise_3();

	//
	// ejercicio 3...
	//
	test_exercise_4();

	return 0;
}

