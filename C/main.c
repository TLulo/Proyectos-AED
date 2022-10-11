/*
LAS FUNCIONES ESTAN PUESTAS PARA COMPILARLAS UNA A UNA.
Ejercicio 1
*/
#include <stdio.h>
#include <stdbool.h>

bool resc,rese;
int x, y, z, a, b, c , d, e;
int main(void)
{
    printf("Ingrese el valor de x:");
    scanf("%d", &x);

    printf("Ingrese el valor de y:");
    scanf("%d", &y);
    
    printf("Ingrese el valor de z:");
    scanf("%d", &z);

    a = x + y + 1;
    b = z * z + y * 45 -15 * x;
    c = y-2 == (x * 3 + 1) % 5;
    d = y / 2 * x;
    e = y < x * z;
    resc = c;
    rese = e;

    printf("El resultado de la primera ecuacion es: %d\n",a);
    printf("El resultado de la segunda ecuacion es: %d\n",b);
    printf("El resultado de la tercera ecuacion es: %d\n",resc);
    printf("El resultado de la cuarta ecuacion es: %d\n",d);
    printf("El resultado de la quinta ecuacion es: %d\n",rese);    
}
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
    func = !b  && w;
}
