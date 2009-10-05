# $Id: Makefile,v 1.2 2009/09/16 20:51:37 raitech Exp raitech $

# Makefile para o projeto do jogo da velha de ED

PROG=veia
SRC=*.c
HEADERS=*.h

ALL: ${PROG} ${PROG}-debug

${PROG}: ${SRC} ${HEADERS}
	gcc -o ${PROG} ${SRC}

${PROG}-debug: ${SRC} ${HEADERS}
	gcc -g -o ${PROG}-debug ${SRC}

.PHONY: clean
clean:
	rm ${PROG} ${PROG}-debug

