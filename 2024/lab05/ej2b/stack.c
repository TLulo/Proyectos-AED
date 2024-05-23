#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack
{
    struct Node *nodo;
    size_t size;
};


struct Node{
    stack_elem elem;
    struct Node *next;
};

stack stack_empty(){
    stack s = malloc(sizeof(struct _s_stack));
    s->nodo = NULL;
    s->size = 0;
    return s;
}

stack stack_push(stack s, stack_elem e){
    struct Node *top = NULL;
    top = malloc(sizeof(struct Node));
    top->elem = e;
    top->next = s->nodo;
    s->nodo = top;
    s->size ++;
    return s;
}

stack stack_pop(stack s){
    struct Node *p = NULL;
    if (!stack_is_empty(s))
    {
        p = s->nodo;
        (s->nodo) = (s->nodo)->next;
        s->size --;
        free(p);
    }
    return s;
}

unsigned int stack_size(stack s){
    unsigned int len = 0;
    len = s->size;
    return len;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    stack_elem e;
    e = (s->nodo)->elem;
    return e;
}

bool stack_is_empty(stack s){
  return s->size == 0;
}

stack_elem *stack_to_array(stack s){

    unsigned int len= stack_size(s); 
    stack_elem *array = NULL;
    array = NULL;

    if (!stack_is_empty(s))
    {
        array = calloc(len,sizeof(stack_elem));
        struct Node *p = NULL;
        p = s->nodo;

        for (unsigned int i = 0; i < len; i++){
            array[i] = p->elem;
            p = p->next;
        }
    }
    return array;
}

stack stack_destroy(stack s){
    struct Node *p = NULL;
    if (!stack_is_empty(s))
    {
        p = s->nodo;
        s->nodo = (s->nodo)->next;
        free(p);
    }
    free(s);
    return NULL;
}

void destroy_array(stack_elem *array){
    free(array);
}

