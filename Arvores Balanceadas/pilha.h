#ifndef PILHA_H
#define PILHA_H

#include "arvore.h"
#include <stdbool.h>

typedef struct pilha Pilha;

Pilha* pilha_inicia();

//inclui no topo
void pilha_push( Pilha* p, Arv* a );

//retira no topo
Arv* pilha_pop( Pilha* p );

void pilha_imprime( Pilha* p );

Arv* pilha_peek(Pilha* pilha);

bool pilha_esta_vazia( Pilha* p );

void pilha_destroi( Pilha* p );

#endif