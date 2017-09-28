TITULO  := "Programa zconfig1"
NAME    := zconfig1
VERSION := 1.0.0

FUENTES  :=  zconfig1.c
INCLUDES := metaTab.h 
OUTHER_DIR_INCLUDE  := 

OUTHER_DIR_LIBS  := 
OUTHER_LIBS  := 
PROYECT_LIBS := libzlLeeMetaTab.a 





OUTPUT_DIR := bin

PROGRAM_NAME := $(NAME)
CFLAGS =  $(OUTHER_DIR_INCLUDE)
LDFLAGS = $(OUTHER_DIR_LIB:%=-L%)
LDLIBS =  $(PROYECT_LIBS)  $(OUTHER_LIBS) 
OBJETOS      := $(FUENTES:%.c=%.o)


# -------- RULES ------------------




all: libreria $(PROGRAM_NAME)

$(OBJETOS):$(FUENTES) $(INCLUDES) $(OUTHER_LIBS)

$(PROGRAM_NAME): $(OBJETOS) 
	$(CC) $(LDFLAGS)  $(OBJETOS) $(LDLIBS) -o $(PROGRAM_NAME)

libreria:
	make -f makeLib

clean:
	 - rm -f $(OBJETOS) $(PROGRAM_OUTPUT)
	make -f makeLib clean


