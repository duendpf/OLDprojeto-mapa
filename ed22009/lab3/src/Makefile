# $Id: Makefile,v 1.2 2009/09/27 20:01:38 raitech Exp raitech $

# Makefile para o projeto do lab3 de ED


#primeira implementacao
PROG_C1=listaec1
SRC_C1=imp_1/*.c
HEADERS_C1=imp_1/*.h

PROG_CPP1=listaecpp1
SRC_CPP1=imp_1/*.cpp
HEADERS_CPP1=imp_1/*.hpp

#segunda implementacao
PROG_C2=listaec2
SRC_C2=imp_2/*.c
HEADERS_C2=imp_2/*.h

PROG_CPP2=listaecpp2
SRC_CPP2=imp_2/*.cpp
HEADERS_CPP2=imp_2/*.hpp

#terceira implementacao
PROG_C3=listaec3
SRC_C3=imp_3/*.c
HEADERS_C3=imp_3/*.h

PROG_CPP3=listaecpp3
SRC_CPP3=imp_3/*.cpp
HEADERS_CPP3=imp_3/*.hpp


${PROG_C1}: ${SRC_C1} ${HEADERS_C1}
	gcc -o ${PROG_C1} ${SRC_C1}

${PROG_C1}-debug: ${SRC_C1} ${HEADERS_C1}
	gcc -g -o ${PROG_C1}-debug ${SRC_C1}

${PROG_CPP1}: ${SRC_CPP1} ${HEADERS_CPP1}
	g++ -o ${PROG_CPP1} ${SRC_CPP1}

${PROG_CPP1}-debug: ${SRC_CPP1} ${HEADERS_CPP1}
	g++ -g -o ${PROG_CPP1}-debug ${SRC_CPP1}

${PROG_C2}: ${SRC_C2} ${HEADERS_C2}
	gcc -o ${PROG_C2} ${SRC_C2}

${PROG_C2}-debug: ${SRC_C2} ${HEADERS_C2}
	gcc -g -o ${PROG_C2}-debug ${SRC_C2}

${PROG_CPP2}: ${SRC_CPP2} ${HEADERS_CPP2}
	g++ -o ${PROG_CPP2} ${SRC_CPP2}

${PROG_CPP2}-debug: ${SRC_CPP2} ${HEADERS_CPP2}
	g++ -g -o ${PROG_CPP2}-debug ${SRC_CPP2}

${PROG_C3}: ${SRC_C3} ${HEADERS_C3}
	gcc -o ${PROG_C3} ${SRC_C3}

${PROG_C3}-debug: ${SRC_C3} ${HEADERS_C3}
	gcc -g -o ${PROG_C3}-debug ${SRC_C3}

${PROG_CPP3}: ${SRC_CPP3} ${HEADERS_CPP3}
	g++ -o ${PROG_CPP3} ${SRC_CPP3}

${PROG_CPP3}-debug: ${SRC_CPP3} ${HEADERS_CPP3}
	g++ -g -o ${PROG_CPP3}-debug ${SRC_CPP3}



.PHONY: clean
clean:
	rm ${PROG_C1} ${PROG_C1}-debug ${PROG_CPP1} ${PROG_CPP1}-debug \
	rm ${PROG_C2} ${PROG_C2}-debug ${PROG_CPP2} ${PROG_CPP2}-debug \
	rm ${PROG_C3} ${PROG_C3}-debug ${PROG_CPP3} ${PROG_CPP3}-debug

