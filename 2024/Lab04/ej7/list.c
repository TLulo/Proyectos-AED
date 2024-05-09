#include "list.h"

#include <stdlib.h>
#include <assert.h>

typedef int list_elem;

struct Node
{
    list_elem elem;
    struct Node *next;
};

list empty(){
    list l = NULL;
    return l;
}

list addl(list_elem e, list l){
    list p = malloc(sizeof(list));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}

void destroy(list l){
    list p = l;
    if(!is_empty(l)){
        while (p->next != NULL)
        {
            p = p->next;
            free(l);
            l = p;
        }
    }
    
}

list copy_list(list l){
    unsigned int n;
    list l2 = malloc(sizeof(l));
    n = length(l);
    for (unsigned int i = 0; i < n; i++)
    {
        l2->elem = l->elem;
        l2->next = l->next;
    }
    return l2;
}

bool is_empty(list l){
    bool res = false;
    if (l == NULL)
    {
        res = true;
    }
    return res;
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l){
    assert(!is_empty(l));
    list q = l;
    l = l->next;
    free(q);
    return l;
}

list addr(list l, list_elem e){
    list p,q;
    p = l;
    q = malloc(sizeof(list));
    q->elem = e;
    q->next = NULL;

    if (is_empty(l))
    {
        l = q;
    }else{
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
    return l;
}

int length(list l){
    list q;
    q = l;
    unsigned int res = 0;
    if (!is_empty(l))
    {
        while (q->next != NULL){
            q = q->next;
            res ++;
        }
    }
    return res;
}

list concat(list l1,list l2){
    list p;
    p = l1;
    if (is_empty(l1))
    {
        l1 = l2;
    }else{
        while (p->next != NULL){
            p = p->next;
        }
        p->next = l2;
    }
    return l1;
}

list_elem index(list l, int i){
    assert(length(l) > i);
    list p = l;
    for (int j = 0; j < i && p->next != NULL ; j++)
    {
        p = p->next;
    }
    return p->elem;
}

list take(list l, int i){
    list p = l;
    list q;
    q = empty();
    if (!is_empty(l))
    {
        for (int j = 0; j < i && p->next != NULL ; j++)
        {
            addr(q,p->elem);
            p = p->next;
        }
    }
    destroy(l);
    return q;
}

list drop(list l, int i){
    list p,q;
    if (length(l) < i)
    {
        destroy(l);
        p = NULL;
    }else{
        p = l;
        q = l;
        for (int j = 0; j < i && p->next != NULL ; j++)
        {
            p = p->next;
            free(q);
            q = p;
        }
        
    }
    return p;
}