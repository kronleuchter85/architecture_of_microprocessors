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

// -------------------------------------------------------------------------------------------------------
// ej-1 - zeros
// -------------------------------------------------------------------------------------------------------
void zeros(uint32_t *vector, uint32_t length) {

	while (length--) {
		vector[length] = 0;
	}

}

// -------------------------------------------------------------------------------------------------------
// ej-2 - productoEscalar32
// -------------------------------------------------------------------------------------------------------

void scalarProduct32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t size, uint32_t scalarNumber) {

	while (size--) {
		vectorOut[size] = scalarNumber * vectorIn[size];
	}

}

// -------------------------------------------------------------------------------------------------------
// ej-3 - productoEscalar16
// -------------------------------------------------------------------------------------------------------

void scalarProduct16(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t size, uint16_t scalarNumber) {

	while (size--) {
		vectorOut[size] = scalarNumber * vectorIn[size];
	}
}

// -------------------------------------------------------------------------------------------------------
// ej-4 - productoEscalar12
// -------------------------------------------------------------------------------------------------------

void scalarProduct12(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t size, uint16_t scalarNumber) {

	while (size--) {

		if (scalarNumber * vectorIn[size] < 0) {
			vectorOut[size] = 4095;
		} else {
			vectorOut[size] = scalarNumber * vectorIn[size];
		}

	}

}

// -------------------------------------------------------------------------------------------------------
// ej-5 - windowFilter10
// -------------------------------------------------------------------------------------------------------

void windowFilter10(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t vecInLength)
{
	uint32_t index;

	for (index = 0; index < vecInLength; index++) {

		uint16_t avg = 0;

		uint32_t i;
		for (i = 0; i < 10; i++) {

			uint32_t tmp_index;
			if (index + i < vecInLength) {
				tmp_index = (index + i);
			} else {
				tmp_index = index + i % vecInLength;
			}
			avg += vectorIn[tmp_index];
		}

		vectorOut[index] = avg / 10;

	}
}

// -------------------------------------------------------------------------------------------------------
// ej-5 - windowFilter10
// -------------------------------------------------------------------------------------------------------

void pack32_to_16(int32_t *vectorIn, int16_t *vectorOut, uint32_t length) {

	uint32_t i = 0;

	for (i = 0; i < length; i++) {

		int32_t value = vectorIn[i];
		int32_t transformed = value >> 16;
		int16_t packedOne = (int16_t) transformed;
		vectorOut[i] = packedOne;
	}
}

// -------------------------------------------------------------------------------------------------------
// utils
// -------------------------------------------------------------------------------------------------------

void set_val(uint32_t *vector, uint32_t size, uint32_t val) {

	while (size--) {
		vector[size] = val;
	}
}

void set_val_16(uint16_t *vector, uint32_t size, uint16_t val) {

	while (size--) {
		vector[size] = val;
	}
}

void printVector(uint32_t *vec, uint32_t size) {

	printf("------------------------------------------------\n");

	while (size--) {
		printf("%i-%i\n", size, vec[size]);
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
	while (size--) {
		printf("%i-%i\n", size, vec[size]);
	}
	//
	// ponemos los valores en 2
	//
	size = 16;
	while (size--) {
		vec[size] = 2;
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
	while (size--) {
		printf("%i-%i\n", size, vec2[size]);
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
	while (size--) {
		printf("%i-%i\n", size, vec[size]);
	}
	//
	// ponemos los valores en un numero random
	//
	size = 16;
	while (size--) {
		vec[size] = rand() % 11;
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
	while (size--) {
		printf("%i-%i\n", size, vec2[size]);
	}
}

void test_exercise_6() {

	uint32_t vectorIn[8] = {
			312313123, 12348598, 7823182123, 734782424
			, 312323123, 1148538, 78829123, 34724234 };

	uint16_t vectorOut[8];

	pack32_to_16(vectorIn, vectorOut, 8);
}

