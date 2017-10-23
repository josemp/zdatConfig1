# zConfig1
Utilidad para generar c-libreria estática para leer ficheros de formato [ZCONF1][TAB_ZCONF1]
Inicialmente concebido para linux y programado en C
## Introducción
Este proyecto contiene los fuentes de una utilidad llamada [zconf1][ZCONF1], mediante la cual, construyendo un [fichero de texto meta][META_ZCONF1] que describe un [fichero de texto de tipo configuración][TAB_ZCONF1] generamos un API (C LIBRARY) personalizada para [el tipo de fichero diseñado][EXAMPLE_ZCONF1] 

Una vez generada la utilidad, si necesitamos un [fichero de texto de tipo configuración][TAB_ZCONF1], podemos generar la API para programar dicho fichero de este modo:
Prefijo : tablaConf // Elegimos un prefijo que identifique la tabla
Fichero Meta : tablaConfMeta.tab // Creamos el fichero meta que describa la tabla
Generación : ejecutamos #zconfig1 tablaConf

Esto generara un API para manejar el fichero.

NOTA. La API también gestiona LISTAS : ficheros con lineas que cumplen la especificacion META.

## Contenido

### programa zconfig1
`zconfig1.c`    - Programa Main de la utilidad.  
`metaTab.h`	    - Estructuras meta de las tablas meta.  
`metaTab.c`	    - Funciones de lectura del contenido de una tabla meta.  
`metaTabAdd.h`,`metaTabAdd.c`  - Funciones Add para la generacion de las estructuras meta.  
`metaTabLee.c`	- Funcion de lectura de una tabla meta hacia las estructuras meta.  
`metaTabLimpia.c`	    - Funciones auxiliares de buffers.  
`metaTabBigote.c`	- Funcion de lectura de templates y generacion basado en las estructuras meta leidas del fichero meta.  
`metaTabGenera.c`	- Funcion de generacion de distintos tipos de ficheros, amenudo utilizando templates y mustach.  

### plantillas
`makefileMain.template`       - Generación del makefile principal de la tabla generada.  
`makefileTest.template`       - Generación del makefile TEST del  de la tabla generada.  
`metaTab2Json_c.template`	    - Generación del programa de generación de Json de la tabla.  
`metaTabLee_c.template`       - Generación del programa de lectura de la tabla.  
`metaTabParseJson_c.template` - Generación del programa de lectura del Json de la tabla -> estructura.  
`metaTabTest_c.template`	    - Generacion del programa de Test de la tabla generada.  
`metaTabCargaMeta_c.template` - Generación del programa.  
`metaTabGetKeys_c.template`   - Gemeracion de la Carga (en forma de inicialización) de la estructura meta de la tabla.  
`cJSON_c.template`            - Template para generar cJSON.c en el API de la tabla generada.  
`cJSON_h.template`	          - Template para generar cJSON.h en el API de la tabla generada.  
### utilidad
`template2Include.c`	- Programa para generar includes de ficheros.  
Los ficheros que genera la utilidad zconfig1, se almacenan en un buffer en un include del programa, y cuando se ejecuta la utilidad se l

### programas externos utilizados
https://github.com/DaveGamble/cJSON
`cJSON.c`  
`cJSON.h`  

https://gitlab.com/jobol/mustach  
`mustach.c`	 
`mustach.h`	 

### git
.gitignore	

### documentacion
Doxyfile	
README.md	 
changelog.txt	 

### makefile
makeLib	
makefile	


### test
motFaltasMeta.tab  - Fichero meta para test  

### Archivos intermedios no incluidos
 *Includes de programas para posteriormete generarlos*
 Generados por template2Include
 
 metaTabGetKeys_c.h  
 metaTab_h.h  
 metaTab_c.h  
 metaTabCargaMeta_c.h  
 metaTabTabla_h.h  
 metaTabLee_c.h  
 metaTabTest_c.h 
 makefileMain.h 
 makefileTest.h 
 metaTab2Json_c.h 
 metaTabParseJson_c.h 
 cJSON_c.h 
 cJSON_h.h

Estos archivos se Generan en la compilacion
doxygen_sqlite3.db	Añado zconfig1 utilidad	25 days ago
leeme.txt	Añado zconfig1 utilidad	25 days ago
metaTab_h.h	anado el tipo Y	11 days ago
metaTab_h.template	anado el tipo Y	11 days ago

..		
test	anadida inicializacion en la lectura de lista	9 days ago



## Links
* carpeta **zdatConfig1Tab** 
[Documento con la descripción del formato de los ficheros ZCONF1][TAB_ZCONF1]

* carpeta **zdatConfig1TabMeta** 
[Documento con la descripción 'META' de ficheros ZCONF1][META_ZCONF1]



[TAB_ZCONF1]: ../zdatConfig1Tab/readme.md "Descripción del formato de ficheros ZCONF1"
[META_ZCONF1]: ../zdatConfig1TabMeta/readme.md "Descripción del formato de ficheros META_ZCONF1"
[ZCONF1]: README.md "Fuentes en C para la generación de programas de manejo de ficheros ZCONF1"
