#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "metaTab.h"
// El titulo no está en este fichero
// Pero la descripcion si que esta en el comentario #descripcionTab:
//label:tipo:...           
// tipo Char
// label:C:len
//
// tipo List
// label:L:lenLista:len
//
// tipo Objeto
// label:O:nombre1:len1:nombre2:len2 ...
metaTab_t *leeMetaTab(char *file)
{
 metaTab_t metaTab;
 itemObjeto_t *objeto;
 metaTab.numItems=0;
 char *pun;
 char *label;
 char *label1;
 int len,len1;
 char *sdescri;
 char *sdescriI;
 char *slen,*slen1;
 char *tipo;
 char *tipoCallBack;
char *resto;
 char buf[10000l];
 char hayItems=0;
 strcpy(metaTab.descri,"");/* inicio esto porque creo que sale basurilla */
  

 FILE *in= fopen(file,"r");
 if (!in) return(NULL);
 while(1)
  {
   if (!fgets(buf,10000l,in)) break;
   if (strlen(buf)<2) continue;
   buf[strlen(buf)-1]=0;
   Conf1LimpiaBuf(buf);

// Comentario de descripcion
   if (strncmp(buf,"#descripcionTab:",16)==0)
     sprintf(metaTab.descri,"%.200s",buf+16);
// comentario
   if (buf[0]=='#') continue;
// busca ":" para el label.
   pun=memchr(buf,':',strlen(buf));
   if (!pun) continue;
  
   *pun=0;
   label=buf;
Conf1LimpiaBuf(label);
   pun++;
   tipo=pun;
   if (strlen(tipo)==0) break;
   pun=memchr(tipo,':',strlen(tipo));
   if (!pun) continue;
   *pun=0;
   pun++;
   resto=pun;
   if (strlen(resto)== 0) break;
   if (tipo[0]!='C' && tipo[0]!='L' && tipo[0]!='O' && tipo[0]!='Y') break;
   switch (tipo[0])
      {
     case 'Y':
        sdescri=resto;
        pun=memchr(resto,':',strlen(resto));
        if (!pun) break;
        *pun=0;
        pun++;
        tipoCallBack=pun;
        addItemCallBackMetaTab(&metaTab,label,sdescri,tipoCallBack);
     break;
     case 'C':
        sdescri=resto;
        pun=memchr(resto,':',strlen(resto));
        if (!pun) break;
        *pun=0;
        pun++;
        slen=pun;
        len=atoi(slen);
        if (len==0) break;
        addItemCharMetaTab(&metaTab,label,sdescri,atoi(slen));
     break;
     case 'L': 
      sdescri=resto;
      pun=memchr(resto,':',strlen(resto));
      if (!pun) break;
      *pun=0;
      pun++;

      slen=pun;
      pun=memchr(slen,':',strlen(resto));
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
     addItemListMetaTab(&metaTab,label,sdescri,atoi(slen),atoi(slen1));
     break;
     case 'O':
      sdescri=resto;
      pun=memchr(resto,':',strlen(resto));
      if (!pun) break;
      *pun=0;
      pun++;
      resto=pun;
       hayItems=0;
       while(1)
        {
         
          label1=resto;
          pun=memchr(resto,':',strlen(resto));
          if (!pun) break;
          *pun=0;
          if (strlen(label1)==0) break;
          pun++;

          sdescriI=pun;
          pun=memchr(sdescriI,':',strlen(sdescriI));
          if (!pun) break;
          *pun=0;
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
                     strcpy(objeto->descri,sdescri);
                     hayItems=1;
                   }
                addItemObjeto(objeto,label1,sdescriI,atoi(slen));
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
                     strcpy(objeto->descri,sdescri);
               hayItems=1;
             }
                addItemObjeto(objeto,label1,sdescriI,atoi(slen));
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

