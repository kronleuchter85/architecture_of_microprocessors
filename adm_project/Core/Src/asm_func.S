.syntax unified
.thumb
.text

@ Simbolos exportados
.global asm_svc
.global asm_sum
.global asm_zeros
.global asm_copy_vector
.global asm_iterate
.global asm_scalarProduct32
.global asm_scalarProduct16
.global asm_scalarProduct12
.global asm_windowFilter10
.global asm_get_max

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void asm_svc (void)
@
.thumb_func
    asm_svc:
        svc 0
        bx lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   uint32_t asmSum (uint32_t firstOperand, uint32_t secondOperand)
@
@ Parametros recibidos:
@   r0: firstOperand
@   r1: secondOperand
@
@ Valor de retorno:
@   r0: resultado de la suma de firstOperand y secondOperand
@
.thumb_func
    asm_sum:
        add r0, r1  @ r0 = r0 + r1
        bx lr       @ vuelve adonde fue llamada (especificamente, si "pc"
                    @ es la direccion, en el codigo del programa, de la
                    @ instruccion "bl asm_sum" usada para saltar a
                    @ esta funcion, entonces "lr" contiene ese "pc" + 4).
                    @ el valor de retorno debe quedar en el registro r0.
                    @ En este caso, r0 es el resultado de r0 + r1.

        @ Otras alternativas para el retorno
        @ mov pc,lr
        @ bx lr
        @ push {lr} ... pop {pc}


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@	EJERCICIO 1)
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C": 
@   void asm_zeros (uint32_t *vector, uint32_t longitud);
@	
@ Parametros recibidos:
@   r0: *vector
@   r1: longitud
@
.thumb_func
    asm_zeros:
        @ Registros usados
        @   r2: valor cero
        mov r2, 0           @ constante cero
    asm_zeros_loop:
        str r2, [r0], 4     @ sizeof(uint32_t) == 4, *vector++ = r2
        subs r1, 1          @ --longitud
        bne asm_zeros_loop
        bx lr




@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void asm_copy_vector (uint32_t *vector1, uint32_t *vector2, uint32_t length);
@
@ Parametros recibidos:
@   r0: *vector1
@   r1: *vector2
@   r2: length
@
.thumb_func
    asm_copy_vector:
    	@ Registros usados
    	@	r3: valor cero
    	mov		r3,0
    asm_copy_loop:
    	ldr		r3,[r0],4
    	str		r3,[r1],4
    	subs	r2, 1
    	bne		asm_copy_loop
    	bx		lr
    	




@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@	EJERCICIO 2)
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void asm_scalarProduct16(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t length, uint32_t scalarNumber);
@
@ Parametros recibidos:
@   r0: *vectorIn
@   r1: *vectorOut
@   r2: length
@	r3:	scalarNumber
@
.thumb_func
    asm_scalarProduct32:


		@
		@ pongo en el stack el valor del R4
		@
		push 	{r4}
		
		@
    	@	r4: inicializo en cero - estoy asumiendo que el R4 es un registro de proposito general
    	@
    	mov		r4,0
    asm_scalarProduct32_loop_1:
    	
    	@
		@ Cargo en R4 el contenido de la posicion de memoria del registro R0
		@ e incremento en 4 bytes su posicion para que apunte al siguiente
		@ elemento del array
		@   
    	ldr		r4,[r0],4
    	
    	@
    	@ multiplico el contenido del registro R4 por el de R3 (el valor escalar) 
    	@ y lo guardo en R3
    	@
    	mul		r4,r3
    	
    	@
    	@ Almaceno en memoria, en la posicion del registro R1 el valor de R4 e incremento 
    	@ su direccion en 4 bytes
    	@
    	str		r4,[r1],4
    	
    	subs	r2, 1
    	bne		asm_scalarProduct32_loop_1
    	
    	@
    	@ restituyo el valor de R4
    	@
		pop		{r4}
		
		
    	bx		lr
    	

    	
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@	EJERCICIO 3)
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void asm_scalarProduct16(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t length, uint16_t scalarNumber);
@
@ Parametros recibidos:
@   r0: *vectorIn
@   r1: *vectorOut
@   r2: length
@	r3:	scalarNumber
@
.thumb_func
    asm_scalarProduct16:
    	
		@
		@ pongo en el stack el valor del R4
		@
		push 	{r4}
    	
    	@
    	@	r4: inicializo en cero - estoy asumiendo que el R4 es un registro de proposito general
		@
    	mov		r4,0
    asm_scalarProduct16_loop_1:
    
    	@
		@ Cargo en R4 el contenido de la posicion de memoria del registro R0
		@ e incremento en 2 bytes su posicion para que apunte al siguiente
		@ elemento del array
		@    	
    	ldr		r4,[r0],2
    	
    	@
    	@ multiplico el contenido del registro R4 por el de R3 (el valor escalar) 
    	@ y lo guardo en R4
    	@
    	mul		r4,r3
    	
    	@
    	@ Almaceno en memoria, en la posicion del registro R1 el valor de R4 e incremento 
    	@ su direccion en 2 bytes
    	@
    	str		r4,[r1],2
    	
    	subs	r2, 1
    	
    	bne		asm_scalarProduct16_loop_1
    	
    	@
    	@ restituyo el valor de R4
    	@
		pop		{r4}
    	
    	bx		lr
    	



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@ 	Prueba de concepto de una iteracion desde el primer elemento manteniendo un indice
@
@   uint32_t asm_iterate (uint32_t *vector1, uint32_t length);
@
@ Parametros recibidos:
@   r0: *vector1 - elementos
@   r1: length - cantidad de elementos
@
.thumb_func
    asm_iterate:

		push	{r4}
		push	{r5}
		push	{r6}
		
		@
		@ indice para recorrer el arreglo de principio a fin
		@ lo inicializo en cero
		@
		mov		r3 , 0
		
		@
		@ quiero usar R5 para guardar el tamanio del tipo de datos (4 bytes)
		@ e ir incrementando el iterador en multiplos de este valor
		@
		mov		r5 , 4

	asm_get_by_index_InitLoop:

		@
		@ multiplico el indice por el tamanio del tipo de datos
		@ y lo guardo en R6
		@
		mul		r6, r3 , r5

		@
		@ traigo a R4 el elemento actual del arreglo conforme al indice basado en el 
		@ numero de elemento y tamanio tipo de datos
		@
		ldr		r4 , [r0,r6]
		
		@
		@ incremento el 1 el indice del iterador
		@
		add		r3 , 1

		@
		@ si llegue al final del arreglo
		@
		cmp		r3 , r1
		
		bne 	asm_get_by_index_InitLoop

		pop		{r6}
		pop		{r5}
		pop		{r4}

    	bx		lr
    	




@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@	EJERCICIO 4)
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@ void asm_scalarProduct12(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t length, uint16_t scalarNumber);
@
@ Parametros recibidos:
@   r0: * vectorIn
@   r1: * vectorOut
@	r2: length
@	r3: scalarNumber
@
@ Valor de retorno:
@   Ninguno
@
.thumb_func
    asm_scalarProduct12:
    	
    	@
    	@ pongo en el stack el valor de r4 
    	@
    	push 	{r4}
    	
    asm_scalarProduct12_loop:
    
    	@
    	@ cargo el contenido de memoria indicado por r0 en r4 
    	@ e incremento el valor de r0 en 2 para la siguiente iteracion
    	@
    	ldr 	r4, [r0], 2
    	
    	@
    	@ multiplico el valor de r3 por r4 y el resultado lo almaceno en r4
    	@
    	mul 	r4, r3
    	
    	@
    	@ saturo a 12 bits (segundo parametro) el valor de r4. el resultado lo 
    	@ vuelvo a almacenar en R4
    	@
    	usat 	r4, #12, r4
    	
    	@
    	@ almaceno R4 en la posicion de memoria indicada por R1, incrementando
    	@ en 2 bytes su direccion.
    	@
		str 	r4, [r1], 2
		
		@
		@ decremento en 1 el valor del tercer parametro length
		@
    	subs 	r2, 1
    	
    	@
    	@ salto condicional mientras Z != 0
    	@
        bne	asm_scalarProduct12_loop
        
        @
        @ restituyo los valores de r5 y r6
        @
        pop 	{r4}
    	
        bx 		lr
        
        
        
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@	EJERCICIO 5)
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@ void asm_windowFilter10(uint16_t * vectorIn , uint16_t * vectorOut , uint32_t vecInLength)
@
@ Parametros recibidos:
@   r0: * vector
@   r1: * vector
@	r2: vecInLength
@
.thumb_func
	asm_windowFilter10:
        push {r3}
        push {r4}
        push {r5}
        push {r6}
        push {r7}
        push {r8}

		@
		@ incializo el index en 0
		@
		mov r3, 0			

	asm_windowFilter10_for_1:
		
		@
		@ inicializo la variable avg en 0
		@
		mov r4, 0			
		
		@
		@ inicializo la variable i en cero
		@
		mov r5, 0			

	asm_windowFilter10_for_2:
		
		@
		@ sumo r3 (index) con r5 (i) y guardo el resultado en r6 
		@
		add r6, r3, r5
		
		@
		@ comparo r6 con la longitud del vector vecInLength
		@
		cmp r6, r2
		
		@
		@ si r6 es mas chico 
		@
		blt asm_windowFilter10_if_index_plus_i_lt_vecInLength
		
		@ calculo el modulo de index + i y lo guardo en r6
		@
		udiv r7, r6, r2
		mul r7, r7, r2
		sub r6, r6, r7

	asm_windowFilter10_if_index_plus_i_lt_vecInLength:

		@
		@ me desplazo al siguiente elemento del arreglo de entrada
		@ sumando 2 bytes a su direccion de memoria y traigo el valor
		@ guardandolo en r8
		@
		mov r8, 2
		mul r6, r6, r8
		add r6, r0, r6
		ldrh r8, [r6]
		
		@
		@ incremento el valor del promedio acumulado con el valor del vectorIn buscado
		@ 
		add r4, r4, r8
		
		@
		@ incremento y analisis del for (i++ && (i<10))
		@
		add r5, 1
		cmp r5, 10
		blt asm_windowFilter10_for_2

		@
		@ termino el for, calculo el promedio en r8 y lo almaceno en vectorout
		@
		mov r8, 10
		udiv r8, r4, r8
		strh r8, [r1], 2

		@
		@ incremento index y analisis del for (index++ && (iindex < vecInLength))
		@
		add r3, 1
		cmp r3, r2
		blt asm_windowFilter10_for_1

		@
		@ saco todo de la pila y restituyo los valores de los registros
		@
		pop {r8}
        pop {r7}
		pop {r6}
        pop {r5}
        pop {r4}
        pop {r3}
        
		bx lr
		

        
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@	EJERCICIO 7)
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@ int32_t asm_get_max(uint32_t *vectorIn, int32_t length);
@
@ Parametros recibidos:
@   r0: * vectorIn
@   r1: length
@ Returns:
@	r0: indice del maximo
@
.thumb_func
	asm_get_max:
	
		push {r4}
		push {r5}
		
		@
		@ voy a almacenar el valor del maximo encontrado en un registro (R2) en lugar
		@ de buscarlo del array como en la implementacion en C
		@
		mov r2, 0					
		
		@
		@ indice del maximo encontrado (R3)
		@
		mov r3, 0
		
		@
		@ me guardo la longitud inicial del array
		@
		mov r5, r1							
		
	asm_get_max_InitLoop:
	    
	    ldr r4, [r0], 4						

		@
		@ comparo el elemento actual del arreglo (indexado desde el final) con 
		@ el maximo actual guardado en R2 
		@		
		cmp r4,r2
		bgt asm_get_max_UpdateGreater		

	asm_get_max_AfterUpdatingGreater:
		
		@
		@ me muevo al siguiente elemento del arreglo (desde el final)
		@
		subs r1,1						
		
		@
		@ si llegue al comienzo del arreglo termino la iteracion
		@
		cmp r1,0							
		beq asm_get_max_End			

		@
		@ de lo contrario vuelvo al comienzo del loop
		@		
		b asm_get_max_InitLoop
	
	asm_get_max_UpdateGreater:
		
		@
		@ actualizo el maximo valor encontrado
		@
		mov r2, r4
		
		@
		@ y el de su indice
		@
		mov	r3, r1
		b asm_get_max_AfterUpdatingGreater
		
	asm_get_max_End:
	
		@
		@ como empece a recorrerlo desde el final me interesa
		@ restarlo para devolver el indice desde el elemento 0
		@
	    sub r5,r3
	    
	    @
	    @ devuelvo el indice del maximo 
	    @
		mov r0, r5
		
		pop {r5}
		pop {r4}
		
	    bx lr

