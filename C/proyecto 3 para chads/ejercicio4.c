#include <stdio.h>

int x, y, z, m;

int f1e(int a, int b)
{
if (a >= b)
{return 0;}
else if (b >= a)
{return 2;} 
} 

/*
El programa compara x, y, z y almacena el más chico en m
*/
int f4b(int x, int y, int z, int m)
{
if (x < y)
{
m = x;}
else 
{m = y;}
if (m < z)
{return m;}
else 
{return z;}
}
int main(void)
{
printf("Ingrese el valor de x:\n");
scanf("%d",&x);
printf("Ingrese el valor de y:\n");
scanf("%d",&y);
printf("Ingrese el valor de z:\n");
scanf("%d",&z);
printf("Ingrese el valor de m:\n");
scanf("%d",&m);

printf("Resultado de f1e: %d\n",f1e(x, y));
printf("Resultado de f4b: %d\n",f4b(x, y, z, m));

return 0;
}

/*
Resultado de m: 4
Otros estados iniciales x -> 1, y -> 6, z -> 9, m -> 5
Resultado m: 1
*/