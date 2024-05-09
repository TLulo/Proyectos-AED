#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0)
    {
        y = x;
    }else
    {
        y = -x;
    }   
    y =y; 
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a,res);
    printf("%d\n",res);

    return EXIT_SUCCESS;
}
//Imprime 0 que difiere con el teorico, pues luego de ejecutar el 'procedimiento' absolute el valor de y no se mantiene.
