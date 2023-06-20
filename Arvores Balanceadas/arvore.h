#ifndef ARVORE_H
#define ARVORE_H

typedef struct arv Arv;

Arv* arvore_cria_vazia();

Arv* arvore_insere_chave_na_folha( Arv* a, int chave );

Arv *arvore_insere_chave_na_raiz(Arv *a, int chave);

Arv* arvore_libera( Arv* a );

void arvore_imprime( Arv* a);

void arvore_teste( Arv* a );

void arvore_imprime_folha( Arv* a );

int arvore_altura( Arv* a );

void arvore_rec_preorder(Arv *a, void (*visit)(Arv*));

void arvore_rec_inorder(Arv *a, void (*visit)(Arv*));

void arvore_rec_postorder(Arv *a, void (*visit)(Arv*));

void arvore_nao_rec_preorder(Arv* arv, void (*visit)(Arv*));

void arvore_nao_rec_inorder(Arv* arv, void (*visit)(Arv*));

void arvore_nao_rec_postorder(Arv* arv, void (*visit)(Arv*));

void arvore_nao_rec_caminhamento_por_niveis(Arv* arv, void (*visit)(Arv*));

Arv* rotate_right(Arv* a);

Arv* rotate_left(Arv* a);

#endif