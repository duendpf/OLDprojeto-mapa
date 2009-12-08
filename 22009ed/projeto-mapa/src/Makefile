# Makefile do projeto de Mapa do grupo KINDEROVO

test: abb.c abb.h map.c map.h test.c
	gcc -g -o test abb.c map.c test.c

release: abb.c abb.h map.c map.h main.c
	gcc -o main abb.c map.c main.c

debug: abb.c abb.h map.c map.h main.c
	gcc -g -o main abb.c map.c main.c

clean:
	rm *.o main test

