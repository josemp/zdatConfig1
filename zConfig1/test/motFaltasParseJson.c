
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motFaltas.h"
#include "cJSON.h"

// Los campos simples de la raiz

parseString(cJSON *item,motFaltas_t *motFaltas)
{ 
 if (strcmp(item->string,"name")==0)
       sprintf(motFaltas->name,"%.*s",50,item->valuestring);
}

// Los campos de objeto

parseItemObjeto(char *padre, cJSON *item,motFaltas_t *motFaltas)
{ 
 if (   strcmp(padre,"ped")==0
    &&  strcmp(item->string,"ip")==0)
       sprintf(motFaltas->ped.ip,"%.*s",20,item->valuestring);

 if (   strcmp(padre,"ped")==0
    &&  strcmp(item->string,"puerto")==0)
       sprintf(motFaltas->ped.puerto,"%.*s",6,item->valuestring);

 if (   strcmp(padre,"ped")==0
    &&  strcmp(item->string,"timeutConexion")==0)
       sprintf(motFaltas->ped.timeutConexion,"%.*s",6,item->valuestring);

 if (   strcmp(padre,"ped")==0
    &&  strcmp(item->string,"timeoutRespuesta")==0)
       sprintf(motFaltas->ped.timeoutRespuesta,"%.*s",6,item->valuestring);

 if (   strcmp(padre,"cons")==0
    &&  strcmp(item->string,"ip")==0)
       sprintf(motFaltas->cons.ip,"%.*s",20,item->valuestring);

 if (   strcmp(padre,"cons")==0
    &&  strcmp(item->string,"puerto")==0)
       sprintf(motFaltas->cons.puerto,"%.*s",6,item->valuestring);
}

// Los campos de array

parseItemArray(char *padre, cJSON *item,int contador,motFaltas_t *motFaltas)
{ 
 if (    strcmp(padre,"hostias")==0
     && contador <3)
       sprintf(motFaltas->hostias[contador],"%.*s",10,item->valuestring);

 if (    strcmp(padre,"reinicio")==0
     && contador <3)
       sprintf(motFaltas->reinicio[contador],"%.*s",7,item->valuestring);
}

void parse_object(cJSON *item, char *padre, int tipoPadre,motFaltas_t *motFaltas)
{
int contArray=0;
    cJSON *myItem = item;
    while (1)
    {
        // handle subitem
        if (myItem->child)
        {
            parse_object(myItem->child,myItem->string,myItem->type,motFaltas);
        }
       else
        {
          if (padre==NULL || strcmp(padre,"root")==0)
              parseString(myItem,motFaltas);
          else if (tipoPadre== cJSON_Object)
              parseItemObjeto(padre,myItem,motFaltas);
          else if (tipoPadre==cJSON_Array)
            {
              parseItemArray(padre,myItem,contArray,motFaltas);
              contArray++;
            }
        }

        myItem = myItem->next;
        if (!myItem) break;
    }
}


motFaltasParseJson(char *jsonString,motFaltas_t *motFaltas)
{

//int ret=leeFile("prueba.json",&jsonString);
//if (ret<0) {printf("no pude leer prueba.json\n");return;}
cJSON * root = cJSON_Parse(jsonString);
if (root==NULL) {return(-1);}
parse_object(root, "root", cJSON_Object, motFaltas);

free(root);

return(0);

}

