#include "UF.h"

static int id[1000];
static int N;

void UF_init(int size) {
    N = size;
    for (int i = 0; i < N; i++) {
        id[i] = i; // Cada objeto comeca na sua propria componente.
    } // N acessos ao array.
}
int UF_find(int i) {
    while (i != id[i]) i = id[i]; // Buscar o pai ate a raiz.
    return i; // Profundidade de i acessos.
}
void UF_union(int p, int q) {
    int i = UF_find(p); // Modifique raiz de p para a raiz de q.
    int j = UF_find(q); // Profundidade de p+q acessos.
    id[i] = j;
}

bool UF_connected(int p, int q) {
    return UF_find(p) == UF_find(q);
}