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
Ingrese el valor de x:7
Ingrese el valor de y:3
Ingrese el valor de z:5
El resultado de la primera ecuacion es: 11
El resultado de la segunda ecuacion es: 55
El resultado de la tercera ecuacion es: 0
El resultado de la cuarta ecuacion es: 7
El resultado de la quinta ecuacion es: 1
-------------------------------
Ingrese el valor de x:1
Ingrese el valor de y:10
Ingrese el valor de z:8
El resultado de la primera ecuacion es: 12
El resultado de la segunda ecuacion es: 499
El resultado de la tercera ecuacion es: 0
El resultado de la cuarta ecuacion es: 5
El resultado de la quinta ecuacion es: 0
*/
