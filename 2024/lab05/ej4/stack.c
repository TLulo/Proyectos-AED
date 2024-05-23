#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define CAPACITY_MIN 2u

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool inv_rep(stack s){
    return s->capacity >= s->size;
}

stack stack_empty(){
    stack s = NULL;
    s = malloc(sizeof(struct _s_stack));
    s->capacity=CAPACITY_MIN;
    s->elems = calloc(s->capacity,sizeof(stack_elem *));
    s->size = 0u;
    return s;
}

stack stack_push(stack s, stack_elem e){
    assert((inv_rep(s)));
    if (s->capacity == s->size)
    {
        s->capacity = s->capacity * 2;
        
        s->elems=realloc(s->elems,s->capacity * sizeof(stack_elem *));
        
        s->size ++;
        s->elems[s->size] = e;
    }else{
        s->size ++;
        s->elems[s->size] = e;
    }
        
    assert((inv_rep(s)));
    return s;    
}

stack stack_pop(stack s){
    assert((inv_rep(s)));
    assert(!stack_is_empty(s));

    s->size --;

    assert((inv_rep(s)));
    
    return s;
}
unsigned int stack_size(stack s){
    assert((inv_rep(s)));
    
    return s->size;
}

stack_elem stack_top(stack s){
    assert((inv_rep(s)));
    assert(!stack_is_empty(s));

    return s->elems[s->size];
}

bool stack_is_empty(stack s){
    assert((inv_rep(s)));
    
    return s->size == 0;
}

stack_elem *stack_to_array(stack s){
    assert((inv_rep(s)));

    stack_elem *arr = NULL;
    arr = calloc(s->size,sizeof(stack_elem));
    for (unsigned int i = 0; i < s->size; i++)
    {
        arr[i] = s->elems[s->size-i];
    }
    
    assert((inv_rep(s)));
    return arr;
}

stack stack_destroy(stack s){
    assert((inv_rep(s)));
    
    free(s->elems);
    free(s);
    
    return NULL;
}

void destroy_array(stack_elem *array){
    free(array);
}