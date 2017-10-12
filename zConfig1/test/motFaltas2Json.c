
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "motFaltas.h"

motFaltas2Json(char *nombreFichero,motFaltas_t *motFaltas)
{
FILE *ou;
int count=0;
int i;
ou=fopen(nombreFichero,"w");
if (!ou) return(-1);
fprintf(ou,"{\n");

if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");


fprintf(ou,"\"hostias\":[");
for (i=0;i<3;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",motFaltas->hostias[i]);
 }
fprintf(ou,"]");


count++;

if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");

fprintf(ou,"\"name\":\"%s\"",motFaltas->name);



count++;

if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");



fprintf(ou,"\"ped\":\n{\n");
i=0;

if (i>0) fprintf(ou,",\n");
fprintf(ou,"\"ip\":\"%s\"",motFaltas->ped.ip);
i++;

if (i>0) fprintf(ou,",\n");
fprintf(ou,"\"puerto\":\"%s\"",motFaltas->ped.puerto);
i++;

if (i>0) fprintf(ou,",\n");
fprintf(ou,"\"timeutConexion\":\"%s\"",motFaltas->ped.timeutConexion);
i++;

if (i>0) fprintf(ou,",\n");
fprintf(ou,"\"timeoutRespuesta\":\"%s\"",motFaltas->ped.timeoutRespuesta);
i++;

fprintf(ou,"\n}");

count++;

if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");



fprintf(ou,"\"cons\":\n{\n");
i=0;

if (i>0) fprintf(ou,",\n");
fprintf(ou,"\"ip\":\"%s\"",motFaltas->cons.ip);
i++;

if (i>0) fprintf(ou,",\n");
fprintf(ou,"\"puerto\":\"%s\"",motFaltas->cons.puerto);
i++;

fprintf(ou,"\n}");

count++;

if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");


fprintf(ou,"\"reinicio\":[");
for (i=0;i<3;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",motFaltas->reinicio[i]);
 }
fprintf(ou,"]");


count++;

if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");



count++;

fprintf(ou,"\n}");
fclose(ou);

}
