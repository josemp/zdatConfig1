/**
  @file limpia.c
  @brief Diversas utilidades de limpieza de buffers, especial para el programa zconf1

  Basado en antiguas funciones que limpia un buffer, se han protegido con otro nombre comenzando en Conf1

  @author Jose Miguel Parra
  @date 30/Agosto/2017

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/**
  @brief Quita espacios iniciales y finales a un **null string**
  @param buf Un null string al que queremos quitarle espacios iniciales y finales.
  @returns no tiene mucho interes el retrono.

  Example:
  \verbatim
     char buf[22];
     strcpy(buf," quita espacios ");
     Conf1LimpiaBuf(buf);
     printf("buf despues [%s]\n",buf);
   \endverbatim

  Resultado:
  \Verbatin
   buf despues [quita espacios]
  \endverbatim

  */
Conf1LimpiaBuf(char *buf)
{
  return(Conf1LimpiaBuffer(buf,strlen(buf)));
}

/**
  @brief Quita espacios iniciales y finales a los primeros len caracteres de buf

  @param buf Un string al que queremos quitarle espacios iniciales y finales.
  @param len la longitud del string
  @returns no tiene mucho interes el retrono.

  Example:
  \verbatim
     char buf[22];
     strcpy(buf," quita espacios ");
     Conf1LimpiaBuffer(buf,7);
     printf("buf despues [%s]\n",buf);
   \endverbatim

  Resultado:
  \Verbatin
   buf despues [quitaespacios ]
  \endverbatim

  */
Conf1LimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=Conf1quita_espacios_iniciales(buf,len);
 ret=Conf1quita_espacios_finales(buf,lenp);
 return(ret);
}

/**
  @brief Quita espacios iniciales los primeros len caracteres de buf

  @param buf Un string al que queremos quitarle espacios iniciales.
  @param len la longitud del string
  @returns no tiene mucho interes el retrono.

  Example:
  \verbatim
     char buf[22];
     strcpy(buf," quita espacios ");
     Conf1quita_espacios_iniciales(buf,7);
     printf("buf despues [%s]\n",buf);
   \endverbatim

  Resultado:
  \Verbatin
   buf despues [quita espacios ]
  \endverbatim

  */
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

/**
  @brief Quita espacios finales los primeros len caracteres de buf

  @param buf Un string al que queremos quitarle espacios iniciales.
  @param len la longitud del string
  @returns no tiene mucho interes el retrono.

  Example:
  \verbatim
     char buf[22];
     strcpy(buf," quita espacios ");
     Conf1quita_espacios_finales(buf,7);
     printf("buf despues [%s]\n",buf);
   \endverbatim

  Resultado:
  \Verbatin
   buf despues [ quitaespacios ]
  \endverbatim

  */
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

