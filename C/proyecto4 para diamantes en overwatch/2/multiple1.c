#include <stdio.h>
int x, y;
int main(void)
{
printf("Ingrese el valor de x:\n");
scanf("%d",&x);
printf("Ingrese el valor de y:\n");
scanf("%d",&y);

y = x + y;
x = x + 1;

printf("El valor de x es: %d\n", x);
printf("El valor de y es: %d\n", y);
}