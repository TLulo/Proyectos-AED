#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    unsigned int size;
    struct s_node*front;
};

struct s_node {
    pstack_elem elem;
    unsigned int priority;
    struct s_node*next;
};

static struct s_node * create_node(pstack_elem e, priority_t priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node -> elem = e;
    new_node -> next = NULL;
    new_node -> priority = priority;
    //assert(e==e && priority == priority); // BORRAR ESTE ASSERT
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pstack s) {
    bool inv = true;
    if(s->size == 0){
        inv = true;
    }
    else{
        struct s_node * index = s->front;
        if(index != NULL){
            while(index != NULL){//Chequeo que esten ordenados por prioridad
                if(index->next != NULL){
                    if(index->priority < (index->next)->priority){
                        inv = false;
                    }
                }
                index = index->next;
            }
        }
    }
    //assert(s==s); // BORRAR ESTE ASSERT
    return inv;
}

// bool pstack_is_ord(pstack s) {
//     bool is_ord = true;
//     struct s_node *index = s -> front;
//     while (is_ord && index != NULL && index->next != NULL)
//     {
//         is_ord &= index -> priority <= (index -> next)-> priority;
//         index = index -> next;
//     }
//     return is_ord;
// }

// static bool invrep(pstack s) {
//    bool is_valid = s != NULL ? pstack_is_ord(s) : true;        
//    return is_valid;
// }

pstack pstack_empty(void) {
     pstack s=NULL;
     s = malloc(sizeof(struct s_pstack));
     s -> size = 0;
     s -> front = NULL;
     return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    s -> size += 1; 
    struct s_node *new_node = create_node(e, priority);
    struct s_node *index = s -> front;
    struct s_node *parent = NULL;
    bool flag = true;
    if (index == NULL)
    {
        s -> front = new_node;
    } else{
        while (flag && priority < index -> priority)
        {   
            parent = index;
            index = index -> next;
            if(index == NULL){
                flag = false;
            }
        }
        new_node -> next = index;
        if(parent != NULL){
            parent -> next = new_node;
        }else{
            s -> front = new_node;
        }
        
    }
    
    //assert(e==e && priority==priority && new_node==new_node); // BORRAR ESTE ASSERT
    return s;
}

// pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
//     assert(invrep(s) && s != NULL);
//     struct s_node *new_node = create_node(e, priority);
//     struct s_node * index = s->front;
//     struct s_node * aux;
//     if(pstack_is_empty(s)){//Si esta vacio el stack lo pongo primero
//         s->front= new_node;
//     }
//     //Si tiene la misma o mas prioridad que el primero lo pongo primero
//     else if((new_node->priority == index->priority) || (new_node->priority > index->priority)){
//         new_node->next = index;
//         s->front = new_node;
//     }
//     //Si tiene menos prioridad que el primero lo agrego justo despues del elemento con mayor prioridad
//     //a el y antes de los que tengan la misma o menos prioridad
//     else if(new_node->priority < index->priority){
//         while( index != NULL && index->priority > new_node->priority){
//             aux = index;
//             index = index->next;
//         }
//         new_node->next = aux->next;
//         aux->next = new_node;
//     }
//     s->size++;
//     assert(invrep(s) && s != NULL && !pstack_is_empty(s));
//     //assert(e==e && priority==priority && new_node==new_node); // BORRAR ESTE ASSERT
//     return s;
// }

bool pstack_is_empty(pstack s) {
    //assert(s==s);
    return (s -> size == 0);
}

pstack_elem pstack_top(pstack s) {
    pstack_elem top = (s -> front) -> elem;
    //assert(s==s);
    return top;
}

priority_t pstack_top_priority(pstack s) {
    priority_t worst;
    worst = (s->front) -> priority;
    //assert(s==s); // BORRAR ESTE ASSERT
    return worst;
}

unsigned int pstack_size(pstack s) {
    assert(invrep(s));
    unsigned int size=s->size;
    return size;
}

pstack pstack_pop(pstack s) {
    struct s_node*killme = s -> front;
    s -> front = s -> front -> next;
    s -> size -= 1;
    killme = destroy_node(killme);
    assert(s==s); // BORRAR ESTE ASSERT
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    while (s->front != NULL)
    {
        s = pstack_pop(s);
    }
    free(s);
    s = NULL;
    assert(s == NULL);
    return s;
}

