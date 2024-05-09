

//librerias propias
#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t res;
    res.fst = x;
    res.snd = y;
    return res;
}

int pair_first(pair_t p){
    int fst;
    fst = p.fst;
    return fst;
}

int pair_second(pair_t p){
    int snd;
    snd = p.snd;
    return snd;
}

pair_t pair_swapped(pair_t p){
    int aux = p.fst;
    p.fst = p.snd;
    p.snd = aux;
    return p;
}

pair_t pair_destroy(pair_t p){
    return p;
}