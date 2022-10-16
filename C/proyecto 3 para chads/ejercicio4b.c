#include <stdio.h>

/*
El programa compara x, y, z y almacena el más chico en m
*/

int main(void)
{
int x, y, z, m;
printf("Ingrese el valor de x:\n");
scanf("%d",&x);
printf("Ingrese el valor de y:\n");
scanf("%d",&y);
printf("Ingrese el valor de z:\n");
scanf("%d",&z);
printf("Ingrese el valor de m:\n");
scanf("%d",&m);
if (x < y)
m = x;
else 
m = y;
if (m < z)
printf("Resultado: %d", m);
else 
printf("Resultado: %d", z);


return 0;
}

/*
Resultado de m: 4
Otros estados iniciales x -> 1, y -> 6, z -> 9, m -> 5
Resultado m: 1
*/