#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char* argv[] ){

    int N = 10;

    Arv* a = arvore_cria_vazia();

    srand(time(NULL));

    for( int i = 0; i < N; i++ ){
        int chave = rand();
        a = arvore_insere_chave_na_raiz(a, i);
    }

    printf("A altura da arvore é: %d\n", arvore_altura(a));

    arvore_imprime(a);

    arvore_libera(a);

    return 0;
}

// Média altura inserção na folha: 49.2
// Média altura inserção na raiz: 48.6
