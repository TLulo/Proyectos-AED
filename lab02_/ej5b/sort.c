#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */
    unsigned int pivot;
    unsigned int i;
    unsigned int j;
    pivot = izq;
    i = izq + 1;
    j = der;
    while(i <= j){
        if (goes_before(a[i], a[pivot])){
            i++;
        }
        else if (goes_before(a[pivot], a[j])){
            j--;
        }
        else if (goes_before(a[pivot], a[i]) && goes_before(a[j], a[pivot])){
            swap(a, i, j);
        }
    }
    swap(a, pivot, j);
    pivot = j;
    return pivot;
}


static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
   unsigned int pivot;
   pivot = partition(a, izq, der);
    if (izq < pivot){    
        quick_sort_rec(a, izq, pivot-1);}
    if (der > pivot){
        quick_sort_rec(a, pivot + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


