#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char* argv[] ){

    int N = atoi(argv[1]);

    Arv* a = arvore_cria_vazia();

    srand(time(NULL));
    for( int i = 0; i < N; i++ ){
        int chave = rand();
        a = arvore_insere_chave(a, chave);
    }

    // arvore_imprime(a);

    // Medir o tempo de execução da versão recursiva do pre-order
    clock_t start = clock();
    arvore_rec_preorder(a, arvore_teste);
    clock_t end = clock();
    double time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (Recursivo pre order): %.6f segundos\n", time_spent_recursive);
    puts("");

    // Medir o tempo de execução da versão recursiva do in-order
    start = clock();
    arvore_rec_inorder(a, arvore_teste);
    end = clock();
    time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (Recursivo in order): %.6f segundos\n", time_spent_recursive);
    puts("");

    // Medir o tempo de execução da versão recursiva do post-order
    start = clock();
    arvore_rec_postorder(a, arvore_teste);
    end = clock();
    time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (Recursivo post order): %.6f segundos\n", time_spent_recursive);
    puts("");

    // Medir o tempo de execução da versão NAO recursiva do pre-order
    start = clock();
    arvore_nao_rec_preorder(a, arvore_teste);
    end = clock();
    time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (NAO Recursivo pre order): %.6f segundos\n", time_spent_recursive);
    puts("");

    // Medir o tempo de execução da versão NAO recursiva do in-order
    start = clock();
    arvore_nao_rec_inorder(a, arvore_teste);
    end = clock();
    time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (NAO Recursivo in order): %.6f segundos\n", time_spent_recursive);
    puts("");

    // Medir o tempo de execução da versão NAO recursiva do post-order
    start = clock();
    arvore_nao_rec_postorder(a, arvore_teste);
    end = clock();
    time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (NAO Recursivo post order): %.6f segundos\n", time_spent_recursive);
    puts("");

    // Medir o tempo de execução da versão NAO recursiva do caminhamento por niveis
    start = clock();
    arvore_nao_rec_caminhamento_por_niveis(a, arvore_teste);
    end = clock();
    time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (NAO Recursivo caminahmento por niveis): %.6f segundos\n", time_spent_recursive);
    puts("");


    arvore_libera(a);

    return 0;
}