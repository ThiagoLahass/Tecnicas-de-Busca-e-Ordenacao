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

    time_t inicial_time, final_time;

    int N = atoi(argv[1]);

    Item * array = calloc(N, sizeof(Item));

    int i = 0;
    int num = 0;

    while ( i < N ){
        scanf("%d\n", &num);
        array[i] = num;
        i++;
    }

    time(&inicial_time);

    sort(array,0,N);

    time(&final_time);

    ImprimirArray(array, N);

    LiberarArray(array);

    printf("Tempo execucao da ordenacao (segundos): %.0lf\n", difftime(final_time, inicial_time));

    return 0;
}

