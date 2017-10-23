#include <stdio.h>
#include <stdlib.h>
#include "metaTab.h"
#include "metaTabAdd.h"
#include "metaTabLee_c.h"   
#include "metaTabTabla_h.h"
#include "metaTabTest_c.h" 
#include "makefileMain.h" 
#include "makefileTest.h"  
#include "metaTab2Json_c.h"  
#include "metaTabParseJson_c.h"
#include "metaTabCargaMeta_c.h"
#include "metaTabGetKeys_c.h"
#include "cJSON_c.h"
#include "cJSON_h.h"
#include "metaTab_h.h"
#include "metaTab_c.h"
main(int argc,char **argv)
{
char nombreMeta[200];
char fileOut[200];
//char buf[10000];
int ret;
if (argc<2)
  {
   printf("%s nombre \n\n Del fichero nombreMeta.tab, genenera nombre.tab nombre.c nombre.h nombreLee.c\n",argv[0]);
   return;
}

char *nombre=argv[1];

// Lectura de metadatos

sprintf (nombreMeta,"%sMeta.tab",nombre);
metaTab_t *metaTab=leeMetaTab(nombreMeta);
if (metaTab==NULL) {printf("%s no existe\n",nombreMeta);return;}
if (metaTab->numItems==0) {printf("%s no tiene datos correctos\n",nombreMeta);return;}

if (argc>2)
{
 
 if (strcmp(argv[2],"-f")==0)
   {
     if (argc<5)
       {printf("zconfig1 -f file.template file.out\n");return;}
     printf ("----------> <%s><%s>\n",argv[3],argv[4]);
     ret=templateFile2File(nombre,metaTab,argv[3],argv[4]);
    if (ret!=0) printf("algo no fue buen\n");
     printf ("----------> <%s><%s>\n",argv[3],argv[4]);
     return;
   }
 if (strcmp(argv[2],"-t")==0)
   {
      ret=templateBuf2File(nombre, metaTab, metaTabCargaMeta_c,"hostias.final");
    if (ret!=0) printf("algo no fue buen\n");
     return;
   }
}

// Genercion de la tabla en *.tab
printf("Generando Tabla <%s.tab>\n",nombre);
ret=generaTabla(nombre,metaTab );
if (ret<0) {printf("imposible abrir para escritura %s.tab\n",nombre);return;}

// Genera Include (template en  metaTabTabla_h.h)

sprintf(fileOut,"%s.h",nombre);
printf("Generando Tabla <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab,metaTabTabla_h ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}

// Generaion del programa de lectura #include "metaTabLee_c.h"   

sprintf(fileOut,"%sLee.c",nombre);
printf("Generando Tabla <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab,metaTabLee_c ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}

// Generaion del programa de carga meta #include "metaTabCargaMeta_c.h"   

sprintf(fileOut,"%sCargaMeta.c",nombre);
printf("Generando Tabla <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab,metaTabCargaMeta_c ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}

// Generacion de lista

printf("Generando Tabla Lista <%sList.tab>\n",nombre);
ret=generaLista(nombre, metaTab);
if (ret<=0) {printf("imposible generar lista %sTest.c <%d>\n",nombre,ret);return;}


// Generaion del programa de test #include "metaTabTest_c.h"   

sprintf(fileOut,"%sTest.c",nombre);
printf("Generando  <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab,metaTabTest_c ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}

// Generaion del makefileMain #include "makefileMain.h"   

sprintf(fileOut,"makefileMain");
printf("Generando  <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab,makefileMain ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}

// Generaion del makefileTest #include "makefileTest.h"   

sprintf(fileOut,"makefileTest");
printf("Generando  <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab,makefileTest ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}
// Generaion del metaTab2Json #include "metaTab2Json_c"

sprintf(fileOut,"%s2Json.c",nombre);
printf("Generando  <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab,metaTab2Json_c ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}


// Generaion del  metaTabParseJson_c #include " metaTabParseJson_c.h"   

sprintf(fileOut,"%sParseJson.c",nombre);
printf("Generando  <%s>\n",fileOut);
ret=templateBuf2File(nombre, metaTab, metaTabParseJson_c ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}

// Generando cJSON.c
printf("generando cJSON.c\n");
FILE *ou;
ou=fopen("cJSON.c","w");
fprintf(ou,"%s",cJSON_c);
fclose(ou);


// Generando cJSON.h
printf("generando cJSON.h\n");

ou=fopen("cJSON.h","w");
fprintf(ou,"%s",cJSON_h);
fclose(ou);

// Generando metaTab.h 
printf("generando metaTab.h\n");
ou=fopen("metaTab.h","w");
fprintf(ou,"%s",metaTab_h);
fclose(ou);

// Generando metaTab.c
printf("generando metaTab.c\n");
ou=fopen("metaTab.c","w");
fprintf(ou,"%s",metaTab_c);
fclose(ou);

// Generando metaTabGetKeys.c
sprintf(fileOut,"%sGetKeys.c",nombre);
printf("generando %s\n",fileOut);
ret=templateBuf2File(nombre, metaTab,metaTabGetKeys_c ,fileOut);
    if (ret!=0) {printf("imposible generar <%s>\n",fileOut);return;}
}
