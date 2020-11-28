#Estructuras de Repetición - Robot cuenta cuartos

![main1.png](images/main1.png)
![main2.png](images/main2.png)
![main3.png](images/main3.png)


Una de las ventajas de utilizar programas de computadoras es que podemos realizar tareas repetitivas fácilmente. Los ciclos como `for`, `while`, y `do-while` son  estructuras de control que nos permiten repetir un conjunto de instrucciones. A estas estructuras también se les llama *estructuras de repetición*.

Los algoritmos son uno de los conceptos más fundamentales en la Ciencia de Cómputos. Dado un pequeño conjunto de instrucciones y las estructuras básicas de programación, podemos resolver una gran cantidad de problemas. En esta experiencia de laboratorio vas a practicar la creación de algoritmos simulando un robot que debe explorar un espacio utilizando un conjunto bien limitado de instrucciones.

##Objetivos:

1. Diseñar algoritmos usando estructuras secuenciales, de decisión y repetición.
2. Analizar el número de pasos de los algoritmos propuestos y tratar de minimizarlos.
3. Practicar la invocación de métodos a un objeto.

Esta experiencia de laboratorio es una adaptación de http://nifty.stanford.edu/2015/tychonievich-sherriff-layer-counting-squares/ .


##Pre-Lab:

Antes de llegar al laboratorio debes haber:

1. Repasado las estructuras básicas de decisión y repetición en C++.
2. Repasado la creación de objetos e invocación de sus métodos.
3. Estudiado los conceptos e instrucciones para la sesión de laboratorio.
4. Tomado el quiz Pre-Lab, disponible en Moodle.


---

---


## Robot cuenta cuartos

En esta experiencia de laboratorio estaremos programando un robot que ha sido puesto en una cuadrícula (grid) de habitaciones cuadradas. Cada una de las cuatro paredes de cada cuarto puede tener una puerta. Solo las paredes que colindan con otros cuartos tienen puertas. Las paredes que forman la parte exterior de la cuadrícula  no tienen puertas.

---

![](images/cuarto.png)

**Figura 1.** El robot está en el cuarto en el extremo superior izquierdo de la cuadrícula de 36 cuartos.

---

Los únicos comandos que entiende el robot son:

1. Verificar si hay una puerta en la pared del norte (N), sur (S), este (E) u oeste (W) del cuarto donde se encuentra.
2. Moverse al cuarto que queda justo al norte (N), sur (S), este (E) u oeste (W) del cuarto actual.
4. Crear variables y asignarle valores.
3. Realizar operaciones de suma, resta, multiplicación y división.
5. Usar estructuras de decisión y repetición.
6. Desplegar resultados a pantalla.


## Objetos y métodos

A continuación mostramos la función `main` de un programa básico como el que estarás creando. Durante esta experiencia de laboratorio solo tienes que programar la función `main` (dentro del archivo `main.cpp`). Los demás archivos contienen funciones que implementan la funcionalidad de las instrucciones que entiende el robot.

---

```cpp
int main(int argc, char *argv[]) {
    QApplication   a(argc, argv);

    // Crear la cuadrícula y robot
    MainGameWindow *w = new MainGameWindow(Mode::RECT_RANDOM);
    w->show();

    // Mostrar la palabra "Start"
    w->display("Start");

    // Mover el robot hacia el oeste cuanto se pueda
    // mientras contamos el número de movidas

    int ctr = 0;
    while (w->canMove('W')) {
        w->moveRobot('W');
        ctr = ctr + 1;
    }

    // Desplegar el total de movidas
    w->display("Total: " + QString::number(ctr));

    return a.exec();
}
```

**Figura 2** Ejemplo de una función `main`.

---

En el ejemplo estamos creando un robot dentro de un espacio cuadrado que solo sabe verificar si hay una puerta hacia el oeste y (si hay puerta) caminar hacia esa misma dirección.  Veamos la función, línea por línea.

La primera línea crea el único objeto que debes crear, un objeto de clase `MainGameWindow`. El parámetro `Mode::SQUARE_TOP_LEFT` especifica que la cuadrícula será un cuadrado y que el robot comenzará en la esquina superior izquierda. Otras opciones para el parámetro son `RECT_TOP_LEFT`, `RECT_RANDOM` y `PYRAMID_RANDOM`.

`MainGameWindow *w = new MainGameWindow(Mode::SQUARE_TOP_LEFT);`

La siguiente es para mostrar el objeto `w`.

`w->show();`

El método `void display(QString)` sirve para desplegar mensajes cortos a la pantalla. Por ejemplo:

`w->display("Start");`


muestra la palabra "Start" antes de comenzar a mover el robot. El pedazo de código que le sigue:

```cpp
int ctr = 0;
while ( w->canMove('W') ) {
    w->moveRobot('W');
    ctr = ctr + 1;
}
```

ilustra el uso de los métodos `bool canMove(char)` y `void moveRobot(char)`:

* `bool canMove(char)` - acepta como parámetro una de las siguientes letras: `'N'`, `'S'`, `'E'` o `'W'` y devuelve `true` si existe una puerta en esa dirección del cuarto donde se encuentra el robot.
* `void moveRobot(char)` - acepta como parámetro una de las letras `'N'`, `'S'`, `'E'` o `'W'` y mueve el robot al cuarto próximo que se encuentra en esa dirección.

En el ejemplo, el código está tratando de mover al robot todas las veces que pueda hacia el oeste (`W`) y contándo cada cuarto en esa dirección.

---

---

!INCLUDE "../../eip-diagnostic/repetitions-countingsquares/es/diag02.html" 
<br>

!INCLUDE "../../eip-diagnostic/repetitions-countingsquares/es/diag01.html" 
<br>


---

---


## Sesión de laboratorio:

### Ejercicio 1 - Cuadrícula cuadrada de cuartos

Supón que el robot se encuentra en el cuarto superior izquierdo (extremo noroeste) de un espacio **cuadrado** de cuartos, i.e. el espacio contiene igual número de filas y columnas de cuartos (como el de la Figura 1). Diseña un algoritmo para que el robot pueda computar el número de cuartos que hay en la cuadrícula.

#### Instrucciones

1. Carga a `QtCreator` el proyecto `CountingSquares`. Hay dos maneras de hacer esto:

    * Utilizando la máquina virtual: Haz doble “click” en el archivo `CountingSquares.pro` que se encuentra  en el directorio `/home/eip/labs/repetitions-countingsquares` de la máquina virtual.
    * Descargando la carpeta del proyecto de `Bitbucket`: Utiliza un terminal y escribe el comando `git clone http:/bitbucket.org/eip-uprrp/repetitions-countingsquares` para descargar la carpeta `repetitions-countingsquares` de `Bitbucket`. En esa carpeta, haz doble “click” en el archivo `CountingSquares.pro`.

2. Configura el proyecto. El proyecto consiste de varios archivos. **Solo escribirás código en el archivo** `main.cpp`. Los demás archivos contienen funciones que implementan la funcionalidad de las instrucciones que entiende el robot.

3. Al escribir tu algoritmo debes asegurarte de que el objeto `MainGameWindow` es creado usando el argumento `Mode::SQUARE_TOP_LEFT`.  Recuerda, el robot no sabe de antemano cuántos cuartos hay. Prueba tu algoritmo con algunos ejemplos.

4. Si el tamaño de la cuadrícula es 3x3, ¿cuántos cuartos debe visitar el robot para completar tu algoritmo? ¿Qué tal 4x4? ¿Qué tal $$n \times n$$ cuartos?

5. Presume que deseamos ahorrar la cantidad de energía que utiliza el robot. ¿Puedes hacer un algoritmo que utilice menos movidas para el mismo tamaño de cuadrícula?

6. Una vez hayas terminado el algoritmo, lo hayas hecho correcto y eficiente, entrégalo usando Entrega 1 en Moodle. En el encabezado del algoritmo escribe y explica la expresión que hallaste sobre cuántos cuartos debe visitar el robot para completar su tarea para una cuadrícula $$n \times n$$ (algo así como "El robot toma 2n+5 movidas, 5 para llegar al medio y 2n para contar el resto")


### Ejercicio 2 -  Cuadrícula rectangular de cuartos

#### Instrucciones

1. Supón que ahora el robot se encuentra en el cuarto superior izquierdo (extremo noroeste) de un espacio **rectangular**  (no necesariamente cuadrado) de cuartos. Diseña un algoritmo para que el robot pueda computar el número de cuartos que hay en la cuadrícula.

2. Para probar esta parte en programación debes asegurarte que objeto `MainGameWindow` es creado usando el argumento `Mode::RECT_TOP_LEFT`.

3. Una vez hayas terminado el algoritmo, lo hayas hecho correcto y eficiente, impleméntalo en la función `main`. En el encabezado del programa escribe y explica la expresión que hallaste sobre cuántos cuartos debe visitar el robot para completar su tarea en una cuadrícula $$m \times n$$. 

4. Entrega el archivo `main.cpp` con el código para calcular el número de cuartos del rectángulo usando Entrega 2 en Moodle.

### Ejercicio 3 - Cuadrícula rectangular de cuartos, posición aleatoria

#### Instrucciones

1. Supón que ahora el robot comienza su recorrido en cualquiera de los cuartos de una cuadrícula **rectangular** (no necesariamente cuadrada).  Diseña un algoritmo para que el robot pueda computar el número de cuartos que hay en la cuadrícula.

2. Para probar esta parte en programación debes asegurarte que objeto `MainGameWindow` es creado usando el argumento `Mode::RECT_RANDOM`.

3. Una vez hayas terminado el algoritmo, lo hayas hecho correcto y eficiente, impleméntalo en la función `main`. En el encabezado del programa escribe y explica la expresión que hallaste sobre cuántos cuartos debe visitar el robot para completar su tarea en una cuadrícula $$m \times n$$. En este caso, el número de cuartos a visitar va a depender de la posición inicial del robot, así que expresa el peor de los casos, i.e. ¿cuántos cuartos debe visitar tu algoritmo si el robot comienza en el *peor* de los cuartos. 

4. Entrega el archivo `main.cpp` con el código para calcular el número de cuartos del rectángulo con robot en posición aleatoria usando Entrega 3 en Moodle.



### Ejercicio 4 -  Cuadrícula en forma de pirámide, posición aleatoria

#### Instrucciones

1. Supón que ahora el robot comienza su recorrido en cualquiera de los cuartos de una cuadrícula en forma de pirámide.  Diseña un algoritmo para que el robot pueda computar el número de cuartos que hay en la cuadrícula.

2. Para probar esta parte en programación debes asegurarte que objeto `MainGameWindow` es creado usando el argumento `Mode::PYRAMID_RANDOM`.

3. Una vez hayas terminado el algoritmo, lo hayas hecho correcto y eficiente, impleméntalo en la función `main`. En el encabezado del programa escribe y explica la expresión que hallaste sobre cuántos cuartos debe visitar el robot para completar su tarea en una cuadrícula $$m \times n$$. En este caso, el número de cuartos a visitar va a depender de la posición inicial del robot, así que expresa el peor de los caso, i.e. ¿cuántos cuartos visitaría tu algoritmo si el robot comienza en el *peor* de los cuartos.

4. Entrega el archivo `main.cpp` con el código para calcular el número de cuartos de la pirámide con robot en posición aleatoria usando Entrega 4 en Moodle.



---

---

## Entregas

Utiliza los enlaces "Entrega" en Moodle para entregar el algoritmo del Ejercicio 1 y los  archivos `main.cpp` que contienen el código que implementaste en los ejercicios 2, 3 y 4. Recuerda utilizar buenas prácticas de programación, incluye el nombre de los programadores y documenta tu programa.



---

---

## Referencias

[1] Luther A. Tychonievich, Mark S. Sherriff, and Ryan M. Layer, http://nifty.stanford.edu/2015/tychonievich-sherriff-layer-counting-squares/


