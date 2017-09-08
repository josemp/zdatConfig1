# zdatConfig1TabMeta
## FORMATO META DE [FICHEROS ZCONF1][ZCONF1]
Un [fichero ZCONF1][ZCONF1] tiene como finalidad proveer datos mediante un fichero plano a una aplicación. La base son parejas `nombre:valor`.

Un fichero [META ZCONF1][META ZCONF1]  tiene como finalidad proveer la configuración de un fichero [ZCONF1][ZCONF1] , para ayudar a su carga y verificación.

Cada linea del fichero **META_ZCONF1**  describe un tipo de linea permitida en el fichero [ZCONF1][ZCONF1].
El fichero **META_ZCONF1** tiene formato [ZCONF1][ZCONF1].

## Ejemplo de fichero META_ZCONF1
~~~
name:C:50
ped:O:ip:20:puerto:6:timeutConexion:6:timeoutRespuesta:6
cons:O:ip:20:puerto:6
reinicio:L:3:7
~~~
Este fichero describe un fichero [ZCONF1][ZCONF1] de este formato:
~~~
name:Este es el name
#ped:ip:puerto:timeutConexion:timeoutRespuesta
ped:192.168.10.11:12:40
#cons:ip:puerto
cons:192.168.1.34:1222
#reinicio:L:3
reinicio:1222:1428:0300
~~~
## Lineas del fichero META_ZCONF1
Las lineas del fichero meta, tienen el siguiente formato
~~~
etiqueta:tipo:datos
~~~
donde **tipo** es un caracter que describe el tipo de linea.
~~~
# linea tipo C
name:C:50
#linea tipo O
ped:O:ip:20:puerto:6:timeutConexion:6:timeoutRespuesta:6
# linea tipo O
cons:O:ip:20:puerto:6
# linea tipo L
reinicio:L:3:7
~~~
## Tipos de lineas

**comentario**  
	Linea que comienza con el caracter'#'  
	Estas lineas son ignoradas.

**linea en blanco**  
	Se ignoran las lineas en blanco
	
**Linea Char**
`etiqueta:C:longitud`
Define una linea simple en el fichero [ZCONF1](https://github.com/josemp/zdatConfig1Tab)
`etiqueta:texto`
La longitud es la máxima longitud permitida de texto.
Identificación en C:
`char nombre[len];`

**Linea List**
`etiqueta:L:longitud list:longitud string`
Define una linea de lista en el fichero [ZCONF1](https://github.com/josemp/zdatConfig1Tab)
`etiqueta:texto1:texto2:...`
La `longitud list` es el número de items (lenl).
La `longitud string` es la máxima longitud permitida de texto (lens).
Identificación en C:
`char nombre[lenl][lens];`

**Linea Objeto**
`etiqueta:O:eti1:len1:eti2:len2...`
Define una linea de objeto en el fichero ZCONF1
`etiqueta:texto1:texto2:...`
La `eti1` es el nombre o etiqueta del valor 1 del objeto.
La `len1` es la máxima longitud permitida del valor del item 1 del objeto.
Identificación en C:
~~~
struct nombre_t { 
 char eti1[len1]; 
 ...
 char etin[len]; 
};
~~~
# PARSE FICHERO ZCONF1 EN C con ayuda del fichero META ZCONF1. Un acercamiento
Según vimos en la documentación del fichero ZCONF1, Un posible acercamiento a una función que lea un fichero ZCONF1 puede consistir en una función que mediante un parámetro que consista en el nombre de un fichero, nos devuelva una estructura 'rellena' con los datos del fichero.
El fichero META ZCONF1 permite definir perfectamente la estructura de carga del fichero.

## La estructura del fichero ZCONF1, con la ayuda del fichero META ZCONF1
Del ejemplo arriba descrito, podemos generar completamente la estructura de un fichero ZCONF1.

La estructura tiene por supuesto las longitudes y los nombres de objeto que necesite y que no están incluidos en el fichero, aunque pueden estar incluidos en comentarios.
Por ejemplo, el ejemplo arriba incluido, puede tener asociada la siguiente estructura.
~~~
typedef struct {
char ip[20+1];
char puerto[6+1];
char timeout1[6+1];
char timeout2[6+1];
} ped_t;
~~~
~~~
typedef struct {
char ip[20+1];
char puerto[6+1];
} cons_t;
~~~
~~~
typedef struct {
char name[50];
ped_t ped
cons_t cons;
char reinicio[3][7+1];
} generalEstructura_t;
~~~


[ZCONF1]: https://github.com/josemp/zdatConfig1Tab "EN GITHUB"
[META ZCONF1]: https://github.com/josemp/zdatConfig1TabMeta "EN GITHUB"
