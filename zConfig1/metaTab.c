#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metaTab.h"




addItemObjeto(itemObjeto_t *objeto,char *label,char *descri,int len)
{
  int numItem=objeto->numItems;
  if (objeto->numItems==0)
  objeto->item=malloc(sizeof(itemChar_t));
  else
  objeto->item=realloc(objeto->item,(numItem+1)*sizeof(itemChar_t));
  itemChar_t item;
  strcpy(item.nombre,label);
  item.lenChar=len;
  strcpy(item.descri,descri);
  objeto->item[numItem]=item;
  objeto->numItems++;
}
addItemCharMetaTab(metaTab_t *tabla,char *label,char *descri,int len)
{
 metaTabItem_t tabItem;
 tabItem.tipo='C';
 itemChar_t *itemChar;
 itemChar=malloc(sizeof(itemChar_t));
 strcpy(itemChar->nombre,label);
 strcpy(itemChar->descri,descri);
 itemChar->lenChar=len;
 tabItem.data=itemChar;
 if (tabla->numItems==0)
 tabla->item=malloc(sizeof(metaTabItem_t));
 else
 tabla->item=realloc(tabla->item,(tabla->numItems+1)*sizeof(metaTabItem_t));

 tabla->item[tabla->numItems]=tabItem;
 tabla->numItems++;

}
addItemListMetaTab(metaTab_t *tabla,char *label,char *descri,int lenLista,int lenChar)
{
 metaTabItem_t tabItem;
 tabItem.tipo='L';
 itemLista_t *itemLista;
 itemLista=malloc(sizeof(itemLista_t));
 strcpy(itemLista->nombre,label);
 strcpy(itemLista->descri,descri);
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

char *getNombreItemTabla(metaTab_t *tabla,int itemTabla)
{


 if (itemTabla >= tabla->numItems)
   return(NULL);
 if (itemTabla< 0)
   return(NULL);
 if (tabla->item[itemTabla].tipo=='C')
   {
    itemChar_t *itemChar = (itemChar_t *) tabla->item[itemTabla].data;
    return(itemChar->nombre);
   }
 if (tabla->item[itemTabla].tipo=='L')
   {
    itemLista_t *itemLista = (itemLista_t *) tabla->item[itemTabla].data;
    return(itemLista->nombre);
   }
 if (tabla->item[itemTabla].tipo=='O')
   {
    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    return(itemObjeto->nombre);
   }
return(NULL);
}
int  getLenCharItemTabla(metaTab_t *tabla,int itemTabla)
{

 if (itemTabla >= tabla->numItems)
   return(-1);
 if (itemTabla< 0)
   return(-1);
 if (tabla->item[itemTabla].tipo=='C')
   {
    itemChar_t *itemChar = (itemChar_t *) tabla->item[itemTabla].data;
    return(itemChar->lenChar);
   }
 if (tabla->item[itemTabla].tipo=='L')
   {
    itemLista_t *itemLista = (itemLista_t *) tabla->item[itemTabla].data;
    return(itemLista->lenChar);
   }
 if (tabla->item[itemTabla].tipo=='O')
   {
    return(-1);
   }
return(-1);
}
int  getLenListaItemTabla(metaTab_t *tabla,int itemTabla)
{

 if (itemTabla >= tabla->numItems)
   return(-1);
   
 if (itemTabla< 0)
   return(-1);
 if (tabla->item[itemTabla].tipo=='C')
   {
    return(-1);
   }
 if (tabla->item[itemTabla].tipo=='L')
   {
    itemLista_t *itemLista = (itemLista_t *) tabla->item[itemTabla].data;
    return(itemLista->lenLista);

   }
 if (tabla->item[itemTabla].tipo=='O')
   {
    return(-1);
   }
return(-1);
}


char *getNombreItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto)
{

 if (itemTabla >= tabla->numItems)
   return(NULL);

 if (itemTabla< 0)
   return(NULL);

 if (tabla->item[itemTabla].tipo=='C')
    return(NULL);

 if (tabla->item[itemTabla].tipo=='L')
    return(NULL);

 if (tabla->item[itemTabla].tipo!='O')
    return(NULL);

// Solo quedan objetos

    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    
    if ( numItemObjeto >= itemObjeto->numItems)
      return(NULL);
    if (numItemObjeto <0) return(NULL);
    
    return(itemObjeto->item[numItemObjeto].nombre);
}


int getLenCharItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto)
{

 if (itemTabla >= tabla->numItems)
   return(-1);

 if (itemTabla< 0)
   return(-1);

 if (tabla->item[itemTabla].tipo=='C')
    return(-1);

 if (tabla->item[itemTabla].tipo=='L')
    return(-1);

 if (tabla->item[itemTabla].tipo!='O')
    return(-1);

// Solo quedan objetos

    
    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    
    if ( numItemObjeto >= itemObjeto->numItems)
      return(-1);
    if (numItemObjeto <0) return(-1);
    
    return(itemObjeto->item[numItemObjeto].lenChar);
}

int  getNumItemsObjeto(metaTab_t *tabla,int itemTabla)
{
 if (itemTabla >= tabla->numItems)
   return(-1);

 if (itemTabla< 0)
   return(-1);

 if (tabla->item[itemTabla].tipo=='C')
    return(-1);

 if (tabla->item[itemTabla].tipo=='L')
    return(-1);

 if (tabla->item[itemTabla].tipo!='O')
    return(-1);

// Solo quedan objetos

    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    
    
    return(itemObjeto->numItems);
}
