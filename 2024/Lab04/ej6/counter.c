#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
/*
    Needs implementation.
*/

    counter p = NULL;
    p = malloc(sizeof(counter));
    p->count = 0;
    return p;
    assert(counter_is_init);
}

void counter_inc(counter c) {
    c->count ++;
}

bool counter_is_init(counter c) {
    bool res = false;
    if (c->count == 0){
        res = true;
    }
    return res;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count --;
}

counter counter_copy(counter c) {
    counter copy = NULL;
    copy = malloc(sizeof(counter));
    copy->count = c->count;
    return copy;
}

void counter_destroy(counter c) {
    free(c);
}
