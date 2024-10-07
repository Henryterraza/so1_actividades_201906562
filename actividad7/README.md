# ¿Qué es CFS?
El Completely Fair Scheduler (CFS) es el planificador de tareas que usa Linux para asegurarse de que todos los programas obtengan una cantidad justa de tiempo en el procesador.

### Características Principales

* **Equidad:**

    CFS trata de que cada programa reciba el mismo tiempo de CPU, evitando que alguno se quede sin recursos.

* **Árbol Rojo-Negro:**

    Utiliza un tipo de lista especial llamada árbol rojo-negro para organizar los programas que necesitan ejecutarse, asegurando que todo sea rápido y eficiente.

* **Comportamiento Asintótico:**

    Cada programa tiene un contador llamado vruntime, que mide cuánto tiempo ha estado en el procesador. CFS siempre elige el programa con el vruntime más bajo, es decir, el que ha recibido menos tiempo hasta ahora.

### ¿Cómo Funciona?
* **Tiempo de Ejecución Virtual:**

    CFS monitorea cuánto tiempo ha recibido cada programa (con el vruntime) y elige el que menos ha sido ejecutado, así todos tienen su oportunidad.

* **Selección del Proceso:**

    Los programas se almacenan en el árbol rojo-negro, lo que facilita encontrar al que menos tiempo ha tenido para ejecutarse y permitirle correr.

* **Interacción con la Prioridad:**

    Si un programa tiene más prioridad (por ejemplo, uno que el sistema considera más importante), su vruntime sube más lentamente, permitiéndole más tiempo de CPU.
* **Duración de los Tiempos de Slot:**

    Cada programa se ejecuta por un rato, y luego CFS revisa si es momento de cambiar a otro. Trata de hacer esto de la forma menos disruptiva posible.

* **Granularidad:**

    Para evitar que el procesador esté cambiando de tarea todo el tiempo, CFS define un tiempo mínimo para que cada programa pueda ejecutarse antes de pasar al siguiente.