#include <stdlib.h>
#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi){

    int low_position = 0;

    for( int position = lo; position < hi; position++ ){
        low_position = position;
        for( int j = position; j < hi; j++){
            if(less(a[j], a[low_position])){
                low_position = j;
            }
        }
        exch(a[position], a[low_position]);
    }
}