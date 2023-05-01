#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"

void sort(Item *a, int lo, int hi){
    
    for( int count = 0; count < hi/2; count++){

        //indo em um sentido
        for( int foward = count; foward < hi-1 -count; foward++){
            compexch(a[foward], a[foward+1]);
        }

        //voltando no outro sentido
        for( int back = hi-2 - count; back > count; back--){
            compexch(a[back-1], a[back]);
        }
    }
}