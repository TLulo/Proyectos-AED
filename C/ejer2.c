
/*
Ejercicio 2
*/
#include <stdio.h>
#include <stdbool.h>

bool b,w,funa ,funb ,func;
int x, y, z, btemp, wtemp;
int main(void)
{
    printf("Ingrese el valor de x:");
    scanf("%d", &x);

    printf("Ingrese el valor de y:");
    scanf("%d", &y);
    
    printf("Ingrese el valor de z:");
    scanf("%d", &z);
    
    printf("Ingrese el valor de b:");
    scanf("%d", &btemp);
    
    printf("Ingrese el valor de w:");
    scanf("%d", &wtemp);

    w=wtemp;
    b=btemp;

/*
x=4     y=-4    z=8      b=0    w=5
*/
    funa = x % 4 == 0;
    funb = x + y == 0 && y - x == (-1) * z;
    func = !b  && w; // tiene que dar false. Con b = 0 w = 5 da true 
}
