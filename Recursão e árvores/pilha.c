#include "pilha.h"
#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>

#define MaxTam 1000

struct pilha {
    Arv* arvores[MaxTam];
    int Topo;
    int Max;
};


Pilha* pilha_inicia(){
    Pilha* p = calloc(1, sizeof(Pilha));
    p->Topo = 0;
    p->Max = MaxTam;

    return p;
}

//inclui no topo
void pilha_push( Pilha* p, Arv* a ){
    
    if( !p || !a || p->Topo >= MaxTam ){
        printf("Pilha ou arvore invalido(s) ou a Pilha esta cheia!\n");
    }

    else{
        p->arvores[p->Topo] = a;
        p->Topo++;
    }
}

//retira no topo
Arv* pilha_pop( Pilha* p ){
    if( !p || p->Topo == 0 ){
        printf("Pilha vazia!\n");
        return NULL;
    }

    Arv* arv = p->arvores[p->Topo-1];
    p->Topo--;

    return arv;
}

void pilha_imprime( Pilha* p ){
    if( !p ) {
        printf("Pilha invalida!\n");
        return;
    }

    for( int i = (p->Topo-1); i >= 0; i-- ){
        arvore_imprime_folha(p->arvores[i]);
    }
}

Arv* pilha_peek(Pilha* pilha) {
    if (pilha == NULL || pilha->arvores[pilha->Topo-1] == NULL) {
        // Pilha vazia
        return NULL; // Valor de sentinela para indicar pilha vazia
    }

    return pilha->arvores[pilha->Topo-1]; // Retorna o valor do elemento no topo da pilha
}


bool pilha_esta_vazia( Pilha* p ){
    return p->Topo == 0;
}

void pilha_destroi( Pilha* p ){
    if( !p ) {
        printf("Pilha invalida!\n");
        return;
    }

    free(p);
}