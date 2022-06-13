
# Cortex M

1. Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4.

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

2. ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código? Explique

> 
> Respuesta:
> 
> Entendiendo la densidad de código como la cantidad de funcionalidad posible por tamaño de instrucción, y basándose en los artículos [Performance, code density and operating states](https://developer.arm.com/documentation/dvi0027/b/arm7tdmi/performance--code-density-and-operating-states) y [The Thumb instruction set](https://developer.arm.com/documentation/ddi0210/c/CACBCAAE), las instrucciones Thumb son un subconjunto de las instrucciones ARM permitiendo la misma funcionalidad pero son almacenadas en un código de 16 bits en lugar de 32 bits, por lo que se dice que son más densas. Su ejecución y tratamiento es transparente en tiempo de ejecución, puesto que estas instrucciones son descomprimidas a instrucciones ARM completas de 32 bits sin pérdida de rendimiento como se puede inferir de la siguiente cita de uno de los articulos mencionados: “Thumb code is typically 65% of the size of ARM code, and provides 160% of the performance of ARM code when running from a 16-bit memory system. Thumb, therefore, makes the ARM7TDMI core ideally suited to embedded applications with restricted memory bandwidth, where code density and footprint is important.”
> 
> Fuentes:
> - [arm Developer - Performance, code density and operating states](https://developer.arm.com/documentation/dvi0027/b/arm7tdmi/performance--code-density-and-operating-states)
> - [arm Developer - The Thumb instruction set](https://developer.arm.com/documentation/ddi0210/c/CACBCAAE)
> 

3. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?

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
> - [arm Developer - Memory regions table](https://developer.arm.com/documentation/100166/0001/Programmers-Model/Processor-memory-model/Memory-regions-table)
> - [arm Developer - System address map](https://developer.arm.com/documentation/ddi0439/b/Programmers-Model/System-address-map)
> 

5. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP?

> Primero, MSP (Main Stack Pointer) y PSP (Processor Stack Pointer) son dos registros de los Cortex M usados como stack pointers, MSP usado en Thread mode cuando el bit de CONTROL (SPSEL) esta en cero pero usado siempre en Handler Mode. PSP por otro lado usadoen Thread Mode cuando el bit de CONTROL (SPSEL) esta en 1.
>  
> Fuentes:
> [Main Stack Pointer](https://www.sciencedirect.com/topics/engineering/main-stack-pointer)
>  


6. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado.

> 
> Respuesta: 
> Los modos en los que el procesador puede operar son Thread -modo normal de operacion con dos niveles de privilegios en el que el micro inicia y al que se vuelve luego de procesar excepciones, se puede utilizar el stack principal o uno alternativo si el sistema se configura para eso- y Handler -modo privilegiado en el que se utiliza el stack principal y se encuentra cuando esta procesando una excepcion-. Como se menciono antes, en el modo Thread existen dos niveles de privilegio: Privilegiado -puede acceder a todos los recursos- y No-Privilegiado -el acceso se restringe a ciertos recursos necesarios para la operacion del sistema. 
> 

7. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo
> 
> Respuesta:
> La ortogonalidad en el modelo de registros significa que la arquitectura soporta que todos los tipos de instrucciones del procesador pueden utilizar todos los modos de direccionamiento. Por lo tanto es "ortogonal" en el sentido de que el tipo de instruccion y el modo de direccionamiento varian independientemente, no imponiendo una limitacion de requerir una determinada instruccion para utilizar un registro especifico permitiendo entonces menor superposicion de la funcionalidad entre las instrucciones.
>  

8. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo

> 
> Respuesta:
> Las instrucciones condicionales que comienzan con IT permiten ejecutar logica condicional de hasta cuatro instrucciones de la forma if-then-then-*-else.
> Por ejemplo si quisieramos ejecutar la siguiente logica condicional:
> 
>  //
>  // codigo C
>  // 
>  if(EQ) {
>  	MOV R0,R1
> 	ADD R2,R2,10
>  } else {
> 	AND R3,R3,1
>  }
> 
> Hariamos:
> 
>  @
>  @ codigo assembler
>  @
>  ITTEE  EQ
>  MOVEQ  R0, R1
>  ADDEQ  R2, R2, #10
>  ANDNE  R3, R3, #1
> 
> Fuentes:
> - [Conditional Execution](https://azeria-labs.com/arm-conditional-execution-and-branching-part-6/)
> 

9. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).

10. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?

11. Describa la secuencia de reset del microprocesador.

> 
> Respuesta:
> La secuencia de reset es:
> 1. Despues de lanzado el reset, el PC (contador de programa) es cargado con la direccion 0x00000000
> 2. El procesador lee el valor de esa direccion de memoria y lo guarda en MSP (stack pointer)
> 3. El procesador lee la direccion del handler de reset de la direccion de memoria 0x00000004 y la guarda en el PC
> 4. El procesador comienza a ejecutar las rutinas del handler de reset saltando a la primer instruccion
> 5. Luego de la ejecucion del handler se invoca a la funcion main del programa
> 
> Por lo anterior se espera que el programador defina el handler de reset con la logica necesaria para ser ejecutada previa al main y que ponga la direccion de memoria correcta del MSP en la posicion 0x00000000.
> 
> Fuentes:
> - [Youtube Video: ARM Cortex M3/M4 Processor Reset Sequence ](https://www.youtube.com/watch?v=qMH2MBGuG3E)
> 

12. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de los periféricos?
> 
> Respuesta:
> 
> 
> Fuentes:
> - []()
> - []()
> 
13. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo
> 
> Respuesta:
> 
> 
> Fuentes:
> - []()
> - []()
> 
14. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta?
> 
> Respuesta:
> 
> El Cortex Microcontroller Software Interface Standard (CMSIS) proporciona un framework para el desarrollo de sistemas embebidos basados ​​en Cortex-M y Cortex-A5/A7/A9. Se inició en 2008 en cooperación con varios proveedores de software y silicio. CMSIS permite interfaces de software uniformes y sencillas para el procesador y los periféricos, lo que simplifica la reutilización del software y reduce la curva de aprendizaje para los desarrolladores de sistemas embebidos.
> 
> Consta de varios componentes internos, que solo para mencionar algunos de sus modulos:
> - CMSIS-RTOS
> - CMSIS-NN
> - CMSIS-DSP
> - CMSIS-Driver
> - CMSIS-CORE
> - CMSIS-SVD
> - CMSIS-DAP
> - CMSIS-Zone
> 
> Dentro de las ventajas se pueden mencionar: 
> - que al ser un conjunto de componentes, herramientas, APIs, etc, ayuda a reducir la curva de aprendizaje, los costos de desarrollo, y el time-to-market
> - los componentes utilizan interfaces consistentes por lo cual se mejora la portabilidad
> - brinda interfaces y herramientas de debug estandarizadas y probadas
> - existe una gran comunidad utilizandolo, con lo cual es facil encontrar documentacion y referencias
> 
> Fuentes:
> - [CMSIS](https://www2.keil.com/mdk5/cmsis)
> - []()
> 


15. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo

> 
> Respuesta:
> 
> 
> Fuentes:
> - [arm Developer - Handling Interrupts](https://developer.arm.com/documentation/198123/0302/Handling-interrupts?lang=en)
> - [A Practical guide to ARM Cortex-M Exception Handling](https://interrupt.memfault.com/blog/arm-cortex-m-exceptions-and-nvic)


16. Explique las características avanzadas de atención a interrupciones: tail chaining y late arrival.

17. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la portabilidad de los sistemas operativos embebidos?

> 
> Respuesta:
> El systick es una interrupción  generada cada un intervalo establecido por un timer en el procesador. Se utiliza para establecer una forma de medir el tiempo y es posible asociarle interrupciones para ser lanzadas por cada tick. Se puede decir que favorece a la portabilidad de los sistemas operativos embebidos, en realidad a la portabilidad de cualquier sistema operativo, porque sirve de capa de abstraccion para que el software del sistema operativo acceda a esta funcionalidad como un servicio en lugar de tener que estar implementando una logica para medir el tiempo. De esta manera las implementaciones de sistemas operativos que se apalancan sobre el consumo del systick provisto por el hardware resultan mas portables que si lo intentaran implementar nativamente. 
> 
> 

17. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?

18. ¿Qué funciones cumple la unidad de protección de memoria (MPU)?

> 
> Respuesta:
> 
> MPU es una versión reducida de la unidad de administración de memoria (MMU) que solo brinda soporte de protección de memoria. Se implementa en procesadores de baja potencia que solo requieren protección de memoria y no necesitan la función completa de una unidad de administración de memoria como la administración de memoria virtual. 
> La MPU permite que el software privilegiado defina regiones de memoria y les asigne permisos de acceso y atributos, para luego monitorear las transacciones, incluida la obtención de instrucciones y el acceso a datos desde el procesador, lanzando una excepción de falla cuando se detecta una infracción de acceso. Por lo tanto, el objetivo principal de la protección de la memoria es evitar que un proceso acceda a la memoria que no se le ha asignado. Esto evita que un error o malware dentro de un proceso afecte a otros procesos o al propio sistema operativo.
> 
> Fuentes:
> - [arm Developer - About the MPU](https://developer.arm.com/documentation/ddi0363/e/memory-protection-unit/about-the-mpu)
> - [Unidad de Proteccion de Memoria](https://hmong.es/wiki/Memory_protection_unit)

19. ¿Cuántas regiones pueden configurarse como máximo? ¿Qué ocurre en caso de haber solapamientos de las regiones? ¿Qué ocurre con las zonas de memoria no cubiertas por las regiones definidas?

> 
> Respuesta:
> 
> El numero de regiones depende del procesador, por ejemplo en procesadores ARMv8-M admite hasta 16 regiones. Sobre los solapamientos, puede haber dos o mas regiones solapadas con permisos y atributos de ambas regiones, para lo cual se aplica un esquema de prioridad fija para deter.minar los atributos y permisos que debe considerarse para esa zona de solapamiento. Los atributos y permisos para la region 11 tiene mayor prioridad  mientras que para la region 0 la menor prioridad. Finalmente, si se intenta acceder a una zona no cubierta o definida como parte de una region el procesador aborta el acceso. Todo acceso a una zona no mapeada en el MPU hace que produce  una 'background' fault.
> 
> Fuentes: 
> - [arm Developer - Overlaping Regions](https://developer.arm.com/documentation/ddi0363/e/memory-protection-unit/about-the-mpu/overlapping-regions)
> - [arm Developer - Background Regions](https://developer.arm.com/documentation/ddi0363/e/memory-protection-unit/about-the-mpu/background-regions)

20. ¿Para qué se suele utilizar la excepción PendSV? ¿Cómo se relaciona su uso con el resto de las excepciones? Dé un ejemplo

21. ¿Para qué se suele utilizar la excepción SVC? Expliquelo dentro de un marco de un sistema operativo embebido.

# ISA

1. ¿Qué son los sufijos y para qué se los utiliza? Dé un ejemplo
2. ¿Para qué se utiliza el sufijo ‘s’? Dé un ejemplo
3. ¿Qué utilidad tiene la implementación de instrucciones de aritmética saturada? Dé un ejemplo con operaciones con datos de 8 bits.

> Respuesta: 
> Las instrucciones de aritmetica saturada permiten establecer limites por software (máximos y minimos) para acotar y converger resultados en operaciones aritmeticas. Esto evita probelmas como overflow/underflow
> 

4. Describa brevemente la interfaz entre assembler y C ¿Cómo se reciben los argumentos de las funciones? ¿Cómo se devuelve el resultado? ¿Qué registros deben guardarse en la pila antes de ser modificados?
5. ¿Qué es una instrucción SIMD? ¿En qué se aplican y que ventajas reporta su uso? Dé un ejemplo.
