#include <stdlib.h>
#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi){

    for (int count=1; count < hi; count++) {
        for ( int proximo=0; proximo < hi-1; proximo++) {
            compexch(a[proximo], a[proximo+1]);
        }
    }
}
