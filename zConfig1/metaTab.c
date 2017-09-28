#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metaTab.h"




addItemObjeto(itemObjeto_t *objeto,char *label,int len)
{
  int numItem=objeto->numItems;
  if (objeto->numItems==0)
  objeto->item=malloc(sizeof(itemChar_t));
  else
  objeto->item=realloc(objeto->item,(numItem+1)*sizeof(itemChar_t));
  itemChar_t item;
  strcpy(item.nombre,label);
  item.lenChar=len;
  objeto->item[numItem]=item;
  objeto->numItems++;
}
addItemCharMetaTab(metaTab_t *tabla,char *label,int len)
{
 metaTabItem_t tabItem;
 tabItem.tipo='C';
 itemChar_t *itemChar;
 itemChar=malloc(sizeof(itemChar_t));
 strcpy(itemChar->nombre,label);
 itemChar->lenChar=len;
 tabItem.data=itemChar;
 if (tabla->numItems==0)
 tabla->item=malloc(sizeof(metaTabItem_t));
 else
 tabla->item=realloc(tabla->item,(tabla->numItems+1)*sizeof(metaTabItem_t));

 tabla->item[tabla->numItems]=tabItem;
 tabla->numItems++;

}
addItemListMetaTab(metaTab_t *tabla,char *label,int lenLista,int lenChar)
{
 metaTabItem_t tabItem;
 tabItem.tipo='L';
 itemLista_t *itemLista;
 itemLista=malloc(sizeof(itemLista_t));
 strcpy(itemLista->nombre,label);
 itemLista->lenChar=lenChar;
 itemLista->lenLista=lenLista;
 tabItem.data=itemLista;
 if (tabla->numItems==0)
 tabla->item=malloc(sizeof(metaTabItem_t));
 else
 tabla->item=realloc(tabla->item,(tabla->numItems+1)*sizeof(metaTabItem_t));

 tabla->item[tabla->numItems]=tabItem;
 tabla->numItems++;

}
addItemObjMetaTab(metaTab_t *tabla,itemObjeto_t **objeto)
{
 metaTabItem_t tabItem;
 tabItem.tipo='O';
 tabItem.data=*objeto;
 if (tabla->numItems==0)
 tabla->item=malloc(sizeof(metaTabItem_t));
 else
 tabla->item=realloc(tabla->item,(tabla->numItems+1)*sizeof(metaTabItem_t));
 tabla->item[tabla->numItems]=tabItem;
 tabla->numItems++;

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
generaInclude(char *nombreTabla,metaTab_t *tabla)
{
int i,j;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
char namefile[200];
sprintf(namefile,"%s.h",nombreTabla);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);

// Primero los objetos
for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou,"\ntypedef struct {\n");
      for (j=0;j<itemObjeto->numItems;j++)
       {
         fprintf(ou,"char %s[%d];\n",itemObjeto->item[j].nombre,itemObjeto->item[j].lenChar+1);
       }
      fprintf(ou,"}%s_t;\n\n",itemObjeto->nombre);
    }


}
// Ahora la clase general

if (tabla->numItems>0)
  fprintf(ou,"\ntypedef struct {\n");
for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      fprintf(ou,"char %s[%d];\n",itemChar->nombre,itemChar->lenChar+1);
    
  }
 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      fprintf(ou,"char %s[%d][%d];\n",itemLista->nombre,itemLista->lenLista+1,itemLista->lenChar+1);
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou," %s_t %s;\n",itemObjeto->nombre,itemObjeto->nombre);

    }


}


if (tabla->numItems>0)
  fprintf(ou,"}%s_t; \n\n",nombreTabla);
fclose(ou);
return(0);
}
buscaEtiqueta(metaTab_t *tabla,char *label)
{
int i;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
for (i=0;i<tabla->numItems;i++)
{
 
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      if (strcmp(label,itemChar->nombre)==0)
        return(i);
    
  }
 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      if (strcmp(label,itemLista->nombre)==0)
        return(i);
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      if (strcmp(label,itemObjeto->nombre)==0)
        return(i);
   }
}
return(-1);
}





generaProgramaLectura(char *nombre, metaTab_t *tabla)
{

itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
int i,j;
char namefile[200];
sprintf(namefile,"%sLee.c",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);
// Cabeceras

fprintf(ou,"#include <stdio.h>\n#include <string.h>\n#include <stdlib.h>\n#include <memory.h>\n\n");

fprintf(ou,"#include \"%s.h\"\n\n",nombre);

fprintf(ou,"%sLee(char *nombreFichero,%s_t *%s)\n",nombre,nombre,nombre);
fprintf(ou,"{\n");
fprintf(ou,"char buf[2001];\n");
fprintf(ou,"char *pun,*pun1,*resto,*campo,*label;\n");
fprintf(ou,"FILE *in = fopen(nombreFichero,\"r\");\n");
fprintf(ou,"if (!in) return(-1);\n");
fprintf(ou,"while(1)\n");
fprintf(ou,"{\n");
fprintf(ou,"if (!fgets(buf,2000,in))\n");
fprintf(ou,"         break;\n");
fprintf(ou," if (strlen(buf)<3) continue;\n");
fprintf(ou," buf[strlen(buf)-1]=0;\n");
fprintf(ou," %sLimpiaBuf(buf);\n",nombre);
fprintf(ou,"if (buf[0]=='#')\n");
fprintf(ou,"         continue;\n");
fprintf(ou,"resto=buf;\n");
fprintf(ou,"\n \n//...\n\n");

// PROCESO
      fprintf(ou,"\n// Etiquetas\n");
      fprintf(ou,"label=buf;\n");
      fprintf(ou,"pun=memchr(buf,':',strlen(buf));\n");
      fprintf(ou,"if(!pun) continue;\n");
      fprintf(ou,"*pun=0;\n");
      fprintf(ou,"pun++;\n");
      fprintf(ou,"resto=pun;\n");
      fprintf(ou,"%sLimpiaBuf(label); \n",nombre);

for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      fprintf(ou,"\n// Char %s\n",itemChar->nombre);
      fprintf(ou,"if (strcmp(label,\"%s\")==0)\n",itemChar->nombre);
      fprintf(ou," {\n");
      fprintf(ou,"    %sTrunca(resto,%d);\n",nombre,itemChar->lenChar);
      fprintf(ou,"    %sLimpiaBuf(resto);\n",nombre);
      fprintf(ou,"   strcpy(%s->%s,resto);\n",nombre,itemChar->nombre);
      fprintf(ou,"   continue;\n");
      fprintf(ou," }\n\n");
    
  }
 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      fprintf(ou,"\n// LISTA %s\n",itemLista->nombre);
      fprintf(ou,"if (strcmp(label,\"%s\")==0)\n",itemLista->nombre);
      fprintf(ou," {\n");
      fprintf(ou,"  int i=0;\n");
      fprintf(ou,"while(1)\n");
      fprintf(ou," {\n");
      fprintf(ou,"   campo=resto;\n");
      fprintf(ou,"   pun=memchr(resto,':',strlen(resto));\n");
      fprintf(ou,"   if(pun) *pun=0;\n");
      fprintf(ou,"    %sTrunca(campo,%d);\n",nombre,itemLista->lenChar);
      fprintf(ou,"    %sLimpiaBuf(campo);\n",nombre);
      fprintf(ou,"   strcpy(%s->%s[i],campo);\n",nombre,itemLista->nombre);
      fprintf(ou,"   i++;\n");
      fprintf(ou,"   if (!pun) break; \n");
      fprintf(ou,"   pun++;\n");
      fprintf(ou,"   if (strlen(pun)==0) break;\n");
      fprintf(ou,"   resto=pun;\n");
      fprintf(ou," }// end while\n");
      fprintf(ou,"continue;\n");
      fprintf(ou," }\n\n");
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou,"\n// Objeto %s\n",itemObjeto->nombre);
      fprintf(ou,"if (strcmp(label,\"%s\")==0)\n",itemObjeto->nombre);
      fprintf(ou," {\n");
      for (j=0;j<itemObjeto->numItems;j++) 
       {
      fprintf(ou,"\n// Item %s\n\n",itemObjeto->item[j].nombre);
      fprintf(ou,"   campo=resto;\n");
      fprintf(ou,"   pun=memchr(resto,':',strlen(resto));\n");
      fprintf(ou,"   if(pun) *pun=0;\n");
      fprintf(ou,"    %sTrunca(campo,%d);\n",nombre,itemObjeto->item[j].lenChar);
      fprintf(ou,"    %sLimpiaBuf(campo);\n",nombre);
      fprintf(ou,"   strcpy(%s->%s.%s,campo);\n",nombre,itemObjeto->nombre,itemObjeto->item[j].nombre);
      fprintf(ou,"   if (!pun) continue; \n");
      fprintf(ou,"   pun++;\n");
      fprintf(ou,"   if (strlen(pun)==0) continue;\n");
      fprintf(ou,"   resto=pun;\n");
       }
      fprintf(ou,"continue;\n");
      fprintf(ou," }\n\n");

   }
}



// PIE

fprintf(ou,"continue;\n");
fprintf(ou,"}\n");
fprintf(ou,"fclose(in);\n");
fprintf(ou,"return(0);\n");
fprintf(ou,"}\n\n");

// FIN DEL PROGRAMA


// PROGRAMA DE LECTURA DE LISTA


fprintf(ou,"\n// PROGRAMA DE LECTURA DE LISTA\n\n");
fprintf(ou,"// usage:\n");
fprintf(ou,"//        %s_t *%sLista;\n",nombre,nombre);
fprintf(ou,"//       numItems = %sLeeLista(nombreFichero,&%sLista);\n",nombre,nombre);
fprintf(ou,"%sLeeLista(char *nombreFichero,%s_t **%sLista)\n",nombre,nombre,nombre);
fprintf(ou,"{\n");
fprintf(ou,"%s_t %sx;\n",nombre,nombre);
fprintf(ou,"%s_t *%s=&%sx;\n",nombre,nombre,nombre);
fprintf(ou,"char buf[20001];\n");
fprintf(ou,"int numItems=0;\n");
fprintf(ou,"char *pun,*pun1,*resto,*campo,*label;\n");
fprintf(ou,"FILE *in = fopen(nombreFichero,\"r\");\n");
fprintf(ou,"if (!in) return(-1);\n");
fprintf(ou,"while(1)\n");
fprintf(ou,"{\n");
fprintf(ou,"if (!fgets(buf,20000,in))\n");
fprintf(ou,"         break;\n");
fprintf(ou," if (strlen(buf)<3) continue;\n");
fprintf(ou," buf[strlen(buf)-1]=0;\n");
fprintf(ou," %sLimpiaBuf(buf);\n",nombre);
fprintf(ou,"if (buf[0]=='#')\n");
fprintf(ou,"         continue;\n");
fprintf(ou,"resto=buf;\n");
fprintf(ou,"\n \n//...\n\n");

// PROCESO
      fprintf(ou,"\n// Inicia\n");
      fprintf(ou,"resto=buf;\n");

for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;

      fprintf(ou,"\n// Char %s\n",itemChar->nombre);
      fprintf(ou,"if (!resto) continue;  \n");
      fprintf(ou,"campo=resto;\n");
      fprintf(ou,"pun=memchr(resto,':',strlen(resto));\n");
      fprintf(ou,"if (pun)\n");
      fprintf(ou," {\n");
      fprintf(ou,"  *pun=0;\n");
      fprintf(ou,"  pun++;\n");
      fprintf(ou,"  resto=pun;\n");
      fprintf(ou," }\n");
      fprintf(ou,"else\n");
      fprintf(ou," resto=NULL;\n");
      fprintf(ou,"    %sTrunca(campo,%d);\n",nombre,itemChar->lenChar);
      fprintf(ou,"    %sLimpiaBuf(campo);\n",nombre);
      fprintf(ou,"   strcpy(%s->%s,campo);\n",nombre,itemChar->nombre);
    
  }
 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      fprintf(ou,"\n// LISTA %s\n",itemLista->nombre);
      for (j=0;j<itemLista->lenLista;j++)
      {

        fprintf(ou,"if (!resto) continue;  \n");
        fprintf(ou,"campo=resto;\n");
        fprintf(ou,"pun=memchr(resto,':',strlen(resto));\n");
        fprintf(ou,"if (pun)\n");
        fprintf(ou," {\n");
        fprintf(ou,"  *pun=0;\n");
        fprintf(ou,"  pun++;\n");
        fprintf(ou,"  resto=pun;\n");
        fprintf(ou," }\n");
        fprintf(ou,"else\n");
        fprintf(ou," resto=NULL;\n");
      fprintf(ou,"    %sTrunca(campo,%d);\n",nombre,itemLista->lenChar);
      fprintf(ou,"    %sLimpiaBuf(campo);\n",nombre);
        fprintf(ou,"   strcpy(%s->%s[%d],campo);\n",nombre,itemLista->nombre,j);
      }
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou,"\n// Objeto %s\n",itemObjeto->nombre);
      for (j=0;j<itemObjeto->numItems;j++) 
       {

        fprintf(ou,"if (!resto) continue;  \n");
        fprintf(ou,"campo=resto;\n");
        fprintf(ou,"pun=memchr(resto,':',strlen(resto));\n");
        fprintf(ou,"if (pun)\n");
        fprintf(ou," {\n");
        fprintf(ou,"  *pun=0;\n");
        fprintf(ou,"  pun++;\n");
        fprintf(ou,"  resto=pun;\n");
        fprintf(ou," }\n");
        fprintf(ou,"else\n");
        fprintf(ou," resto=NULL;\n");
      fprintf(ou,"    %sTrunca(campo,%d);\n",nombre,itemObjeto->item[j].lenChar);
      fprintf(ou,"    %sLimpiaBuf(campo);\n",nombre);
        fprintf(ou,"   strcpy(%s->%s.%s,campo);\n",
                nombre,itemObjeto->nombre,itemObjeto->item[j].nombre);
       }

   }
}



// PIE
fprintf(ou,"if (numItems==0) *%sLista=malloc(sizeof(%s_t));\n",nombre,nombre);
fprintf(ou,"else *%sLista=realloc(*%sLista,(numItems+1)*sizeof(%s_t));\n",nombre,nombre,nombre);
fprintf(ou,"(*%sLista)[numItems]=*%s;\n",nombre,nombre);
fprintf(ou,"numItems++;\n");
fprintf(ou,"continue;\n");
fprintf(ou,"}\n");
fprintf(ou,"fclose(in);\n");
fprintf(ou,"return(numItems);\n");
fprintf(ou,"}\n\n");

// FIN DE PROGRAMA DE LECTURA DE LISTA


// PINTA CONTENIDO DE LA TABLA

fprintf(ou,"%sPinta(%s_t *%s)\n",nombre,nombre,nombre);
fprintf(ou,"{\n");


// BUCLE

for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      fprintf(ou,"printf(\"%s = %s\\n\",%s->%s);\n",itemChar->nombre,"%s",nombre,itemChar->nombre);
  }
 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      for(j=0;j<itemLista->lenLista;j++)
 {
      fprintf(ou,"printf(\"%s[%d] = %s\\n\",%s->%s[%d]);\n",itemLista->nombre,j,"%s",nombre,itemLista->nombre,j);
 }
       
  }
 if (tabla->item[i].tipo=='O')
  {
      itemObjeto=tabla->item[i].data;
      for (j=0;j<itemObjeto->numItems;j++) 
       {
       fprintf(ou,"printf(\"%s.%s = %s\\n\",%s->%s.%s);\n",itemObjeto->nombre,
                             itemObjeto->item[j].nombre,
                             "%s",nombre,itemObjeto->nombre,
                             itemObjeto->item[j].nombre
                             );
       }
  }
}

 
fprintf(ou,"}\n\n");


// Limpieza de buffer personalizado


fprintf(ou,"// Limpieza de buffer personalizado\n");
fprintf(ou,"%sLimpiaBuf(char *buf)\n",nombre);
fprintf(ou,"{\n");
fprintf(ou,"return(%sLimpiaBuffer(buf,strlen(buf)));\n",nombre);
fprintf(ou,"}\n");
fprintf(ou,"%sLimpiaBuffer(char *buf,int len)\n",nombre);
fprintf(ou,"{\n");
fprintf(ou," int lenp,ret;\n");
fprintf(ou," lenp=%squita_espacios_iniciales(buf,len);\n",nombre);
fprintf(ou," ret=%squita_espacios_finales(buf,lenp);\n",nombre);
fprintf(ou," return(ret);\n");
fprintf(ou,"}\n");

fprintf(ou,"%squita_espacios_iniciales(char *buf ,int len)\n",nombre);
fprintf(ou,"{\n");
fprintf(ou," int i;\n");
fprintf(ou," int lenp=0;\n");
fprintf(ou," for (i=0;i<len;i++)\n");
fprintf(ou,"   {\n");
fprintf(ou,"     if (lenp==0 && buf[i]==' ')\n");
fprintf(ou,"               continue;\n");
fprintf(ou,"     buf[lenp]=buf[i];\n");
fprintf(ou,"     lenp++;\n");
fprintf(ou,"   }\n");
fprintf(ou," for (i=lenp;i<len;i++)\n");
fprintf(ou,"      buf[i]=0;\n");
fprintf(ou," return(lenp);\n");
fprintf(ou,"}\n");
fprintf(ou,"%squita_espacios_finales(char *buf ,int len)\n",nombre);
fprintf(ou,"{\n");
fprintf(ou," int i;\n");
fprintf(ou," int lenp=len;\n");
fprintf(ou," for (i=(len)-1;i>=0;i--)\n");
fprintf(ou,"   {\n");
fprintf(ou,"     if (buf[i]==' ')\n");
fprintf(ou,"     { buf[i]=0;lenp--;}\n");
fprintf(ou,"     else\n");
fprintf(ou,"       break;\n");
fprintf(ou,"   }\n");
fprintf(ou," return(lenp);\n");
fprintf(ou,"}\n");
fprintf(ou,"\n// buf es terminado en 0 si su longitud es mayor que len, lo trunca\n\n");
fprintf(ou,"%sTrunca(char *buf,int len)\n",nombre);
fprintf(ou,"{\n");
fprintf(ou,"if (strlen(buf)>len)\n");
fprintf(ou,"   buf[len]=0;\n");
fprintf(ou,"}\n");




fclose(ou);
return(0);
}

generaProgramaTest(char *nombre)
{
char namefile[200];
sprintf(namefile,"%sTest.c",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);


fprintf(ou,"#include <stdio.h>\n");
fprintf(ou,"#include <string.h>\n");
fprintf(ou,"#include <stdlib.h>\n");
fprintf(ou,"#include <memory.h>\n\n");

fprintf(ou,"#include \"%s.h\"\n\n",nombre);
fprintf(ou,"main()\n");
fprintf(ou,"{\n");
fprintf(ou,"int ret;\n\n");

fprintf(ou,"//Crea e inicia estructura\n\n");

fprintf(ou,"%s_t %s;\n",nombre,nombre);
fprintf(ou,"memset(&%s,0, sizeof(%s_t));\n\n",nombre,nombre);

fprintf(ou,"//Lee tabla\n");
fprintf(ou,"ret=%sLee(\"%s.tab\",&%s);\n",nombre,nombre,nombre);
fprintf(ou,"if (ret<0) printf(\"No se pudo leer correctamente %s.tab\\n\");\n",nombre);
fprintf(ou,"else printf(\"Leido correctamente \\n\");\n\n");

fprintf(ou,"// Muestra la lectura\n\n");

fprintf(ou,"%sPinta(&%s);\n\n",nombre,nombre);
fprintf(ou,"%s_t *%sLista;\n",nombre,nombre);
fprintf(ou,"ret=%sLeeLista(\"%sList.tab\",&%sLista);\n",nombre,nombre,nombre);
fprintf(ou,"printf(\"Leidos <%s> registros\\n\",ret);\n","%d");

fprintf(ou,"}\n");


fclose(ou);
return(0);

}


generaMakeFileMain(char *nombre)
{
char namefile[200];
sprintf(namefile,"makefileMain",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);

fprintf(ou,"TITULO  := makefile generado por zConf1makefile generado por zConfig1\n");
fprintf(ou,"NAME    := %s\n",nombre);
fprintf(ou,"VERSION := 1.0.0\n\n");

fprintf(ou,"FUENTES  :=  %sLee.c\n",nombre);
fprintf(ou,"INCLUDES := %s.h\n\n",nombre);


fprintf(ou,"OUTHER_DIR_INCLUDE  :=\n\n");

fprintf(ou,"INCLUDES_FOR_OUTPUT :=\n\n");

fprintf(ou,"OUTPUT_DIR := bin\º\n");

fprintf(ou,"LIBRARY_NAME := lib$(NAME).a\n");
fprintf(ou,"CFLAGS = $(OUTHER_DIR_INCLUDE)\n");
fprintf(ou,"OBJETOS      := $(FUENTES:%s)\n\n","%.c=%.o");


fprintf(ou,"# -------- RULES ------------------\n\n");


fprintf(ou,"all: compila test\n\n");

fprintf(ou,"compila: $(LIBRARY_NAME)\n\n");

fprintf(ou,"$(OBJETOS):$(FUENTES) $(INCLUDES)\n\n");

fprintf(ou,"$(LIBRARY_NAME): $(OBJETOS)\n");
fprintf(ou,"\t- rm -f $(LIBRARY_NAME)\n");
fprintf(ou,"\tar -rf $@ $^\n\n");


fprintf(ou,"clean:\n");
fprintf(ou,"\t- rm -f $(OBJETOS) $(LIBRARY_NAME)\n\n");

fprintf(ou,"test:\n");
fprintf(ou,"\tmake -f makefileTest\n");

fclose(ou);
return(0);

}

generaMakeFileTest(char *nombre)
{
char namefile[200];
sprintf(namefile,"makefileTest",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);

fprintf(ou,"TITULO  := makefile generado por zConf1makefile generado por zConfig1\n");
fprintf(ou,"NAME    := %sTest\n",nombre);
fprintf(ou,"VERSION := 1.0.0\n\n");

fprintf(ou,"FUENTES  :=  %sTest.c\n",nombre);
fprintf(ou,"INCLUDES := %s.h\n\n",nombre);


fprintf(ou,"OUTHER_DIR_INCLUDE  :=\n\n");

fprintf(ou,"OUTHER_DIR_LIBS :=\n\n");
fprintf(ou,"OUTHER_LIBS :=\n\n");

fprintf(ou,"PROYECT_LIBS :=lib%s.a\n\n",nombre);
fprintf(ou,"PROGRAM_NAME:= $(NAME)\n");
fprintf(ou,"CFLAGS = $(OUTHER_DIR_INCLUDE)\n");
fprintf(ou,"LDFLAGS =  $(OUTHER_DIR_LIB:%=-L%)\n");
fprintf(ou,"LDLIBS = \n");
fprintf(ou,"OBJETOS      := $(FUENTES:%s)\n\n","%.c=%.o");


fprintf(ou,"# -------- RULES ------------------\n\n");


fprintf(ou,"compila: $(PROGRAM_NAME)\n\n");

fprintf(ou,"$(OBJETOS):$(FUENTES) $(INCLUDES) $(OUTHER_LIBS)\n\n");

fprintf(ou,"$(PROGRAM_NAME): $(OBJETOS) $(PROYECT_LIBS)\n");


fprintf(ou,"clean:\n");
fprintf(ou,"\t- rm -f $(OBJETOS) $(PROGRAM_NAME)\n\n");


fclose(ou);
return(0);

}
