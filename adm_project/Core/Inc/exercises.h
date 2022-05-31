/*
 * exercises.h
 *
 *  Created on: 31 May 2022
 *      Author: gonzalo
 */

#ifndef INC_EXERCISES_H_
#define INC_EXERCISES_H_

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

void zeros(uint32_t *vector, uint32_t length);

// -------------------------------------------------------------------------------------------------------
// ej-2 - productoEscalar32
// -------------------------------------------------------------------------------------------------------

void scalarProduct32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t size, uint32_t scalarNumber);

// -------------------------------------------------------------------------------------------------------
// ej-3 - productoEscalar16
// -------------------------------------------------------------------------------------------------------

void scalarProduct16(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t size, uint16_t scalarNumber);

// -------------------------------------------------------------------------------------------------------
// ej-4 - productoEscalar12
// -------------------------------------------------------------------------------------------------------

void scalarProduct12(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t size, uint16_t scalarNumber);

// -------------------------------------------------------------------------------------------------------
// utils
// -------------------------------------------------------------------------------------------------------

void set_val(uint32_t *vector, uint32_t size, uint32_t val);

void printVector(uint32_t *vec, uint32_t size);

#endif /* INC_EXERCISES_H_ */
