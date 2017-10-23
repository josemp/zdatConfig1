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
  //printf("Objeto <%s> descri <%s>\n",label,descri);
  objeto->item[numItem]=item;
  objeto->numItems++;
}
int addItemCallBackMetaTab(metaTab_t *tabla,char *label,char *descri,char *tipo)
{
metaTabItem_t tabItem;
tabItem.tipo='Y';
itemCallBack_t *itemCallBack;
itemCallBack=malloc(sizeof(itemCallBack_t));
strcpy(itemCallBack->nombre,label);
strcpy(itemCallBack->descri,descri);
strcpy(itemCallBack->tipo,tipo);
tabItem.data=itemCallBack;

 if (tabla->numItems==0)
 tabla->item=malloc(sizeof(metaTabItem_t));
 else
 tabla->item=realloc(tabla->item,(tabla->numItems+1)*sizeof(metaTabItem_t));

 tabla->item[tabla->numItems]=tabItem;
 tabla->numItems++;





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

