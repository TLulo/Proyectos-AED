#include <stdio.h>

int main() {
int i;
printf ("\nEjercicio 1.i\n");
printf("Ingrese la variable i\n");
scanf("%d", &i);
printf("σ0: i -> %d\n\n", i);

while(i != 0)
{
printf("σ1^1: i -> %d\n\n", i);
    i = 0 ;
printf("σ2^1: i -> %d\n\n", i);
}

printf("σ3: i -> %d", i);

}

/*
σ0: i -> 400

σ1^1: i -> 400

σ2^1: i -> 0

σ3: i -> 0
*/