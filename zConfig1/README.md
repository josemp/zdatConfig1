# zConfig1
Utilidad para generar c-libreria estática para leer ficheros de formato [ZCONF1][TAB_ZCONF1]
Inicialmente concebido para linux y programado en C
## Contenido

### programa zconfig1
zconfig1.c    - Programa Main de la utilidad
metaTab.h	    - Estructuras meta de las tablas meta
metaTabAdd.h  - Funciones Add para la generacion de las estructuras meta
metaTabAdd.c 
metaTabLee.c	- Funcion de lectura de una tabla meta hacia las estructuras meta
metaTab.c	    - Funciones de lectura del contenido de una tabla meta
limpia.c	    - Funciones auxiliares de buffers
metaTabBigote.c	- Funcion de lectura de templates y generacion basado en las estructuras meta leidas del fichero meta
metaTabGenera.c	- Funcion de generacion de distintos tipos de ficheros, amenudo utilizando templates y mustach

### plantillas
makefileMain.template
makefileTest.template	
metaTab2Json_c.template	
metaTabLee_c.template	
metaTabParseJson_c.template	
metaTabTest_c.template	
metaTabCargaMeta_c.template
metaTabGetKeys_c.template
cJSON_c.template
cJSON_h.template	

### utilidad
template2Include.c	branche template&json to master	20 days ago

### programas externos utilizados
cJSON.c	branche template&json to master	20 days ago
cJSON.h	branche template&json to master	20 days ago
mustach.c	branche template&json to master	20 days ago
mustach.h	branche template&json to master	20 days ago

### git
.gitignore	Añado zconfig1 utilidad	25 days ago

### documentacion
Doxyfile	Añado zconfig1 utilidad	25 days ago
README.md	Update README.md	28 minutes ago
changelog.txt	anado el tipo Y	11 days ago

### makefile
makeLib	Añado zconfig1 utilidad	25 days ago
makefile	branche template&json to master	20 days ago




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
