# FORMATO DE FICHERO zdatConfig1Tab al que llamo brevemente ZCONF1
Un fichero ZCONF1 tiene como finalidad proveer datos mediante un fichero plano a una aplicación. La base son parejas `nombre:valor`
## Ejemplo
~~~
#denominacion concentrador
name:Concentrador Internet Cofarcircr
#Pedidos ip:puerto:timeout conexion:timeout respuesta
ped:192.168.1.190:1999:5:20
#Consultas
cons:127.0.0.1:10010
#mysql
sql:127.0.0.1:Pedidosf:Clientes
#almacen
almacen:30
diasReserva:10
#horas reinicio automatico hhmm
reinicio:0200:1500
pedidoRecibido:PEDIDO RECIBIDO
hostDesactivado:HOST DESACTIVADO1
~~~

## Tipos de lineas

**comentario**  
	Linea que comienza con el caracter'#'  
	Estas lineas son ignoradas.

**linea en blanco**  
	Se ignoran las lineas en blanco

**Linea simple**
>etiqueta:texto

Es la típica pareja nombre:valor  
En C se identificaría con:
> char nombre[?]; // La longitud no la sabemos
strcpy(nombre,"valor");

**Linea de lista**
> etiqueta:texto1:texto2:...

Consiste en un nombre y una lista de valores : valor1:valor2 ...
En C se identificaría con un array
> char nombre[?][?];// Desconocemos la longitud del array y la de sus valores
strcpy[nombre[0],"valor1");
...
strcpy[nombre[n],"valorn");

**Linea de Objeto**
>etiqueta:valor1:valor2:valor3:..

Consiste un nombre tiene una serie de valores: valor1:valor2 ...
La diferencia entre Objeto y lista está en que el objeto tiene elementos con significado distinto y en la lista los valores tienen todos el mismo significaco, solo que necesitamos varios valores.
En C se identificaría con una estructura.
> struct nombre_t { // el nombre de la estructura puede no ser obvia
char elemento1[?]; // no sabemos el nombre del elemento ni su longitud
...
char elementon[?]; // no sabemos el nombre del elemento ni su longitud
};
struct nombre_t nombre; // el objeto obviamente si debe llamarse nombre
strcpy(nombre.elemento1,"valor1");
...
strcpy(nombre.elementon,"valorn");

# PARSE FICHERO ZCONF1 EN C. Un acercamiento
Un posible acercamiento a una función que lea un fichero ZCONF1 puede consistir en una función que mediante un parámetro que consista en el nombre de un fichero, nos devuelva una estructura 'rellena' con los datos del fichero.
Supongamos una configuración general com prefijo "general"
~~~
generalEstructura_t *generalParse(char *generalPathfilezconf);
...
generalEstructura_t generalEstructura = generalParse("/home/prueba/general.tab");
~~~
## La estructura
La estructura tiene por supuesto las longitudes y los nombres de objeto que necesite y que no están incluidos en el fichero, aunque pueden estar incluidos en comentarios.
Por ejemplo, el ejemplo arriba incluido, puede tener asociada la siguiente estructura.
~~~
typedef struct {
char ip[20];
char puerto[7];
char timeout1[4];
char timeout2[4];
} ped_t;
~~~
~~~
typedef struct {
char ip[20];
char puerto[7];
} cons_t;
~~~
~~~
typedef struct {
char ip[20];
char tablaPedidos[30];
char tablaClientes[30];
} sql_t;
~~~
~~~
typedef struct {
char name[50];
ped_t ped
cons_t cons;
sql_t sql;
char almacen[2+1];
char diasReserva[3+1];
char reinicio[3][4+1];
char pedidoRecibido[50];
char hostDesactivado[50];
} generalEstructura_t;
~~~

