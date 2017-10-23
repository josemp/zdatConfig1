
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


