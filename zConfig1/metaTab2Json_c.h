char *metaTab2Json_c =
"{{={% %}=}}{%#ignore%}\n"
"   #ignore: esta seccion\n"
"   #tabla : seccion de recorrer toda la tabla\n"
"   #char  : datos de tipo char, solo uno\n"
"   #list  : datos de tipo list, solo uno\n"
"   #object : datos de tipo object, solo uno\n"
"   #itemObjeto : seccion de items de objeto\n"
"   &titulo : titulo de la tabla\n"
"   &name : nombre del elemento\n"
"   &lenChar : longitud de char\n"
"   &lenLista : longitud de la lista\n"
"   &itemObjeto.name : nombre de item objeto\n"
"   &itemObjeto.len : len de item objeto{%/ignore%}\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <string.h>\n"
"#include <memory.h>\n"
"\n"
"#include \"{%&titulo%}.h\"\n"
"\n"
"\n"
"int {%&titulo%}2JsonFile(char *nombreFichero,{%&titulo%}_t *{%&titulo%})\n"
"{\n"
"FILE *ou = fopen(nombreFichero,\"w\");\n"
"if (!ou) return(-1);\n"
"{%&titulo%}2Json(ou , {%&titulo%});\n"
"fclose(ou);\n"
"return(0);\n"
"}\n"
"size_t {%&titulo%}2JsonBuf(char **buf,{%&titulo%}_t *{%&titulo%})\n"
"{\n"
"size_t size=0;\n"
"FILE *ou=open_memstream (buf, &size);\n"
"if (!ou) return(-1);\n"
"{%&titulo%}2Json(ou, {%&titulo%} );\n"
"fclose(ou);\n"
"}\n"
"\n"
"{%&titulo%}2Json(FILE *ou,{%&titulo%}_t *{%&titulo%})\n"
"{\n"
"int count=0;\n"
"int i;\n"
"fprintf(ou,\"{\\n\");\n"
"{%#tabla%}\n"
"if (count==0) fprintf(ou,\"\\n\"); else fprintf(ou,\",\\n\");\n"
"{%#char%}\n"
"fprintf(ou,\"\\\"{%&name%}\\\":\\\"%s\\\"\",{%&titulo%}->{%&name%});\n"
"{%/char%}\n"
"{%#list%}\n"
"fprintf(ou,\"\\\"{%&name%}\\\":[\");\n"
"for (i=0;i<{%&lenLista%};i++)\n"
" {\n"
"  if (i>0) fprintf(ou,\",\");\n"
"  fprintf(ou,\"\\\"%s\\\"\",{%&titulo%}->{%&name%}[i]);\n"
" }\n"
"fprintf(ou,\"]\");\n"
"{%/list%}\n"
"{%#object%}\n"
"fprintf(ou,\"\\\"{%&name%}\\\":\\n{\\n\");\n"
"i=0;\n"
"{%#itemObjeto%}\n"
"if (i>0) fprintf(ou,\",\\n\");\n"
"fprintf(ou,\"\\\"{%&itemObjeto.name%}\\\":\\\"%s\\\"\",{%&titulo%}->{%&name%}.{%&itemObjeto.name%});\n"
"i++;\n"
"{%/itemObjeto%}\n"
"fprintf(ou,\"\\n}\");\n"
"{%/object%}\n"
"count++;\n"
"{%/tabla%}\n"
"fprintf(ou,\"\\n}\");\n"
"\n"
"}\n";
