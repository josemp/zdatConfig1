char *metaTabTest_c =
"{{={% %}=}}\n"
"#include <stdio.h>\n"
"#include <string.h>\n"
"#include <stdlib.h>\n"
"#include <memory.h>\n"
"\n"
"#include \"{%&titulo%}.h\"\n"
"\n"
"main()\n"
"{\n"
"int ret;\n"
"\n"
"//Crea e inicia estructura\n"
"\n"
"{%&titulo%}_t {%&titulo%};\n"
"memset(&{%&titulo%},0, sizeof({%&titulo%}_t));\n"
"\n"
"//Lee tabla\n"
"ret={%&titulo%}Lee(\"{%&titulo%}.tab\",&{%&titulo%});\n"
"if (ret<0) printf(\"No se pudo leer correctamente {%&titulo%}.tab\\n\");\n"
"else printf(\"Leido correctamente \\n\");\n"
"\n"
"// Muestra la lectura\n"
"printf(\"------------- tab print -------------------\\n\");\n"
"{%&titulo%}Pinta(&{%&titulo%});\n"
"printf(\"------------- tab print -------------------\\n\");\n"
"\n"
"// Lee lista\n"
"{%&titulo%}_t *{%&titulo%}Lista;\n"
"ret={%&titulo%}LeeLista(\"{%&titulo%}List.tab\",&{%&titulo%}Lista);\n"
"printf(\"Leidos <%d> registros\\n\",ret);\n"
"\n"
"// Genera Json\n"
"printf(\"Generando Json\\n\");\n"
"ret={%&titulo%}2Json(\"{%&titulo%}.json\",&{%&titulo%});\n"
"\n"
"// Parse Json\n"
"printf(\"Parse JSON generado\\n\");\n"
"char *jsonString;\n"
"ret=leeFileTest(\"{%&titulo%}.json\",&jsonString);\n"
"if (ret<0)\n"
"    printf(\"Error de lectura del fichero <%s>\\n\",\"{%&titulo%}.json\");\n"
"\n"
"{%&titulo%}_t {%&titulo%}1;\n"
"{%&titulo%}ParseJson(jsonString, &{%&titulo%}1);\n"
"// Muestra la lectura json\n"
"printf(\"------------- tab print json parsed-------------------\\n\");\n"
"{%&titulo%}Pinta(&{%&titulo%}1);\n"
"printf(\"------------- tab print json parsed-------------------\\n\");\n"
"}\n"
"\n"
"\n"
"\n"
"int leeFileTest(char *file, char **template)\n"
"{\n"
"char *buf;\n"
"FILE *in=fopen(file,\"r\");\n"
"if (!in) return(-1);\n"
"buf=malloc(1);\n"
"strcpy(buf,\"\");\n"
"while(1)\n"
" {\n"
"\n"
"   buf=realloc(buf,strlen(buf)+1001);\n"
"   if (!fgets(buf+strlen(buf),1000,in)) break;\n"
" }\n"
"fclose(in);\n"
"\n"
"*template=buf;\n"
"return(strlen(buf));\n"
"\n"
"}\n"
"\n";