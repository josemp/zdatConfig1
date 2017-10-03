/**
  @file leeMetaTab.c
  @brief Lectura de ficheros meta de configuracion z
  @author Jose Miguel Parra
  @date 8/2017
<b>Estructura del fichero meta:</b>  \n   
Lineas de campos separados por ":".\n
\verbatim  
label:tipo:...
...
label:tipo:...  
\endverbatim
 
- tipo Char
\verbatim
label:C:len
\endverbatim
- tipo List
\verbatim
label:C:lenLista:len
\endverbatim
- tipo Objeto
\verbatim
label:O:nombre1:len1:nombre2:len2 ...
\endverbatim
  
  


*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "metaTab.h"

/**
@brief lectura de un fichero meta zconfig1
@param file : un null string con el path al fichero
@return : retorna un NULL si el fichero no existe o es incorrecto.\n Si todo es correcto, devuelve un array de estructuras metaTab_t



*/
metaTab_t *leeMetaTab(char *file)
{
 metaTab_t metaTab;
 itemObjeto_t *objeto;
 metaTab.numItems=0;
 char *pun;
 char *label;
 char *label1;
 int len,len1;
 char *slen,*slen1;
 char *tipo;
char *resto;
 char buf[10000l];
 char hayItems=0;
  

 FILE *in= fopen(file,"r");
 if (!in) return(NULL);
 while(1)
  {
   if (!fgets(buf,10000l,in)) break;
   if (strlen(buf)<2) continue;
   buf[strlen(buf)-1]=0;
   Conf1LimpiaBuf(buf);
// comentario
   if (buf[0]=='#') continue;
// busca ":" para el label.
   pun=memchr(buf,':',strlen(buf));
   if (!pun) continue;
  
   *pun=0;
   label=buf;
   pun++;
   tipo=pun;
   if (strlen(tipo)==0) break;
   pun=memchr(tipo,':',strlen(tipo));
   if (!pun) continue;
   *pun=0;
   pun++;
   resto=pun;
   if (strlen(resto)== 0) break;
   if (tipo[0]!='C' && tipo[0]!='L' && tipo[0]!='O') break;
   switch (tipo[0])
      {
     case 'C':
        len=atoi(resto);
        if (len==0) break;
        addItemCharMetaTab(&metaTab,label,atoi(resto));
     break;
     case 'L': 
      slen=resto;
      pun=memchr(resto,':',strlen(resto));
      if (!pun) break;
      *pun=0;
      pun++;
      if (strlen(slen)==0) break;
      if (atoi(slen)==0) break;
      slen1=pun;
       
      if (strlen(slen)==0) break;
      len1=atoi(slen1);
      
      if (len1==0) 
         break;
     addItemListMetaTab(&metaTab,label,atoi(slen),atoi(slen1));
     break;
     case 'O':
       hayItems=0;
       while(1)
        {
          label1=resto;
          pun=memchr(resto,':',strlen(resto));
          if (!pun) break;
          *pun=0;
          if (strlen(label1)==0) break;
          pun++;
          slen=pun;
          pun=memchr(slen,':',strlen(slen));
          if (!pun) 
           {// es el final
             if(strlen(slen)!=0 && atoi(slen)>0)
              {
                if (hayItems==0)
                   {
                     objeto=malloc(sizeof(itemObjeto_t));
                     objeto->numItems=0;
                     strcpy(objeto->nombre,label);
                     hayItems=1;
                   }
                addItemObjeto(objeto,label1,atoi(slen));
              }
             break;
           } 
          *pun=0;
          if (strlen(slen)==0) break;
          if (atoi(slen)==0) break;
          pun++;
          resto=pun;
          if (hayItems==0)
             {
               objeto=malloc(sizeof(itemObjeto_t));
               objeto->numItems=0;
                     strcpy(objeto->nombre,label);
               hayItems=1;
             }
                addItemObjeto(objeto,label1,atoi(slen));
        }
             if(hayItems==1)
              {
               addItemObjMetaTab(&metaTab,&objeto);
              }
     break;
  
  }

}
if (metaTab.numItems>0)
{
   metaTab_t *rtab;
   rtab=malloc(sizeof(metaTab_t));
   memset(rtab,0,sizeof(metaTab_t));
   *rtab=metaTab;
   return(rtab);
   
//   generaTabStructuras(&metaTab,"general");
}
else return(NULL);
}
