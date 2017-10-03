#include <stdio.h>
#include <stdlib.h>
#include "metaTab.h"

main(int argc,char **argv)
{
//char buf[10000];
int ret;
if (argc<2)
  {
   printf("%s nombre \n\n Del fichero nombreMeta.tab, genenera nombre.tab nombre.c nombre.h nombreLee.c\n",argv[0]);
   return;
}
char *nombre=argv[1];



// Lectura de metadatos

char nombreMeta[200];
sprintf (nombreMeta,"%sMeta.tab",nombre);

metaTab_t *metaTab=leeMetaTab(nombreMeta);

if (metaTab==NULL) {printf("%s no existe\n",nombreMeta);return;}
if (metaTab->numItems==0) {printf("%s no tiene datos correctos\n",nombreMeta);return;}


// Genercion de la tabla en *.tab


ret=generaTabla(nombre,metaTab );

if (ret<0) {printf("imposible abrir para escritura %s.tab\n",nombre);return;}


// Generaion del include en *.h


ret=generaInclude(nombre,metaTab );

if (ret<0) {printf("imposible abrir para escritura %s.h\n",nombre);return;}

// Generaion del programa de lectura

ret=generaProgramaLectura(nombre, metaTab);
if (ret<0) {printf("imposible abrir para escritura %sLee.c\n",nombre);return;}

ret=generaProgramaTest(nombre);
if (ret<0) {printf("imposible abrir para escritura %sTest.c\n",nombre);return;}

// Generacion de lista

ret=generaLista(nombre, metaTab);
if (ret<=0) {printf("imposible generar lista %sTest.c <%d>\n",nombre,ret);return;}

// Generacion de makefile main

ret=generaMakeFileMain(nombre);
if (ret<0) {printf("imposible generar makefileMain <%d>\n",ret);return;}

// Generacion de makefile test

ret=generaMakeFileTest(nombre);
if (ret<0) {printf("imposible generar makefileTest <%d>\n",ret);return;}
}
