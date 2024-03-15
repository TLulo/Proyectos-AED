#include <stdio.h>
int x, y, z, x2, y2;
int main(void)
{
printf("Ingrese el valor de x:\n");
scanf("%d",&x);
printf("Ingrese el valor de y:\n");
scanf("%d",&y);
printf("Ingrese el valor de z:\n");
scanf("%d",&z);

x2 = y;
y2 = y + x + z;
z = x + y; 

printf("El valor de x es: %d\n", x2);
printf("El valor de y es: %d\n", y2);
printf("El valor de z es: %d\n", z);
}