#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int list_elem;

typedef struct  Node * list;

//CONSTRUCTORS
list empty(void);
/*
Crea la lista vacia
*/

list addl(list_elem e,list l);
/*
Agrega el elemento e al comienzo de la lista
*/

void destroy(list l);
/*
Free memory if is necesary
*/

list copy_list(list l);
/*
Copy all elements to l in other list
*/

//OPERATIONS
bool is_empty(list l);
/*
Return whether the list l has the initial value.
*/

list_elem head(list l);
/*
PRE: l not is_empty
Return first element to list l
*/

list tail(list l);
/*
Remove first element to list l
*/

list addr(list l, list_elem e);
/*
Add element in last position of list l
*/

int length(list l);
/*
Return amount of elements in list l
*/

list concat(list l1, list l2);
/*
Add all elements to l2 in the end to l1
*/

list_elem index(list l, int i);
/*
PRE: list have at least i elements
Return the i'th element to l 
*/

list take(list l, int i);
/*
Take first i elements to l
*/

list drop(list l, int i);
/*
Remove first i elements
*/

#endif