#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"

void ImprimirArray(Item* array, int N ){
    for( int i = 0; i < N; i++){
        printf("%d\n", array[i]);
    }
}

void LiberarArray(Item* array){
    free(array);
}

extern void sort(Item *a, int lo, int hi);

int main( int argc, char* argv[] ){

    int N = atoi(argv[1]);

    Item * array = calloc(N, sizeof(Item));

    int i = 0;
    int num = 0;

    while ( i < N ){
        scanf("%d\n", &num);
        array[i] = num;
        i++;
    }

    clock_t start = clock();

    sort(array,0,N);

    clock_t end = clock();

    // ImprimirArray(array, N);

    double time_spent_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de ordenação: %.6f segundos\n", time_spent_recursive);
    puts("");

    LiberarArray(array);

    return 0;
}

