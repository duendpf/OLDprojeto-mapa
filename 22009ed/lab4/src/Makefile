# $Id$
#
# Makefile para implementacao dos programas teste das listas simples e
# duplamente encadeadas e do programa de benchmark

# a TAD
SRC_BASE = lista_base/*.cpp
H_BASE = lista_base/*.h
OBJ_BASE = elem.o

# lista simples
LS = lsimples
SRC_LS = ${SRC_BASE} lista_simples/*.cpp
H_LS = ${H_BASE} lista_simples/*.h
OBJ_LS = lista_simples.o # e se fossem mil arquivos .cpp a virarem .o?!

# lista dupla
LD = ldupla
SRC_LD = ${SRC_BASE} lista_dupla/*.cpp
H_LD = ${H_BASE} lista_dupla/*.h
OBJ_LD = lista_dupla.o 

#benchmark
BENCH = lbench

ALL: 
	@echo "do nothing"

${OBJ_BASE}: ${SRC_BASE} ${H_BASE}
	g++ -g -c ${SRC_BASE}

${OBJ_LS}: ${SRC_LS} ${H_LS}
	g++ -g -c ${SRC_LS}

${LS}: ${OBJ_BASE} ${OBJ_LS} main_${LS}.cpp
	g++ -g -o ${LS} ${OBJ_BASE} ${OBJ_LS} main_${LS}.cpp

${OBJ_LD}: ${SRC_LD} ${H_LD}
	g++ -g -c ${SRC_LD}

${LD}: ${OBJ_BASE} ${OBJ_LD} main_${LD}.cpp
	g++ -g -o ${LD} ${OBJ_BASE} ${OBJ_LD} main_${LD}.cpp

${BENCH}: ${OBJ_BASE} ${OBJ_LS} ${OBJ_LD} main_${BENCH}.cpp
	g++ -g -o ${BENCH} ${OBJ_BASE} ${OBJ_LS} ${OBJ_LD} main_${BENCH}.cpp

clean:
	rm *.o ${BENCH} ${LS} ${LD}
