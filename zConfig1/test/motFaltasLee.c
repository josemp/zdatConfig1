
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "motFaltas.h"

motFaltasLee(char *nombreFichero,motFaltas_t *motFaltas)
{
char buf[2001];
char *pun,*pun1,*resto,*campo,*label;
FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,2000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 motFaltasLimpiaBuf(buf);
if (buf[0]=='#')
         continue;
resto=buf;

 
//...


// Etiquetas
label=buf;
pun=memchr(buf,':',strlen(buf));
if(!pun) continue;
*pun=0;
pun++;
resto=pun;
motFaltasLimpiaBuf(label); 



// LISTA hostias
if (strcmp(label,"hostias")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    motFaltasTrunca(campo,10);
    motFaltasLimpiaBuf(campo);
    strcpy(motFaltas->hostias[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }






// Char name
if (strcmp(label,"name")==0)
 {
    motFaltasTrunca(resto,50);
    motFaltasLimpiaBuf(resto);
   strcpy(motFaltas->name,resto);
   continue;
 }









// Objeto ped
if (strcmp(label,"ped")==0)
 {

// Item ip

   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if(pun) *pun=0;
    motFaltasTrunca(campo,20);
    motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->ped.ip,campo);
   if (!pun) continue; 
   pun++;
   if (strlen(pun)==0) continue;
   resto=pun;

// Item puerto

   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if(pun) *pun=0;
    motFaltasTrunca(campo,6);
    motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->ped.puerto,campo);
   if (!pun) continue; 
   pun++;
   if (strlen(pun)==0) continue;
   resto=pun;

// Item timeutConexion

   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if(pun) *pun=0;
    motFaltasTrunca(campo,6);
    motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->ped.timeutConexion,campo);
   if (!pun) continue; 
   pun++;
   if (strlen(pun)==0) continue;
   resto=pun;

// Item timeoutRespuesta

   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if(pun) *pun=0;
    motFaltasTrunca(campo,6);
    motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->ped.timeoutRespuesta,campo);
   if (!pun) continue; 
   pun++;
   if (strlen(pun)==0) continue;
   resto=pun;
}





// Objeto cons
if (strcmp(label,"cons")==0)
 {

// Item ip

   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if(pun) *pun=0;
    motFaltasTrunca(campo,20);
    motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->cons.ip,campo);
   if (!pun) continue; 
   pun++;
   if (strlen(pun)==0) continue;
   resto=pun;

// Item puerto

   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if(pun) *pun=0;
    motFaltasTrunca(campo,6);
    motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->cons.puerto,campo);
   if (!pun) continue; 
   pun++;
   if (strlen(pun)==0) continue;
   resto=pun;
}



// LISTA reinicio
if (strcmp(label,"reinicio")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    motFaltasTrunca(campo,7);
    motFaltasLimpiaBuf(campo);
    strcpy(motFaltas->reinicio[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }










continue;
 }


fclose(in);
return(0);
}











// PROGRAMA DE LECTURA DE LISTA

// usage:
//        motFaltas_t *motFaltasLista;
//       numItems = motFaltasLeeLista(nombreFichero,&motFaltasLista);
motFaltasLeeLista(char *nombreFichero,motFaltas_t **motFaltasLista)
{
motFaltas_t motFaltasx;
motFaltas_t *motFaltas=&motFaltasx;
int i;
char buf[20001];
int numItems=0;
char *pun,*pun1,*resto,*campo,*label;

memset(&motFaltas,0,sizeof(motFaltas_t));

FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,20000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 motFaltasLimpiaBuf(buf);
if (buf[0]=='#')
         continue;
resto=buf;

 
//...


// Inicia
resto=buf;


// LISTA hostias
for (i=0;i<3;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   motFaltasTrunca(campo,10);
   motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->hostias[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  






// Char name
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    motFaltasTrunca(campo,50);
    motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->name,campo);






// Objeto ped

if (!resto) continue;  
 campo=resto;
 pun=memchr(resto,':',strlen(resto));
 if (pun)
  { *pun=0; pun++; resto=pun; }
 else resto=NULL;
 motFaltasTrunca(campo,20);
 motFaltasLimpiaBuf(campo);
 strcpy(motFaltas->ped.ip,campo);

if (!resto) continue;  
 campo=resto;
 pun=memchr(resto,':',strlen(resto));
 if (pun)
  { *pun=0; pun++; resto=pun; }
 else resto=NULL;
 motFaltasTrunca(campo,6);
 motFaltasLimpiaBuf(campo);
 strcpy(motFaltas->ped.puerto,campo);

if (!resto) continue;  
 campo=resto;
 pun=memchr(resto,':',strlen(resto));
 if (pun)
  { *pun=0; pun++; resto=pun; }
 else resto=NULL;
 motFaltasTrunca(campo,6);
 motFaltasLimpiaBuf(campo);
 strcpy(motFaltas->ped.timeutConexion,campo);

if (!resto) continue;  
 campo=resto;
 pun=memchr(resto,':',strlen(resto));
 if (pun)
  { *pun=0; pun++; resto=pun; }
 else resto=NULL;
 motFaltasTrunca(campo,6);
 motFaltasLimpiaBuf(campo);
 strcpy(motFaltas->ped.timeoutRespuesta,campo);






// Objeto cons

if (!resto) continue;  
 campo=resto;
 pun=memchr(resto,':',strlen(resto));
 if (pun)
  { *pun=0; pun++; resto=pun; }
 else resto=NULL;
 motFaltasTrunca(campo,20);
 motFaltasLimpiaBuf(campo);
 strcpy(motFaltas->cons.ip,campo);

if (!resto) continue;  
 campo=resto;
 pun=memchr(resto,':',strlen(resto));
 if (pun)
  { *pun=0; pun++; resto=pun; }
 else resto=NULL;
 motFaltasTrunca(campo,6);
 motFaltasLimpiaBuf(campo);
 strcpy(motFaltas->cons.puerto,campo);




// LISTA reinicio
for (i=0;i<3;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   motFaltasTrunca(campo,7);
   motFaltasLimpiaBuf(campo);
   strcpy(motFaltas->reinicio[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  








if (numItems==0) *motFaltasLista=malloc(sizeof(motFaltas_t));
else *motFaltasLista=realloc(*motFaltasLista,(numItems+1)*sizeof(motFaltas_t));
(*motFaltasLista)[numItems]=*motFaltas;
memset(&motFaltas,0,sizeof(motFaltas_t));
numItems++;
continue;
}
fclose(in);
return(numItems);
}











motFaltasPinta(motFaltas_t *motFaltas)
{
int i;
for (i=0;i<3;i++)
  printf("hostias[i] = %s\n",motFaltas->hostias[i]);
printf("name = %s\n",motFaltas->name);
printf("ped.ip = %s\n",motFaltas->ped.ip);
printf("ped.puerto = %s\n",motFaltas->ped.puerto);
printf("ped.timeutConexion = %s\n",motFaltas->ped.timeutConexion);
printf("ped.timeoutRespuesta = %s\n",motFaltas->ped.timeoutRespuesta);
printf("cons.ip = %s\n",motFaltas->cons.ip);
printf("cons.puerto = %s\n",motFaltas->cons.puerto);
for (i=0;i<3;i++)
  printf("reinicio[i] = %s\n",motFaltas->reinicio[i]);
}

// Limpieza de buffer personalizado
motFaltasLimpiaBuf(char *buf)
{
return(motFaltasLimpiaBuffer(buf,strlen(buf)));
}
motFaltasLimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=motFaltasquita_espacios_iniciales(buf,len);
 ret=motFaltasquita_espacios_finales(buf,lenp);
 return(ret);
}
motFaltasquita_espacios_iniciales(char *buf ,int len)
{
 int i;
 int lenp=0;
 for (i=0;i<len;i++)
   {
     if (lenp==0 && buf[i]==' ')
               continue;
     buf[lenp]=buf[i];
     lenp++;
   }
 for (i=lenp;i<len;i++)
      buf[i]=0;
 return(lenp);
}
motFaltasquita_espacios_finales(char *buf ,int len)
{
 int i;
 int lenp=len;
 for (i=(len)-1;i>=0;i--)
   {
     if (buf[i]==' ')
     { buf[i]=0;lenp--;}
     else
       break;
   }
 return(lenp);
}

// buf es terminado en 0 si su longitud es mayor que len, lo trunca

motFaltasTrunca(char *buf,int len)
{
if (strlen(buf)>len)
   buf[len]=0;
}
