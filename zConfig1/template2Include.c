/* Este programa tiene un fichero de texto como entrada */
/* Como salida tiene un fichero include .h , donde el ficher de texto de entrada se guarda como un char buf[]="  " */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *puesEso(char *buf,char *buf2)
{
int i;
strcpy(buf2,"");
for (i=0;i<strlen(buf);i++)
 {
//  printf("buf[%d]=[%c][\\%c]\n",i,buf[i],buf[i]);
  if (buf[i]=='\\')
    sprintf(buf2+strlen(buf2),"%c%c",buf[i],buf[i]);
  else  
  if (buf[i]=='\"')
    sprintf(buf2+strlen(buf2),"\\%c",buf[i]);
  else
    sprintf(buf2+strlen(buf2),"%c",buf[i]);
 }
return(buf2);


}


/* ++++++++++++++++++++++ */
/* using 
/* extension es un puntero de filename
/* ++++++++++++++++++++++ */
int GetFileSinExtension(char* filename,char *fileSin,char *extension)
{
  int i;
  strcpy(fileSin,filename);
  strcpy(extension,"");
  int size = strlen(fileSin);
  char* p = fileSin + size;
  for(i=size; i >= 0; i--)
  {
    if( *(--p) == '.' )
    {
      *p=0;
      strcpy(extension,p+1);
      return(i);
      break;
    }
  }
  return(-1);
  
}

main(int argc, char **argv)
{
FILE *in;
FILE *ou;
char fileSin[100];
char extension[100];
char buf[1000+1];
char buf2[1000+1];
char fileou[100];
if (argc <=1)
{printf("%s fileIn \n",argv[0]);exit(-1);}

GetFileSinExtension(argv[1],fileSin,extension);
if (strcmp(extension,"template")!=0)
  {printf("%s el fichero ha de tener extension .template\n",argv[1]);exit(-1);}
in=fopen(argv[1],"r");
if (!in){printf("fichero [%s] no se pudo abrir para lectura\n",argv[1]);exit(-1);}
sprintf(fileou,"%s.h",fileSin);
ou=fopen(fileou,"w");
if (!ou){printf("fichero [%s] no se pudo abrir para excritura\n",fileou);exit(-1);}



fprintf(ou,"char *%s =",fileSin);
while(fgets(buf,1000,in))
{
 if (strlen(buf) > 0)
    buf[strlen(buf)-1]=0;
 fprintf(ou,"\n\"%s\\n\"",puesEso(buf,buf2));
}
fprintf(ou,";\n");

printf("Generado [%s] a partir de [%s] \n",fileou,argv[1]);
return(0);

}

