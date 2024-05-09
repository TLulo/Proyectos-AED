/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    bool before_player;
    before_player = x->rank <= y->rank;
    return before_player;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j){
    player_t aux = NULL;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    unsigned int i = izq+1;
    unsigned j = der;
    while (i <= j)
    {
        if (goes_before(a[i],a[ppiv]))
        {
            i++;
        }
        else if (goes_before(a[ppiv],a[j]))
        {
            j--;
        }
        else if (goes_before(a[ppiv],a[i]) && goes_before(a[j],a[ppiv]))
        {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a,j,ppiv);
    return j;
}

void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = partition(a, izq, der);
    if (der > ppiv)
    {
        quick_sort_rec(a, ppiv + 1, der);
    }
    if (ppiv > izq)
    {
        quick_sort_rec(a, izq, ppiv - 1);
    }
}

void quick_sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

void sort(player_t a[], unsigned int length) {
    quick_sort(a , length);
}
// static void insert(player_t atp[], unsigned int i) {
// unsigned int j;
// j = i;
// while(j > 0 && goes_before(atp[j], atp[j-1])){
//     swap(atp, j-1, j);
//     j--;
// }
// }


// void sort(player_t a[], unsigned int length) {
//      for (unsigned int i = 1u; i < length; ++i) {
//         /* needs implementation */
//         insert(a, i);
//         assert(array_is_sorted(a, i));
//     }
    
// }