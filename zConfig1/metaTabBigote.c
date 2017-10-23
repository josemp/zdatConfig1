/* Anado el campo numItems */
/* Anado los descri tanto de char list objetos y objetos.item */
/* Anado seccion firstObjeto */
/* Anado seccion first */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metaTab.h"
#include "mustach.h"
/* campos mustach

   &titulo : titulo de la tabla
   &numItems : numero de items del objeto
    
   #ignore: ignora esta seccion

   #tabla : seccion de recorrer toda la tabla

    &name : nombre del elemento

   #callback : datos de tipo callback dentro de un item de la tabla, solo uno (o ninguno)
     &tipoCB : tipo del retorno del callback

    #char  : datos de tipo char, dentro de un item de la tabla, solo uno (o ninguno)
     &lenChar : longitud de char

    #list  : datos de tipo list, solo uno
     &lenChar : longitud de char
     &lenList : longitud de la lista

    #object : datos de tipo object, solo uno
       &numItemsObjeto : numero de items del objeto
     #itemObjeto : seccion de items de objeto, recorre los items
       &itemObjeto.name : nombre de item objeto
       &itemObjeto.len : len de item objeto
*/

// Secciones

typedef enum
{seccionNone,seccionTabla,seccionTipo,seccionItemObjeto,seccionFirstObjeto,seccionFirst} seccionEnum_t;
char *seccionDescri[]={
"seccionNone","seccionTabla","seccionTipo","seccionItemObjeto","seccionFirstObjeto","seccionFirst"
};

printSeccionDescri(seccionEnum_t seccion)
{
 if (seccion<0 || seccion>seccionFirst) {printf("seccion <%d>no valida\n",seccion);fflush(stdout);}
else
 printf("seccion <%d><%s>\n",seccion,seccionDescri[seccion]);fflush(stdout);
}

// Estructura

typedef struct
{
char *titulo;
metaTab_t *tabla;
int itemTabla;
int itemObjeto;
seccionEnum_t seccion;// level 0 --> no hay seccion
                      // level 1 --> lectura de tabla
                      // level 2 --> seleccion de tipo
                      // level 3 --> lectura de objeto
} tablaInfo_t;




struct mustach_itf bigote;

int start(void *closure)
{
tablaInfo_t *tablaInfo= (tablaInfo_t *) closure;

tablaInfo->itemTabla=0;
tablaInfo->itemObjeto=0;
tablaInfo->seccion=seccionNone;
return(0);
}
int put(void *closure, const char *name, int escape, FILE *file)
{
tablaInfo_t *tablaInfo= (tablaInfo_t *) closure;
//printf("put <%s>\n",name);
if (strcmp(name,"titulo")==0)
    {fprintf(file,"%s",tablaInfo->titulo);return(0);}
if (strcmp(name,"numItems")==0)
    {fprintf(file,"%d",tablaInfo->tabla->numItems);return(0);}
if (strcmp(name,"tipoCB")==0)
{
   char *tipo= getTipoItemCallBack(tablaInfo->tabla,tablaInfo->itemTabla);
    fprintf(file,"%s",tipo);
    return(0);
}
if (strcmp(name,"descri")==0)
{
    char *nombre= getDescriItemTabla(tablaInfo->tabla,tablaInfo->itemTabla);
    fprintf(file,"%s",nombre);
    return(0);
}
if (strcmp(name,"name")==0)
{
   char *nombre= getNombreItemTabla(tablaInfo->tabla,tablaInfo->itemTabla);
    fprintf(file,"%s",nombre);
    return(0);
}
if (strcmp(name,"lenChar")==0)
{
   int len= getLenCharItemTabla(tablaInfo->tabla,tablaInfo->itemTabla);
    fprintf(file,"%d",len);
    return(0);
}
if (strcmp(name,"lenLista")==0)
{
   int len= getLenListaItemTabla(tablaInfo->tabla,tablaInfo->itemTabla);
    fprintf(file,"%d",len);
    return(0);
}
if (strcmp(name,"numItemsObjeto")==0)
{
 int numItems=getNumItemsObjeto(tablaInfo->tabla,tablaInfo->itemTabla);
    fprintf(file,"%d",numItems);
    return(0);
}
if (strcmp(name,"itemObjeto.name")==0)
{
   char *nombre= getNombreItemObjeto(tablaInfo->tabla,tablaInfo->itemTabla,tablaInfo->itemObjeto);
    fprintf(file,"%s",nombre);
    return(0);
}
if (strcmp(name,"itemObjeto.descri")==0)
{
   char *nombre= getDescriItemObjeto(tablaInfo->tabla,tablaInfo->itemTabla,tablaInfo->itemObjeto);
    fprintf(file,"%s",nombre);
    return(0);
}
if (strcmp(name,"itemObjeto.len")==0)
{
   int len= getLenCharItemObjeto(tablaInfo->tabla,tablaInfo->itemTabla,tablaInfo->itemObjeto);
    fprintf(file,"%d",len);
    return(0);
}
return(0);
}

/* Entra en una seccion */
// return(0) ignora la seccion
// return(1) continua con la seccion
int enter(void *closure, const char *name)
{
tablaInfo_t *tablaInfo= (tablaInfo_t *) closure;
//printf("Seccion <%s><%s>\n",name, seccionDescri[tablaInfo->seccion]);
if (strcmp(name,"ignore")==0)
  return(0);
if (strcmp(name,"firstObjeto")==0)
{
 if (tablaInfo->seccion== seccionItemObjeto && 
     tablaInfo->tabla->item[tablaInfo->itemTabla].tipo=='O' &&
    tablaInfo->itemObjeto==0)   
    { 
      tablaInfo->seccion=seccionFirstObjeto;
      return(1);
    }// continua
 return(0);// ignora esta seccion
}
if (strcmp(name,"first")==0)
{
    if (tablaInfo->seccion==seccionTabla &&
        tablaInfo->itemTabla==0)   
    { 
      tablaInfo->seccion=seccionFirst;
      return(1);
    }// continua
 return(0);// ignora esta seccion
}
if (strcmp(name,"tabla")==0)
{
 tablaInfo->seccion=seccionTabla;
 tablaInfo->itemTabla=0;
 return(1);
}

if (strcmp(name,"char")==0)
{
 if (tablaInfo->tabla->item[tablaInfo->itemTabla].tipo=='C')   
    {tablaInfo->seccion=seccionTipo;return(1);}// continua
 return(0);// ignora esta seccion
}
if (strcmp(name,"callback")==0)
{
 if (tablaInfo->tabla->item[tablaInfo->itemTabla].tipo=='Y')   
    {tablaInfo->seccion=seccionTipo;return(1);}// continua
 return(0);// ignora esta seccion
}
if (strcmp(name,"list")==0)
{
 if (tablaInfo->tabla->item[tablaInfo->itemTabla].tipo=='L')   
    {tablaInfo->seccion=seccionTipo;return(1);}// continua
 return(0);// ignora esta seccion
}
if (strcmp(name,"object")==0)
{
 if (tablaInfo->tabla->item[tablaInfo->itemTabla].tipo=='O')   
    { tablaInfo->seccion=seccionTipo;return(1);}// continua
 return(0);// ignora esta seccion
    
}

if (strcmp(name,"itemObjeto")==0)
{
    {tablaInfo->seccion=seccionItemObjeto;tablaInfo->itemObjeto=0;return(1);}// continua
}
return(0);
}
 
int next(void *closure)
{
tablaInfo_t *tablaInfo= (tablaInfo_t *) closure;
//printf("Entro en next <%s> \n",seccionDescri[tablaInfo->seccion]);
// Item de tabla
if (tablaInfo->seccion==seccionFirstObjeto)
{
  return(0);//fin
}
if (tablaInfo->seccion==seccionFirst)
{
  return(0);//fin
}
if (tablaInfo->seccion==seccionTabla)
  {
   tablaInfo->itemTabla++;
   if (tablaInfo->itemTabla >=tablaInfo->tabla->numItems)
     return(0); // fin
   else
     return(1);
  }
// Seleccion de tipo de objeto solo uno
if (tablaInfo->seccion==seccionTipo)
    return(0);

// Datos de objeto
if (tablaInfo->seccion==seccionItemObjeto)
{
 int numItemsObjeto=getNumItemsObjeto(tablaInfo->tabla,tablaInfo->itemTabla);
 if (numItemsObjeto<0) return(0);
  tablaInfo->itemObjeto++;
 if (tablaInfo->itemObjeto <numItemsObjeto )
   return(1);
 else
   return(0);

}
return(0);
}
int leave(void *closure)
{
tablaInfo_t *tablaInfo= (tablaInfo_t *) closure;
//printf("Entro en leave <%s>\n",seccionDescri[tablaInfo->seccion]);
if (tablaInfo->seccion==seccionFirstObjeto)
{
  tablaInfo->seccion=seccionItemObjeto;
  return;//fin
}
if (tablaInfo->seccion==seccionFirst)
{
  tablaInfo->seccion=seccionTabla;
  return;//fin
}
tablaInfo->seccion--;
}

int generaBigote(char *titulo,metaTab_t *meta,char *template,char **resultado, size_t *size)
{
int ret;

// Set bigote callbacks

bigote.start=start;
bigote.put=put;
bigote.enter=enter;
bigote.next=next;
bigote.leave=leave;

// Set closure 
//printf("template <<<<<<%s>>>>>>>\n",template);
tablaInfo_t tablaInfo;
tablaInfo.tabla=meta;
tablaInfo.titulo=titulo;
ret=mustach(template, &bigote, &tablaInfo, resultado, size);
if (ret!=0) printf("mustach error <%d>\n",ret);
return(ret); // solo 0 es bueno
}
