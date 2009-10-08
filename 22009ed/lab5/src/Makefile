# $Id$
#
# Makefile para gerenciamento do projeto de labrotario 5
# pilhas

# a base da lista
BASEIPATH = lista_base
SRC_BASE = lista_base/*.cpp
H_BASE = lista_base/*.h
OBJ_BASE = elem.o

# lista simples
LSIPATH = lista_simples
SRC_LS = ${SRC_BASE} lista_simples/*.cpp
H_LS = ${H_BASE} lista_simples/*.h
OBJ_LS = lista_simples.o # e se fossem mil arquivos .cpp a virarem .o?!

# pilha
PPATH = pilha
SRC_PILHA = pilha/*.cpp
H_PILHA = pilha/*.h
OBJ_PILHA = pilha.o

# o progama em si
PILHA = mpilha

ALL: 
	@echo "do nothing"

${OBJ_BASE}: ${SRC_BASE} ${H_BASE}
	g++ -I${BASEIPATH} -I${LSIPATH} -I${PPATH} -g -c ${SRC_BASE}

${OBJ_LS}: ${SRC_LS} ${H_LS}
	g++ -I${BASEIPATH} -I${LSIPATH} -I${PPATH} -g -c ${SRC_LS}

${OBJ_PILHA}: ${SRC_PILHA} ${H_PILHA}
	g++  -I${BASEIPATH} -I${LSIPATH} -I${PPATH} -g -c ${SRC_PILHA}

${PILHA}: ${OBJ_BASE} ${OBJ_LS} ${OBJ_PILHA} main_${PILHA}.cpp
	g++  -I${BASEIPATH} -I${LSIPATH} -I${PPATH} -g -o ${PILHA} ${OBJ_BASE} ${OBJ_LS} ${OBJ_PILHA} main_${PILHA}.cpp

clean:
	rm *.o ${PILHA}
