# Universidade Federal do Rio de Janeiro
# GTA: Grupo de Teleinformatica e Automacao

CC = g++
LD = g++

CFLAGS = -Wall -c
LFLAGS = -Wall -o

CENTRALOBJ = Unidade_aritmetica.o Conformador.o Gerenciador.o Validador.o Erro.o Memoria.o Gramatica.o Calculadora.o

EXECS = central


# Regra Implicita 

.cpp.o:
	$(CC) $(CFLAGS) $<

all: $(EXECS)

central: $(CENTRALOBJ)
	$(LD) $(LFLAGS) $@ $(CENTRALOBJ)


clean:
	rm -rf $(OBJS)


# $RCSfile$
