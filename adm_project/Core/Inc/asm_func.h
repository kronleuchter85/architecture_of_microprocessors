#pragma once

#include <stdint.h>

void asm_svc(void);
uint32_t asm_sum(uint32_t firstOperand, uint32_t secondOperand);

void asm_zeros(uint32_t *vector, uint32_t length);

void asm_copy_vector(uint32_t *vector1, uint32_t *vector2, uint32_t length);
