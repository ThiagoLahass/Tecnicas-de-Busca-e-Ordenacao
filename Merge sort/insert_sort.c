#include <stdlib.h>
#include <stdio.h>
#include "item.h"

void insert_sort(Item *a, int lo, int hi){

    for( int position = lo; position < hi; position++ ){
        
        int aux_position = position;
        for(int back = aux_position-1; back >= 0; back--, aux_position-- ){

            if( less( a[aux_position], a[back] ) ){
                exch( a[aux_position], a[back] );
            }
            else break;
        }
    }
}