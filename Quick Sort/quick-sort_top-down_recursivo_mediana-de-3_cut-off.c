#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define CUTOFF 10

extern void insert_sort(Item *a, int lo, int hi);

int median_of_3(Item *a, int lo, int hi) {
    int r1 = lo + rand() % (hi - lo + 1);
    int r2 = lo + rand() % (hi - lo + 1);
    int r3 = lo + rand() % (hi - lo + 1);
    Item v1 = a[r1], v2 = a[r2], v3 = a[r3];
    if (less(v1, v2)) {
        if (less(v2, v3))
            return r2;
        else if (less(v1, v3))
            return r3;
        else
            return r1;
    } else {
        if (less(v1, v3))
            return r1;
        else if (less(v2, v3))
            return r3;
        else
            return r2;
    }
}

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];
    while(1) {
        while (less(a[++i], v)) // Find item on left to swap.
            if (i == hi) break;
        while (less(v, a[--j])) // Find item on right to swap.
            if (j == lo) break;
        if (i >= j) break; // Check if pointers cross.
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Swap with partitioning item.
    return j; // Return index of item known to be in place.
}

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int median = median_of_3(a, lo, hi);
    // printf("Median = %d\n", median);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}