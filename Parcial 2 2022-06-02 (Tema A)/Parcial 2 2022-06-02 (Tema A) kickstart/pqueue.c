#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    struct s_node * first;
    unsigned int size;
};

struct s_node {
    unsigned int priority;
    pqueue_elem elem;
    struct s_node * next;
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->priority = priority;
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}

bool is_ord(pqueue q) {
    bool is_ord_b = true;
    struct s_node *pointer = q -> first;
    while (is_ord_b && pointer!= NULL && pointer -> next != NULL)
    {
        is_ord_b &= pointer -> priority <= (pointer -> next) -> priority;
        pointer = pointer -> next;
    }
    return is_ord_b;
}

static bool invrep(pqueue q) {
    return (q!=NULL ? is_ord(q) : true);
}

pqueue pqueue_empty(void) {
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));
    q->first = NULL;
    q->size = 0;
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    q -> size += 1; 
    struct s_node * pointer_node = q->first;
    struct s_node * parent = NULL;
    bool flag = true;
    if(pointer_node == NULL){
        q->first = new_node;
    }else{
        while (flag && priority >= pointer_node -> priority)
        {
            parent = pointer_node;
            pointer_node = pointer_node -> next;
            if (pointer_node == NULL)
            {
                flag = false;
            }
        }
        new_node -> next = pointer_node;
        if (parent != NULL)
        {
            parent -> next = new_node;
        } else {
            q -> first = new_node;
        }
    }
    assert(invrep(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    return (q->size == 0);
}

pqueue_elem pqueue_peek(pqueue q) {
    pqueue_elem res = (q->first)->elem;
    return res;
}

unsigned int pqueue_peek_priority(pqueue q) {
    unsigned int res = (q->first)->priority;
    return res;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    unsigned int size=0;
    size = q->size;
    return size;
}

pqueue pqueue_dequeue(pqueue q) {
    struct s_node * elim_node;
    elim_node = q->first;
    q->first = (q->first)->next;
    q->size--;
    elim_node = destroy_node(elim_node);
    elim_node = NULL;
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    while(q->first != NULL){
        q = pqueue_dequeue(q);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}