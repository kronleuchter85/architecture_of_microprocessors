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
// ej-6 - pack32_to_16
// -------------------------------------------------------------------------------------------------------

void pack32_to_16(int32_t *vectorIn, int16_t *vectorOut, uint32_t length) {

	uint32_t i = 0;
	int32_t mask = 0xffff0000;
	for (i = 0; i < length; i++) {

		int32_t value = vectorIn[i];
		int32_t transformed = mask & value;
		transformed = transformed >> 16;
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

void downsampleM(int32_t *vectorIn, int32_t *vectorOut, uint32_t length, uint32_t N) {
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

