
# Cortex M

1. Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y
M4.

> 
> Respuesta:
> 
> El Cortex-M3 y el Cortex-M4 son núcleos muy similares. Cada uno ofrece un rendimiento de 1,25 DMIPS/MHz con un Pipeline de 3 etapas, múltiples buses de 32 bits, velocidades de reloj de hasta 200 MHz y opciones de depuración muy eficientes. La diferencia significativa es la capacidad del núcleo Cortex-M4 para DSP. El Cortex-M3 y el Cortex-M4 comparten la
misma arquitectura y conjunto de instrucciones Thumb-2. Sin embargo, el Cortex-M4 agrega una “gama de saturación” e instrucciones SIMD específicamente optimizadas para manejar algoritmos DSP. Por ejemplo, en el caso de un algoritmo “512 FFT point” que se ejecuta cada 0,5 segundos, en un MCU Cortex M3 y Cortex M4, en comparación, el Cortex-M3 consumiría alrededor de tres veces la energía que necesitaría un Cortex-M4 para el mismo trabajo. También existe la opción de obtener una unidad de punto flotante (FPU) de precisión única en un Cortex-M4, por lo que si la aplicación requiere matemáticas de punto flotante, será considerablemente más rápido usar un Cortex-M4 de lo que lo sería en un Cortex-M3. Dicho esto, para una aplicación que no utiliza las capacidades DSP o FPU del Cortex-M4, verá el mismo nivel de rendimiento y consumo de energía en un Cortex-M3. 
> 
> Para aplicaciones que son particularmente sensibles a los costos o que están migrando de 8 bits a 32 bits, el más pequeño miembro de la serie Cortex-M podría ser la mejor opción. El rendimiento de Cortex M0+ se encuentra un poco por debajo del Cortex-M3 y Cortex-M4 a 0,95 DMIPS/MHz (contra los 1.25 mencionados anteriormente) pero sigue siendo compatible con sus hermanos mayores. El Cortex M0+ usa un subconjunto del conjunto de instrucciones Thumb-2, y esas instrucciones son predominantemente operandos de 16 bits (aunque todas las operaciones de datos son de 32 bits), que se prestan muy bien a la canalización de 2 etapas que ofrece el Cortex M0+. Esto trae un ahorro general de energía al sistema a través de la reducción de la ramificación shadow, y la canalización en la mayoría de los casos contendrá las siguientes cuatro instrucciones. El Cortex-M0+ también tiene un bus dedicado para GPIO de ciclo único, lo que significa que puede implementar ciertas interfaces con GPIO basado en bits como lo haría en una MCU de 8 bits pero con el rendimiento de un núcleo de 32 bits para procesar los datos.
> 
> Otra diferencia clave en el Cortex M0+ es la adición del búfer de micro trazas (MTB). Estos periféricos le permiten dedicar parte de la memoria RAM del chip para almacenar ramas del programa durante la depuración. Estas ramas se pueden volver a pasar al entorno de desarrollo integrado (IDE), y el flujo del programa  puede ser reconstruido. Esta capacidad proporciona una forma rudimentaria de seguimiento de instrucciones y compensa el hecho de no tener la macrocélula de seguimiento extendida (ETM) que se encuentra en los Cortex-M3 y Cortex-M4. El nivel de información de depuración que puede extraer de un Cortex M0+ es significativamente mayor que el que puede obtener de una MCU de 8 bits, lo que significa que esos errores difíciles de resolver ahora son más fáciles de corregir.
> 

2. ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código?
Explique

> 
> Respuesta:
> 
> Entendiendo la densidad de código como la cantidad de funcionalidad posible por tamaño de instrucción, y basándose en los artículos [Performance, code density and operating states](https://developer.arm.com/documentation/dvi0027/b/arm7tdmi/performance--code-density-and-operating-states) y [The Thumb instruction set](https://developer.arm.com/documentation/ddi0210/c/CACBCAAE), las instrucciones Thumb son un subconjunto de las instrucciones ARM permitiendo la misma funcionalidad pero son almacenadas en un código de 16 bits en lugar de 32 bits, por lo que se dice que son más densas. Su ejecución y tratamiento es transparente en tiempo de ejecución, puesto que estas instrucciones son descomprimidas a instrucciones ARM completas de 32 bits sin pérdida de rendimiento como se puede inferir de la siguiente cita de uno de los articulos mencionados: “Thumb code is typically 65% of the size of ARM code, and provides 160% of the performance of ARM code when running from a 16-bit memory system. Thumb, therefore, makes the ARM7TDMI core ideally suited to embedded applications with restricted memory bandwidth, where code density and footprint is important.”
> 
> Fuentes:
> - [Performance, code density and operating states](https://developer.arm.com/documentation/dvi0027/b/arm7tdmi/performance--code-density-and-operating-states)
> - [The Thumb instruction set](https://developer.arm.com/documentation/ddi0210/c/CACBCAAE)
> 

3. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este
tipo de arquitectura?

> 
> Respuesta:
> 
> Basandome en [Wikipedia](https://en.wikipedia.org/wiki/Load%E2%80%93store_architecture) y el articulo [Memory Instructions: Load and Store](https://azeria-labs.com/memory-instructions-load-and-store-part-4/), una arquitectura load-store es basicamente un modelo seguido por el set de instrucciones (o un sub-set del mismo) para la ejecucion de instrucciones que necesitan acceso a memoria. En este approach solo las instrucciones LDR y STR pueden acceder a memoria de forma directa para traer o almacenar datos cargandolos o leyéndolos de registros del CPU, mientras que el resto de las instrucciones, trabajan solamente con valores almacenados en el CPU. Por lo tanto esta arquitectura no posee instrucciones que operan con valores directamente en memoria de forma.
> La arquitectura opuesta es [register-memory architecture](https://en.wikipedia.org/wiki/Register-memory_architecture) en la que básicamente se permite que las instrucciones trabajen con valores directamente en memoria. 
> Las arquitecturas ARM utilizan el modelo load-store mientras que las x86 register-memory.
> 
> Fuentes:
> - [Wikipedia](https://en.wikipedia.org/wiki/Load%E2%80%93store_architecture)
> - [register-memory architecture](https://en.wikipedia.org/wiki/Register-memory_architecture)
> - [Memory Instructions: Load and Store](https://azeria-labs.com/memory-instructions-load-and-store-part-4/)

4. ¿Cómo es el mapa de memoria de la familia?

> 
> Respuesta: 
> Para ARM Cortex M, basandome en los articulos [ARM Cortex M4 - Memory System Details](https://bravokeyl.com/arm-cortex-m4-memory-system/) y [ARM Cortex-M3 and Cortex-M4 Memory Organization](http://download.mikroe.com/documents/compilers/mikroc/arm/help/memory_organization.htm), el mapa de memoria esta dividido en:
> - System ( 0.5 GB)
> - Private Peripheral Bus - External
> - Private Peripheral Bus - Internal
> - External Device (1 GB)
> - RAM (1 GB)
> - Peripheral (0.5 GB)
> - SRAM (0.5 GB)
> - Code (0.5 GB)
> 
> 
> Fuentes:
> - [ARM Cortex M4 - Memory System Details](https://bravokeyl.com/arm-cortex-m4-memory-system/) 
> - [ARM Cortex-M3 and Cortex-M4 Memory Organization](http://download.mikroe.com/documents/compilers/mikroc/arm/help/memory_organization.htm)
> - [Memory regions table](https://developer.arm.com/documentation/100166/0001/Programmers-Model/Processor-memory-model/Memory-regions-table)
> - [System address map](https://developer.arm.com/documentation/ddi0439/b/Programmers-Model/System-address-map)
> 

5. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP?
6. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y
como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo
privilegiado a no priviligiado y nuevamente a privilegiado.
7. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo
8. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un
ejemplo
9. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).
10. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado
a funciones y su retorno?
11. Describa la secuencia de reset del microprocesador.
12. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de
los periféricos?
13. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo
14. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta?
15. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el
microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo
17. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?
16. Explique las características avanzadas de atención a interrupciones: tail chaining y late
arrival.
17. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la
portabilidad de los sistemas operativos embebidos?
18. ¿Qué funciones cumple la unidad de protección de memoria (MPU)?
19. ¿Cuántas regiones pueden configurarse como máximo? ¿Qué ocurre en caso de haber
solapamientos de las regiones? ¿Qué ocurre con las zonas de memoria no cubiertas por las
regiones definidas?
20. ¿Para qué se suele utilizar la excepción PendSV? ¿Cómo se relaciona su uso con el resto
de las excepciones? Dé un ejemplo
21. ¿Para qué se suele utilizar la excepción SVC? Expliquelo dentro de un marco de un
sistema operativo embebido.

# ISA

1. ¿Qué son los sufijos y para qué se los utiliza? Dé un ejemplo
2. ¿Para qué se utiliza el sufijo ‘s’? Dé un ejemplo
3. ¿Qué utilidad tiene la implementación de instrucciones de aritmética saturada? Dé un
ejemplo con operaciones con datos de 8 bits.
4. Describa brevemente la interfaz entre assembler y C ¿Cómo se reciben los argumentos
de las funciones? ¿Cómo se devuelve el resultado? ¿Qué registros deben guardarse en la
pila antes de ser modificados?
5. ¿Qué es una instrucción SIMD? ¿En qué se aplican y que ventajas reporta su uso? Dé un
ejemplo.
