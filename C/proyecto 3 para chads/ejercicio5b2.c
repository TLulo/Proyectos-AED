#include <stdio.h>
#include <stdbool.h>

int main() {
int i, x, estado, res;

estado = 0;
printf("Ingrese la variable i\n");
scanf("%d", &i);
i = 2;
printf("Ingrese la variable x\n");
scanf("%d", &x);
printf("Ingrese la variable res\n");
scanf("%d", &res);
res = true;
while(i < x && res)
{
    res = res && ( x % i != 0);
    i++;
    printf("σ1^%d: i -> %d\n\n",estado, i);
    estado++;
}

}

/*
x -> 5, i -> 0, res -> false 

σ1^0: i -> 3

σ1^1: i -> 4

σ1^2: i -> 5

Aumenta en una unidad a i hasta que este sea mayor que x o sea multiplo de x. 
*/