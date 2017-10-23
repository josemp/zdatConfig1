# zdatConfig1
Un tipo de ficheros que desde hace muchos años utilizo para configuración de programas en C, tiene esta pinta:
~~~
nombre: Este es el nombre de la utilidad
# tiempo de reinicio
reinicio:1205:2003
# ip:puerto:timeout conexion:timeout envio
server:18.12.34.34:2341:2:5
~~~
Este proyecto simplemente trata de definir este tipo de ficheros y de crear una utilidad que **genere los programas necesarios para manejar este tipo de ficheros**

Trata de tipo de ficheros que llamo **ZCONF1** pensados para configuración. Su descripción y utilidades para su uso.

## Contenido
* carpeta **zdatConfig1Tab** 
[Documento con la descripción del formato de los ficheros ZCONF1][TAB_ZCONF1]

* carpeta **zdatConfig1TabMeta** 
[Documento con la descripción 'META' de ficheros ZCONF1][META_ZCONF1]

* carpeta **zConf1** 
[Fuentes de la utilidad zConf1 generadora de programas ZCONF1][ZCONF1]

* carpeta **zdatConfig1Example** 
[Ejemplo generado con la utilidad zConf1 ZCONF1][EXAMPLE_ZCONF1]

# ¿Que puedes conseguir con este proyecto?
Este proyecto contiene los fuentes de una utilidad llamada [zconf1][ZCONF1], mediante la cual, construyendo un [fichero de texto meta][META_ZCONF1] que describe un [fichero de texto de tipo configuración][TAB_ZCONF1] generamos un API (C LIBRARY) personalizada para [el tipo de fichero diseñado][EXAMPLE_ZCONF1] 


[TAB_ZCONF1]: zdatConfig1Tab/readme.md "Descripción del formato de ficheros ZCONF1"
[META_ZCONF1]: zdatConfig1TabMeta/readme.md "Descripción del formato de ficheros META_ZCONF1"
[ZCONF1]: zConfig1/README.md "Fuentes en C para la generación de programas de manejo de ficheros ZCONF1"
[EXAMPLE_ZCONF1]: zdatConfig1Example/README.md "Ejemplo de uso de la utilidad ZCONF1. Fuentes, Descripción y Uso" 
