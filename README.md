# Hipodromo 

tarea de clase enfocada en el desarrollo de una aplicacion que simule un hipodromo de forma lineal.

tarea realizada por Vicente Bastidas, Cristobal Ulloa.

este proyecto esta enfocado desde el punto de vista de programacion orientada a objetos para facilitar la estructura y programacion individual del proyecto. 

## estructura

para el proyecto se usan 2 clases para armar el sistema y una tercera clase especifica para imprimir en la terminal.

### clase conejo 

el objeto conejo representa a cada corredor individual, este posee una forma y una velocidad, luego para poder correr tiene una funcion con el mismo nombre la cual llama para mostrar cuanto se desplazaria

## clase hipodromo 

esta clase aparte de poseer a la clase conejo dentro, esta encargada de gestionar el ambiente de los corredores, proporcionando pistas (llamadas en el codigo dentro del arreglo pos) y una linea de meta, ademas de eso posee funciones destinadas a generar a cada competidor individual el acto de correr, esto hara que el competidor avance y actualiza su posicion. 

## clase menu

esta clase existe para controlar el material impreso en la terminal, consta de una funcion principal, la cual muestra diversas opciones y luego se ramifica en distintas opciones segun lo que solicite el usuario, asi sea cambiar la cantidad de competidores o el largo de la pista