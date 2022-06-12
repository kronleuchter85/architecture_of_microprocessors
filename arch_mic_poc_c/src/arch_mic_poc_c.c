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

void zeros(uint32_t *vector, uint32_t length) {

	while (length) {
		vector[length] = 0;
		length--;
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

		if (scalarNumber * vectorIn[size] < 0) {
			vectorOut[size] = 4095;
		} else {
			vectorOut[size] = scalarNumber * vectorIn[size];
		}

		size--;
	}

}

// -------------------------------------------------------------------------------------------------------
// ej-5 - windowFilter10
// -------------------------------------------------------------------------------------------------------

void windowFilter10(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t vecInLength)
{
	uint32_t index;

	for (index = 0; index < vecInLength; index++) {

		uint32_t tmp_index;
		uint16_t avg = 0;

		uint32_t i;
		for (i = 0; i < 10; i++) {

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
// ej-6 - windowFilter10
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
// ej-7 - get_max
// -------------------------------------------------------------------------------------------------------

int32_t get_max(int32_t *vectorIn, uint32_t length) {

	int32_t index_max = 0;

	uint32_t index;
	for (index = 0; index < length; index++) {
		if (vectorIn[index] > vectorIn[index_max]) {
			index_max = index;
		}
	}

	return index_max;
}

// -------------------------------------------------------------------------------------------------------
// ej-8 - downsampleM
// -------------------------------------------------------------------------------------------------------

void downsampleM(int32_t *vectorIn, int32_t *vectorOut, uint32_t length, uint32_t N)
{

	uint32_t i;
	uint32_t added = 0;
	uint32_t outIndex = 0;

	for (i = 0; i < length; i++) {

		if (added < N - 1) {
			vectorOut[outIndex] = vectorIn[i];
			outIndex++;
			added++;
		} else {
			added = 0;
		}
	}
}

// -------------------------------------------------------------------------------------------------------
// ej-9 - rotate
// -------------------------------------------------------------------------------------------------------

void rotate(uint16_t *vector, uint32_t length) {

	uint32_t i;
	uint32_t x;
	uint16_t tmp_i;
	uint16_t tmp_x;
	uint32_t boundary = length / 2;

	for (i = 0; i < boundary; i++) {
		x = length - 1 - i;
		tmp_i = vector[i];
		tmp_x = vector[x];
		vector[i] = tmp_x;
		vector[x] = tmp_i;
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

void test_exercise_5() {

	uint16_t vectorIn[16] = {
			200, 150, 100, 20
			, 35, 300, 250, 450
			, 35, 300, 250, 450
			, 35, 300, 250, 450 };

	uint16_t vectorOut[16];

	windowFilter10(vectorIn, vectorOut, 16);
}

void test_exercise_6() {

	uint32_t vectorIn[8] = {
			312313123, 12348598, 7823182123, 734782424
			, 312323123, 1148538, 78829123, 34724234 };

	uint16_t vectorOut[8];

	pack32_to_16(vectorIn, vectorOut, 8);
}
void test_exercise_7() {

	int32_t vectorIn[8] = { -4234, -234, -434, 42, -988, 34, -6546, -345 };

	uint32_t max_index = get_max(vectorIn, 8);
}

void test_exercise_8() {

	int32_t vectorIn[8] = { -4234, -234, -434, 42, -988, 34, -6546, -345 };
	int32_t vectorOut[6];
	downsampleM(vectorIn, vectorOut, 8, 3);
}

void test_exercise_invertir() {

	int16_t vectorIn[8] = { 4234, 234, 434, 42, 988, 34, 6546, 345 };
	rotate(vectorIn, 8);
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
	//
	// ejercicio 2...
	//
	// test_exercise_2();
	//
	//
	// ejercicio 3...
	//
	//test_exercise_3();
	//
	//
	// ejercicio 3...
	//
	// test_exercise_4();

	// ejercicio 3...
	//
	// test_exercise_5();

	//
	// ejercicio 6
	//
	// test_exercise_6();

	//
	// ejercicio 7
	//
	// test_exercise_7();

	//
	// ejercicio 8
	//
	// test_exercise_8();

	//
	// ejercicio 9
	//
	test_exercise_invertir();

	return 0;
}

