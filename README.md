# La criba de Eratóstenes

## 0.- Introducción
La criba de Eratóstenes es un antiguo método para hallar números primos.
Se escribe una lista de todos los números naturales.
Comenzando por el 2, se tachan de la lista todos los mayores que 2 que están separados 2 posiciones (se tachan así todos los múltiplos de 2).
A continuación se localiza el siguiente número en la lista, que es primo, el 3. Se tachan a continuación todos los múltiplos de 3.
Se localiza el siguiente número, que es primo, el 5...

Siguiendo este proceso se obtiene una lista en la que los únicos números no tachados son los primos.

## 1.- Ejercicio

### Ejercicio práctico
Diseñar un programa en C++ (erathostenes.cc) que imprima en pantalla una lista de números primos. El programa se invocará (por ejemplo) como:

`./erathostenes 1000`

En este caso particular el programa imprimirá en pantalla todos los números primos menores o iguales que 1000.

El programa seguirá las siguientes especificaciones:

- El programa leerá por línea de comandos un número natural `N` que será el número de valores que inicialmente contendrá la lista. Utilizará alguna estructura de datos para almacenar los `N` valores `[1..N]` iniciales en orden ascendente.
- Todos estos números **son considerados inicialmente primos**.
- La función `Sieve` operará sobre la lista de valores e irá marcando en ella como **no primos** los múltiplos de 2, los de 3, los de 5, etc.
- Para ello localizará un valor que sea primo e invocará la función `Remove` que marcará desde ese punto de la lista en adelante todos los valores múltiplos del elegido, como no primos. Utilice una función adicional para eliminar de la lista todos los números que que no sean primos.
- Desarolle también una función que permita imprimir en pantalla en cualquier momento el estado de la lista. Esta función escribirá cada uno de los valores presentes en la lista indicando si es primo o no.

### Razonamiento del ejercicio
0. Trabajaremos con el tipo [unsigned](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Programming_Languages/C%2B%2B/Code/Keywords/unsigned#:~:text=The%20unsigned%20keyword%20is%20a,values%20from%200%20to%2065535.) ya que todos los primos son naturales, y nos permite trabajar con un rango entre 0 y 65535.
1. Una vez leído el valor del argumento de comandos, procedemos a crear una estructura de `N` elementos y la rellenamos presumiendo que todos son primos (true).
2. Usaremos un [vector](http://www.cplusplus.com/reference/vector/vector/) de [pares](https://www.geeksforgeeks.org/pair-in-cpp-stl/) al que llamaremos primeHolder.
3. Partiremos de la posición 1 ya que 1 (0) no es primo, 2 es primo (1), 3 lo es (2), etc.
4. En nuestra lista, marcaremos como `false` todos aquellos múltiplos del primo seleccionado y los marcamos como `falso`, pasamos al siguiente, ...
5. Eliminamos todos los no primos de nuestro vector de pares, redimensionándolo.
6. Una vez finalizada la lista procederemos a mostrar aquellas casillas especificando como primas aquellas que tengan valor `true` y no primas en caso `false`.
