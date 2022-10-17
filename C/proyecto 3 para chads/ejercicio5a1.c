#include <stdio.h>

int main() {
int i, estado;
estado = 1;
printf ("\nEjercicio 1.h\n");
printf("Ingrese la variable i\n");
scanf("%d", &i);
printf("σ0: i -> %d\n\n", i);

while(i != 0)
{
printf("σ1^%d: i -> %d\n\n", estado, i);
    i-- ;
printf("σ2^%d: i -> %d\n\n", estado, i);
estado++;
}
printf("σ3: i -> %d", i);

}

/*
σ0: i -> 4

σ1^1: i -> 4

σ2^1: i -> 3

σ1^2: i -> 3

σ2^2: i -> 2

σ1^3: i -> 2

σ2^3: i -> 1

σ1^4: i -> 1

σ2^4: i -> 0

σ3: i -> 0
*/
