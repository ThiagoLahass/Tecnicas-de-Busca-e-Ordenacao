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
    while (i != id[i]) {
        id[i] = id[id[i]]; // Uma unica linha de codigo adicional.
        i = id[i]; // Cada passo agora requer 5 acessos.
    }
    return i;
}

void UF_union(int p, int q) {
    int i = UF_find(p); // Pendure a arvore menor sob a maior.
    int j = UF_find(q); // Profundidade de ? acessos.
    if (i == j) return;
    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    }
    else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

bool UF_connected(int p, int q) {
    return UF_find(p) == UF_find(q);
}