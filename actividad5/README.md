## Tipos de Kernel y sus Diferencias

### Kernel Monolítico
- **Qué es**: Un kernel monolítico es como un gran todo-en-uno para el sistema operativo. Todo, desde los controladores hasta la gestión de memoria, está en un solo lugar.
- **Ventajas**: Funciona muy rápido porque todo está integrado y no hay mucha comunicación entre diferentes partes.
- **Desventajas**: Si algo falla, puede afectar a todo el sistema porque todo está junto.
- **Ejemplos**: Linux, Unix.

### Microkernel
- **Qué es**: En un microkernel, solo las funciones básicas están en el núcleo del sistema. Todo lo demás, como los controladores y los sistemas de archivos, están en un espacio separado.
- **Ventajas**: Es más estable porque si algo falla fuera del núcleo, el sistema sigue funcionando. También es más fácil de actualizar.
- **Desventajas**: Puede ser un poco más lento porque las partes tienen que hablar entre ellas constantemente.
- **Ejemplos**: Minix, QNX.

### Kernel Híbrido
- **Qué es**: Un kernel híbrido combina lo mejor de los kernels monolíticos y microkernels. Intenta ser rápido y flexible al mismo tiempo.
- **Ventajas**: Ofrece un buen equilibrio entre velocidad y flexibilidad.
- **Desventajas**: Puede ser complicado de crear y mantener.
- **Ejemplos**: Windows NT, macOS.

## Modo de Usuario vs Modo de Núcleo

- **Modo de Usuario**:
  - **Qué es**: Aquí es donde corren las aplicaciones que usamos todos los días, como los navegadores web. Estas aplicaciones no pueden tocar directamente el hardware o la memoria del sistema.
  - **Ventajas**: Mantiene el sistema más seguro porque las aplicaciones no pueden causar daños graves.
  - **Desventajas**: Las aplicaciones necesitan pedir al sistema operativo que haga ciertas cosas, lo que puede ser un poco más lento.

- **Modo de Núcleo**:
  - **Qué es**: Es el modo donde el sistema operativo y los controladores de hardware trabajan. Aquí, el software tiene acceso completo a todo el hardware y a la memoria.
  - **Ventajas**: Permite un control total sobre el sistema.
  - **Desventajas**: Si algo falla aquí, puede causar un desastre en todo el sistema.

## Interrupciones vs Trampas

- **Interrupciones**:
  - **Qué son**: Son señales que el hardware o el software envían para avisar al procesador de que necesita hacer algo de inmediato. Por ejemplo, cuando presionas una tecla o llega información nueva por la red.
  - **Ejemplos**: La señal de un teclado o una notificación de un disco duro.

- **Trampas**:
  - **Qué son**: Son eventos inesperados que el procesador detecta mientras está ejecutando un programa. Pueden ser errores o situaciones especiales que el sistema necesita manejar.
  - **Ejemplos**: Dividir un número por cero, errores de memoria, o una llamada especial al sistema operativo.
