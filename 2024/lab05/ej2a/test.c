#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "arrayhelpers.h"

int main(void){
    int u = -1;
    stack_elem *a;
    unsigned int b = 0u;
    stack s = stack_empty();
    

    printf("Ingrese cuantos elementos tendra la pila test. \n");
    
    while (u < 0)
    {
        printf("Ingrese un valor mayor o igual que cero:\n");
        scanf("%d",&u);
    }
    for (int i = 0; i < u; i++)
    {
        s = stack_push(s,i);
    }

    b = stack_size(s);
    printf("\n**STACK SIZE\n%d\n**", b);

    a = stack_to_array(s);
    printf("\nArray:\n");
    if (!stack_is_empty(s))
    {
        for (int i = 0; i < u; i++)
        {
            printf("\n%d\n",a[i]);
        }
        
    }else{
        printf("\nArreglo vacio \n");
    }
    
    for (int i = 0; i < u; i++)
    {
        s = stack_pop(s);
    }

    if (stack_is_empty(s))
    {
        printf("\nse vacio la pila \n");
    }
    

    s = stack_push(s,35);
    printf("\nSe agrego %d a la lista vacia\n",stack_top(s));
    s = stack_destroy(s);
    destroy_array(a);
}