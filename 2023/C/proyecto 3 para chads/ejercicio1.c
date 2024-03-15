#include <stdio.h> 

int main(void)
{
int x, y, z;
printf("Ingrese la variable x\n");
scanf("%d",&x);
printf("Ingrese la varible y\n");
scanf("%d",&y); 
printf("Ingrese la variable z\n");
scanf("%d", &z);

printf("x + y + 1 = %d \n", x + y + 1); 
printf("z * z + y * 45 - 15 * x = %d\n", z * z + y *45 - 15 * x);
printf("y - 2 == (x * 3 + 1 ) % 5 = %d\n", y - 2 == (x * 3 + 1) % 5);
printf("y / 2 * x = %d\n", y / 2 * x );
printf("y < x * z = %d\n", y < x * z);
 
return 0;

}

/* 
x + y + 1 = 11, 12 
z * z + y * 45 - 15 * z = 55, 499
y - 2 == (x * 3 + 1) % 5 = 0, 0
y / 2 * x = 7, 5 
y < x * z = 1, 0

Tiene resultado entero ya que los booleanos son representados en C como 0 para False y 1 para True
*/ 
