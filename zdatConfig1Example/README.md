
## Contenido

### Ficheros Generados
**motFaltas.h**  
> `motFaltas_t`  

**motFaltas2Json.c**
Genera json data de la tabla  
> `int motFaltas2JsonFile(char *nombreFichero,motFaltas_t *motFaltas)`  
> `size_t motFaltas2JsonBuf(char **buf,motFaltas_t *motFaltas)`  
> `motFaltas2Json(FILE *ou,motFaltas_t *motFaltas)`  

**motFaltasLee.c**  
Lee fichero en formato motFaltas  
> `motFaltasLee(char *nombreFichero,motFaltas_t *motFaltas)`  
> `motFaltasLeeLista(char *nombreFichero,motFaltas_t **motFaltasLista)`  

**motFaltasParseJson.c**  
Parse Json tabla motFaltas  
> `motFaltasParseJson(char *jsonString,motFaltas_t *motFaltas)`  

**motFaltasGetKeys.c**  
Parse datos "key" "value" de la tabla
> `int motFaltasGetKeys(motFaltas_t *motFaltas,char *key,char *data)`  

**motFaltasCargaMeta.c**  
La tabla meta guardada en una estructura  
> `metaTab_t metaTab_motFaltas`
> `int getMeta_motFaltas(metaTab_t *metaTab)`

**metaTab.h**  
**metaTab.c**  




cJSON.c  
cJSON.h  

motFaltasTest.c  

makefileMain  
makefileTest  

## Relacion de ficheros generados con templates

`metaTabTabla_h.template`     - Generacion de la extructura de la tabla
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
