#include <stdio.h>

int f1c(int a, int b)
{
b = b + b;
a = a + b;
printf("f1c\n");
printf("Estado final x: %d\n",a);
printf("Estado final y: %d\n",b);
}
int main(void) 
{
int x, y;
printf("Ingrese la variable x\n");
scanf("%d",&x);
printf("Ingrese la varible y\n");
scanf("%d",&y); 

y = y + y;
x = x + y;

printf("Estado final x: %d\n",x);
printf("Estado final y: %d\n",y);

return 0;
}

/*
.               Ingreso              Salida 
1a
Ejecucion 1     x -> 5
Ejecucion 2     x -> 1               x -> 5
Ejecucion 3     x -> 3
1b
Ejecucion 1     x -> 5, y -> 1      x -> 6, y -> 2
Ejecucion 2     x -> 8, y -> 3      x -> 11, y -> 6
Ejecucion 3     x -> 3, y -> 4      x -> 11 , y -> 8 
1c
Ejecucion 1     x -> 4, y -> 4      x -> 12, y -> 8
Ejecucion 2     x -> 1, y -> 5      x -> 11, y -> 10
Ejecucion 3     x -> 9, y -> 1      x -> 11, y -> 2
*/