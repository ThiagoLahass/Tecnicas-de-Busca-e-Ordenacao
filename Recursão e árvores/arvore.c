#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "pilha.h"
#include "fila.h"

struct arv{
    int chave;
    struct arv* esquerda;
    struct arv* direita;
};


Arv *arvore_cria_vazia(){
    return NULL;
}

Arv *arvore_insere_chave(Arv *a, int chave){
    if(a == NULL){
        a = (Arv*) calloc(1, sizeof(Arv));
        a->chave = chave;
        a->direita = NULL;
        a->esquerda = NULL;
    }
    else if( chave < a->chave ){
        a->esquerda = arvore_insere_chave(a->esquerda, chave);
    }
    else if( chave > a->chave ){
        a->direita = arvore_insere_chave(a->direita, chave);
    }

    return a;
}

Arv* arvore_libera(Arv *a){
    if( a != NULL ){
        arvore_libera(a->esquerda);
        arvore_libera(a->direita);
        free(a);
    }
    return NULL;
}

void arvore_imprime( Arv* a) {
    printf("<");
    if( a != NULL ) {
        printf("%d", a->chave);
        arvore_imprime(a->esquerda);
        arvore_imprime(a->direita);
    }
    printf("> ");
}

void arvore_imprime_folha( Arv* a ){
    printf("%d\n", a->chave);
}

/// @brief Não faz nada, simplesmente so chama a funcao para testar tempo de execução
/// @param a 
void arvore_teste( Arv* a ){ 
}

//========================= STATIC FUNCTION ================================
static int max_2_ints (int a, int b) {
    return (a > b) ? a : b;
}
//==========================================================================

int arvore_altura( Arv* a ){
    if( a == NULL ){
        return -1;
    }
    else{
        return( 1 + max_2_ints( arvore_altura(a->esquerda), arvore_altura(a->direita) ));
    }
}


//========================== CAMINHAMENTO COM RECURSAO ==========================
void arvore_rec_preorder(Arv *a, void (*visit)(Arv*)){
    if( a != NULL ){
        visit(a);
        arvore_rec_preorder(a->esquerda, visit);
        arvore_rec_preorder(a->direita, visit);
    }
}

void arvore_rec_inorder(Arv *a, void (*visit)(Arv*)){
    if( a != NULL ){
        arvore_rec_preorder(a->esquerda, visit);
        visit(a);
        arvore_rec_preorder(a->direita, visit);
    }
}

void arvore_rec_postorder(Arv *a, void (*visit)(Arv*)){
    if( a != NULL ){
        arvore_rec_preorder(a->esquerda, visit);
        arvore_rec_preorder(a->direita, visit);
        visit(a);
    }
}
//================================================================================


//========================== CAMINHAMENTO SEM RECURSAO (PILHA) ===================

// Função para percorrer a BST em pre-order (não-recursivo)
void arvore_nao_rec_preorder(Arv* arv, void (*visit)(Arv*)) {
    if (arv == NULL) {
        printf("Erro: Arv não existe!\n");
        return;
    }

    Pilha* pilha = pilha_inicia(); // Criar uma pilha vazia
    Arv* current = arv;

    while (current != NULL || !pilha_esta_vazia(pilha)) {
        while (current != NULL) {
            visit(current); // Visitar o nó atual em pre-order
            pilha_push(pilha, current); // Empilhar o nó atual
            current = current->esquerda; // Mover-se para o nó filho esquerdo
        }

        if (!pilha_esta_vazia(pilha)) {
            current = pilha_pop(pilha); // Desempilhar o nó atual
            current = current->direita; // Mover-se para o nó filho direito
        }
    }

    pilha_destroi(pilha); // Destruir a pilha após o uso
}

// Função para percorrer a BST em in-order (não-recursivo)
void arvore_nao_rec_inorder(Arv* arv, void (*visit)(Arv*)) {
    if (arv == NULL) {
        printf("Erro: Arv não existe!\n");
        return;
    }

    Pilha* pilha = pilha_inicia(); // Criar uma pilha vazia
    Arv* current = arv;

    while (current != NULL || !pilha_esta_vazia(pilha)) {
        while (current != NULL) {
            pilha_push(pilha, current); // Empilhar o nó atual
            current = current->esquerda; // Mover-se para o nó filho esquerdo
        }

        if (!pilha_esta_vazia(pilha)) {
            current = pilha_pop(pilha); // Desempilhar o nó atual
            visit(current); // Visitar o nó atual em in-order
            current = current->direita; // Mover-se para o nó filho direito
        }
    }

    pilha_destroi(pilha); // Destruir a pilha após o uso
}

// Função para percorrer a BST em post-order (não-recursivo)
void arvore_nao_rec_postorder(Arv* arv, void (*visit)(Arv*)) {
    if (arv == NULL) {
        printf("Erro: Arv não existe!\n");
        return;
    }

    Pilha* pilha = pilha_inicia(); // Criar uma pilha vazia
    Arv* current = arv;
    Arv* last_visited = NULL; // Guardar o último nó visitado

    while (current != NULL || !pilha_esta_vazia(pilha)) {
        while (current != NULL) {
            pilha_push(pilha, current); // Empilhar o nó atual
            current = current->esquerda; // Mover-se para o nó filho esquerdo
        }

        if (!pilha_esta_vazia(pilha)) {
            Arv* peek = pilha_peek(pilha); // Verificar o nó no topo da pilha

            if (peek->direita != NULL && peek->direita != last_visited) {
                // Se o nó da direita do topo da pilha existir e ainda não foi visitado
                current = peek->direita; // Mover-se para o nó da direita
            } else {
                // Caso contrário, imprimir o valor do nó do topo da pilha (nó folha ou ambos filhos visitados)
                peek = pilha_pop(pilha);
                visit(peek); // Imprimir o valor do nó
                last_visited = peek; // Atualizar o último nó visitado
            }
        }
    }
}

//================================================================================


//================================ CAMINHAMENTO POR NIVEIS ================================
void arvore_nao_rec_caminhamento_por_niveis( Arv* arv, void (*visit)(Arv*) ){
    if( arv == NULL ){
        return;
    }

    Fila* fila = fila_inicia();
    fila_insere( fila, arv );

    while (!fila_esta_vazia(fila)){
        Arv* current = fila_retira(fila);

        visit(current);

        if( current->esquerda != NULL ){
            fila_insere(fila, current->esquerda);
        }
        if( current->direita != NULL ){
            fila_insere(fila, current->direita );
        }
    }
}
//=========================================================================================