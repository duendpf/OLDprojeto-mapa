/*
 * Lucas Eduardo Visolli Sala N.USP 6783652
 * Fisica Computacional - IFSC - USP
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

//MAIN
int main (void){
    Tree* T;
    tipo_elem a,b,c;
    char aux[10];
    nodo* v;
    
    //Define a arvore
    T = define();
    
    //Cria elementos os a,b,c
    a.num = 4;    strcpy(aux, "ElementoA");
    a.info = (char *) malloc(strlen(aux));
    strcpy(a.info, aux);
    
    b.num = 134;    strcpy(aux,"ElementoB");
    b.info = (char *) malloc(strlen(aux));
    strcpy(b.info, aux);

    c.num = 765;    strcpy(aux,"ElementoC");
    c.info = (char *) malloc(strlen(aux));
    strcpy(c.info, aux);

    //Adiciona os elementos na arvore.
    v = insert(T, a);
    printf ("Elemento a: %d.\n", (v->elem).num);
    
    v = insert(T, b);
    printf ("Elemento b: %d.\n",(v->elem).num);
    
    v = insert(T, c);
    printf ("Elemento c: %d.\n",(v->elem).num);
           
    v = search(T, T->root, a);
    if(v == NULL)
	    printf("POOOOOOOOORRA! (by Derci)\n");
    else
	    tremove(T, v);

    v = search(T, T->root, b);
    if(v == NULL)
	    printf("POOOOOOOOORRA! (by Derci)\n");
    else
	    tremove(T, v);

    v = search(T, T->root, c);
    if(v == NULL)
	    printf("POOOOOOOOORRA! (by Derci)\n");
    else
	    tremove(T, v);



    getchar();
    return 0;
}

