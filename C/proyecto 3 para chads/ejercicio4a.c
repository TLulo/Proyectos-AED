#include <stdio.h>
 
int main(void)
{
int x, y;
printf("Ingrese el valor de x:\n");
scanf("%d",&x);
printf("Ingrese el valor de y:\n");
scanf("%d",&y);
printf("Ingrese el valor de z:\n");

if (x >= y)
{
printf("Resultado: 0 \n");
return 0;
}
else if (y >= x)
{
printf("Resultado: 2 \n");
return 2;
}

return 0;
}
