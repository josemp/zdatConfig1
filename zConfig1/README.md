# zConfig1
Utilidad para generar c-libreria estática para leer ficheros de formato [ZCONF1][TAB_ZCONF1]
Inicialmente concebido para linux y programado en C
## Contenido

### programa zconfig1
`zconfig1.c`    - Programa Main de la utilidad.  
`metaTab.h`	    - Estructuras meta de las tablas meta.  
`metaTab.c`	    - Funciones de lectura del contenido de una tabla meta.  
`metaTabAdd.h`,`metaTabAdd.c`  - Funciones Add para la generacion de las estructuras meta.  
`metaTabLee.c`	- Funcion de lectura de una tabla meta hacia las estructuras meta.  
`limpia.c`	    - Funciones auxiliares de buffers.  
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

### programas externos utilizados
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




..		
test	anadida inicializacion en la lectura de lista	9 days ago
cJSON_c.h	branche template&json to master	20 days ago
cJSON_c.template	branche template&json to master	20 days ago
cJSON_h.h	branche template&json to master	20 days ago
cJSON_h.template	branche template&json to master	20 days ago
doxygen_sqlite3.db	Añado zconfig1 utilidad	25 days ago
leeme.txt	Añado zconfig1 utilidad	25 days ago
makefileMain.h	branche template&json to master	20 days ago
makefileTest.h	branche template&json to master	20 days ago
metaTab2Json_c.h	branche template&json to master	20 days ago
metaTabLee_c.h	anadida inicializacion en la lectura de lista	9 days ago
metaTabLimpia.c	branche template&json to master	20 days ago
metaTabParseJson_c.h	branche template&json to master	20 days ago
metaTabTest_c.h	branche template&json to master	20 days ago
metaTab_h.h	anado el tipo Y	11 days ago
metaTab_h.template	anado el tipo Y	11 days ago
template2Include	branche template&json to master	20 days ago



## Contenido
* carpeta **zdatConfig1Tab** 
[Documento con la descripción del formato de los ficheros ZCONF1][TAB_ZCONF1]

* carpeta **zdatConfig1TabMeta** 
[Documento con la descripción 'META' de ficheros ZCONF1][META_ZCONF1]

* carpeta **zConf1** 
[Fuentes de la utilidad zConf1 generadora de programas ZCONF1][ZCONF1]



[TAB_ZCONF1]: ../zdatConfig1Tab/readme.md "Descripción del formato de ficheros ZCONF1"
[META_ZCONF1]: ../zdatConfig1TabMeta/readme.md "Descripción del formato de ficheros META_ZCONF1"
[ZCONF1]: README.md "Fuentes en C para la generación de programas de manejo de ficheros ZCONF1"
