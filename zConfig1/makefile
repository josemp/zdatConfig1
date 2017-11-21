TITULO  := "Programa zconfig1"

PROGRAMA_MAIN    := zconfig1



# Otras fuentes que compilaran a objetos

OTRAS_FUENTES  := metaTabGenera.c metaTabBigote.c metaTabLee.c metaTabLimpia.c metaTabAdd.c metaTab.c mustach.c cJSON.c

# dependencias de los objetos (de todos)

INCLUDES := metaTab.h metaTab.h mustach.h 

INCLUDES_TEMPLATE := metaTabGetKeys_c.h metaTab_h.h metaTab_c.h metaTabCargaMeta_c.h  metaTabTabla_h.h  metaTabLee_c.h  metaTabTest_c.h makefileMain.h makefileTest.h metaTab2Json_c.h metaTabParseJson_c.h cJSON_c.h cJSON_h.h

# directorios e includes externos

OUTHER_DIR_INCLUDE := 
OUTHER_DIR_LIB:= 

# librerias utilizadas

OUTHER_LIBS:= 

# ----------- Variables Intermedias --------
CFLAGS = $(OUTHER_DIR_INCLUDE:%=-I%)
LDFLAGS = $(OUTHER_DIR_LIB:%=-L%)
LDLIBS =     $(OUTHER_LIBS)
OBJETOS      := $(PROGRAMA_MAIN:%=%.o) $(OTRAS_FUENTES:%.c=%.o)

# ------------ RULES ------------------

T2I = ./template2Include
%.h: %.template
	$(T2I) $<


all: metaTab_c.template metaTab_h.template template2Include $(PROGRAMA_MAIN) 


metaTab_h.template: metaTab.h
	cp $^ $(patsubst %.h,%_h.template,$^)

metaTab_c.template: metaTab.c
	cp $^ $(patsubst %.c,%_c.template,$^)

$(OBJETOS): $(PROGRAMA_MAIN:%=%.c) $(OTRAS_FUENTES) $(INCLUDES) $(INCLUDES_TEMPLATE)
$(PROGRAMA_MAIN): $(OBJETOS) 
clean:
	- rm -f $(OBJETOS) $(PROGRAMA_MAIN) template2Include $(INCLUDES_TEMPLATE) metaTab_h.template metaTab_c.template 
limpia:
	- rm -f $(OBJETOS)   $(INCLUDES_TEMPLATE)

# ------------------- UTILIDADES ----------------------

template2Include:template2Include.c
#	$(CC) -o utilBufTemplate utilBufTemplate.c
