#include <stdlib.h>
#include <assert.h>
#include "stack.h"


struct _s_stack{
    stack_elem elem;
    struct _s_stack *next;
};

stack stack_empty(){
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack top = NULL;
    top = malloc(sizeof(struct _s_stack));
    top->elem = e;
    top->next = s;
    return top;
}

stack stack_pop(stack s){
    stack p = NULL;
    if (!stack_is_empty(s))
    {
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}

unsigned int stack_size(stack s){
    unsigned int len = 0;
    if (!stack_is_empty(s))
    {
        stack p = s;
        while (p->next != NULL)
        {
            len ++;
            p = p->next;
        }
        len ++;
    }
    return len;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    stack_elem e;
    e = s->elem;
    return e;
}

bool stack_is_empty(stack s){
  return s == NULL;
}

stack_elem *stack_to_array(stack s){

    unsigned int len= stack_size(s); 
    stack_elem *array = NULL;
    array = NULL;

    if (!stack_is_empty(s))
    {
        array = calloc(len,sizeof(stack_elem));
        stack p = NULL;
        p = s;

        for (unsigned int i = 0; i < len; i++){
            array[i] = p->elem;
            p = p->next;
        }
    }
    return array;
}

stack stack_destroy(stack s){
    stack p = NULL;
    if (!stack_is_empty(s))
    {
        p = s;
        s = s->next;
        free(p);
    }
    free(s);
    return NULL;
}


