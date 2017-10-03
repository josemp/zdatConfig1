
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "motFaltas.h"

main()
{
int ret;

//Crea e inicia estructura

motFaltas_t motFaltas;
memset(&motFaltas,0, sizeof(motFaltas_t));

//Lee tabla
ret=motFaltasLee("motFaltas.tab",&motFaltas);
if (ret<0) printf("No se pudo leer correctamente motFaltas.tab\n");
else printf("Leido correctamente \n");

// Muestra la lectura
printf("------------- tab print -------------------\n");
motFaltasPinta(&motFaltas);
printf("------------- tab print -------------------\n");

// Lee lista
motFaltas_t *motFaltasLista;
ret=motFaltasLeeLista("motFaltasList.tab",&motFaltasLista);
printf("Leidos <%d> registros\n",ret);

// Genera Json
printf("Generando Json\n");
ret=motFaltas2Json("motFaltas.json",&motFaltas);

// Parse Json
printf("Parse JSON generado\n");
char *jsonString;
ret=leeFileTest("motFaltas.json",&jsonString);
if (ret<0)
    printf("Error de lectura del fichero <%s>\n","motFaltas.json");

motFaltas_t motFaltas1;
motFaltasParseJson(jsonString, &motFaltas1);
// Muestra la lectura json
printf("------------- tab print json parsed-------------------\n");
motFaltasPinta(&motFaltas1);
printf("------------- tab print json parsed-------------------\n");
}



int leeFileTest(char *file, char **template)
{
char *buf;
FILE *in=fopen(file,"r");
if (!in) return(-1);
buf=malloc(1);
strcpy(buf,"");
while(1)
 {

   buf=realloc(buf,strlen(buf)+1001);
   if (!fgets(buf+strlen(buf),1000,in)) break;
 }
fclose(in);

*template=buf;
return(strlen(buf));

}

