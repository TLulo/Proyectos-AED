#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x >= 0)
    {
        *y = x;
    }else
    {
        *y = -x;
    }   
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---
    a = -10;
    absolute(a,&res);
    printf("%d\n",res);

    //
    // Completar aquí
    //
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

//C) * la variable *y es de tipo out

//* C tiene los tres tipos de parametros, in en un tipo int como en el abs1, out utilizando punteros solo para cambiar el valor,
//in/out en punteros que se utilizan adentro de la misma funcion.

