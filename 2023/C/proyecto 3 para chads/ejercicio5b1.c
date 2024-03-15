#include <stdio.h>

int main() {
int i, x, y, estado;
estado = 0;
printf("Ingrese la variable i\n");
scanf("%d", &i);
i = 0;
printf("Ingrese la variable x\n");
scanf("%d", &x);
printf("Ingrese la variable y\n");
scanf("%d", &y);
while(x >= y)
{
    x = x - y;
    i++;
    printf("σ1^%d: i -> %d\n\n",estado, i);
    estado++;
}

}

/*
x -> 13, y -> 3, i -> 0 
iteracion 1: σ1^0: i -> 1

iteracion 2: σ1^1: i -> 2

iteracion 3: σ1^2: i -> 3

iteracion 4: σ1^3: i -> 4

almacena el numero de interaciones en i
*/