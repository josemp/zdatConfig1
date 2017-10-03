#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

Conf1LimpiaBuf(char *buf)
{
return(Conf1LimpiaBuffer(buf,strlen(buf)));
}
Conf1LimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=Conf1quita_espacios_iniciales(buf,len);
 ret=Conf1quita_espacios_finales(buf,lenp);
 return(ret);
}

Conf1quita_espacios_iniciales(char *buf ,int len)
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
Conf1quita_espacios_finales(char *buf ,int len)
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

