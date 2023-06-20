#include "fila.h"
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxTam 1000000

struct fila {
    Arv* arvores[MaxTam];
    int qtd;
    int inicio;
};


Fila* fila_inicia(){
    Fila* fila = calloc(1, sizeof(Fila));
    fila->qtd = 0;
    fila->inicio = 0;

    return fila;
}

void fila_insere( Fila* fila, Arv* arv ){
    if( arv == NULL || fila == NULL || fila->qtd >= MaxTam ){
        printf("Fila ou Arvore invalida ou a fila esta cheia!\n");
        return;
    }

    //posicao final do vetor
    int pos = (fila->inicio + fila->qtd) % MaxTam;

    //adicionando a arvore no vetor na posicao pos
    fila->arvores[pos] = arv;
    fila->qtd++;
}

Arv* fila_retira( Fila* fila ){
    if( fila == NULL || fila->qtd == 0 ){
        printf("Fila invalida ou a fila esta vazia!\n");
        return NULL;
    }

    Arv* arv = fila->arvores[fila->inicio];
    fila->inicio = (fila->inicio+1) % MaxTam;
    fila->qtd--;

    return arv;
}

bool fila_esta_vazia( Fila* fila ){
    if( fila->qtd == 0 ){
        return true;
    }
    return false;
}

void fila_imprime( Fila* fila ){
    for (int i = 0;i < fila->qtd;i++){
        int pos = (fila->inicio + i) % MaxTam;
        arvore_imprime_folha(fila->arvores[pos]);
    }
}

void fila_libera( Fila* fila ){
    if( !fila ) {
        printf("Fila invalida!\n");
        return;
    }
    free( fila );
}
