#ifndef FILA_H
#define FILA_H
#include "arvore.h"
#include <stdbool.h>

typedef struct fila Fila;

Fila* fila_inicia();

void fila_insere( Fila* fila, Arv* arv );

Arv* fila_retira( Fila* fila );

bool fila_esta_vazia( Fila* fila );

void fila_imprime( Fila* fila );

void fila_libera( Fila* fila );

#endif