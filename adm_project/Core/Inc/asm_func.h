#pragma once

#include <stdint.h>

void asm_svc(void);
uint32_t asm_sum(uint32_t firstOperand, uint32_t secondOperand);

void asm_zeros(uint32_t *vector, uint32_t length);

void asm_copy_vector(uint32_t *vector1, uint32_t *vector2, uint32_t length);

void asm_scalarProduct32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t size, uint32_t scalarNumber);

void asm_scalarProduct16(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t size, uint16_t scalarNumber);

//void asm_set_val(uint16_t *vector, uint32_t size, uint16_t val)

void asm_scalarProduct12(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t length, uint16_t scalarNumber);

void asm_windowFilter10(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t vecInLength);

void asm_pack32_to_16(int32_t *vectorIn, int16_t *vectorOut, uint32_t length);

int32_t asm_get_max(uint32_t *vectorIn, int32_t length);
