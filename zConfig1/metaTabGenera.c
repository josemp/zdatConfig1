#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metaTab.h"


int templateBuf2File(char *titulo, metaTab_t *meta, char *template,char *fileOu)
{

char *resultado;
size_t size;
int ret;

  ret=generaBigote(titulo,meta,template,&resultado, &size);
  if (ret!=0) {printf("generaBiggote error\n");return(ret);}
  FILE *ou=fopen(fileOu,"w");
  if (!ou) {printf("no se pudo abrir <%s>\n",fileOu);free(resultado);return(-1);}
  fprintf(ou,"%.*s",size,resultado);
  fclose(ou);
  free(resultado);
return(0);


}

int templateFile2File(char *titulo,metaTab_t *meta,char *fileIn,char *fileOu)
{
char *template;
char *resultado;
size_t size;
int ret;
printf(" template <%s> resultado <%s>\n",fileIn,fileOu);
ret=leeFile(fileIn,&template);
if (ret<0)
  {printf("No pudo leerse el fichero <%s>\n",fileIn);return(-1);}

  ret=generaBigote(titulo,meta,template,&resultado, &size);
  if (ret!=0) {printf("generaBiggote error\n");free(template);return(ret);}
  FILE *ou=fopen(fileOu,"w");
  if (!ou) {printf("no se pudo abrir <%s>\n",fileOu);free(template);free(resultado);return(-1);}
  fprintf(ou,"%.*s",size,resultado);
  fclose(ou);
  free(template);
  free(resultado);
return(0);
}

int leeFile(char *file, char **template)
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

generaTabla(char *nombre,metaTab_t *tabla)
{
int i,j;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;

char namefile[200];
sprintf(namefile,"%s.tab",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);


for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      fprintf(ou,"%s: ...\n",itemChar->nombre);

  }

 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      fprintf(ou,"%s: ... : ...\n",itemLista->nombre);
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou,"%s",itemObjeto->nombre,itemObjeto->nombre);
      for (j=0;j<itemObjeto->numItems;j++)
       {
         fprintf(ou,":%s",itemObjeto->item[j].nombre);
       }
      fprintf(ou,"\n");

    }

}

fclose(ou);
return(0);

}
generaLista(char *nombre,metaTab_t *tabla)
{
int i,j;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
int num=0;
char namefile[200];
sprintf(namefile,"%sList.tab",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);


for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      if (num!=0) fprintf(ou,":");
      fprintf(ou,"%s",itemChar->nombre);
      num++;

  }

 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      for (j=0;j<itemLista->lenLista;j++)
      {

      if (num!=0) fprintf(ou,":");
      fprintf(ou,"%s",itemLista->nombre);
      num++;
     }
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou,"%s",itemObjeto->nombre,itemObjeto->nombre);
      for (j=0;j<itemObjeto->numItems;j++)
       {
         if (num!=0) fprintf(ou,":");
         fprintf(ou,"%s",itemObjeto->item[j].nombre);
         num++;
       }

    }

}


if (num>0) fprintf(ou,"\n");
fclose(ou);
return(num);
}

