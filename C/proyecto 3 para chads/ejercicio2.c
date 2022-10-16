#include <stdio.h>
#include <stdbool.h>

int main(void)
{
int x, y, z, tempb, tempw;
bool b, w;
printf("Ingrese la variable x\n");
scanf("%d",&x);
printf("Ingrese la varible y\n");
scanf("%d",&y); 
printf("Ingrese la variable z\n");
scanf("%d", &z);
printf("Ingrese la variable b\n");
scanf("%d", &tempb);
printf("Ingrese la variable w\n");
scanf("%d", &tempw);

b = tempb;
w = tempw;
/*
x = 4, y = -4 , z = 8 , b = 1, w = 0 
*/

printf("x % 4 == 0 = %d\n", x % 4 == 0);
printf("x + y == 0 && y - x == (-1) * z = %d\n", x + y == 0 && y - x == (-1) * z);
printf("not b && w = %d\n", !b && w);

return 0;

}