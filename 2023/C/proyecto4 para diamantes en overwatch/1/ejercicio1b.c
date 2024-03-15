#include <stdio.h>
#include <assert.h>

int x, y, m, z;
int minimo(int a, int b){
assert(a == x && b == y);
int m;
m = 0;
if (x < y)
{
m = x;
}
else {
m = y;    
}
assert(m == x || m == y);
return m;
}

int valor_Absoluto(int a){
assert(a == x);
int m;
if (a >= 0){
m = a;
}
else if (a < 0){
m = -a;
}
assert(m == x || m == -x);
return m;}

void intercambio(int a, int b,int c){
assert(a == x && b == y && c == z);
int a2,b2,c2;
a2= a;
b2 = b;
c2 = c;
assert(a2 == x && b2 == y && c2 == z);
a= b2;
b = c2;
c = a2;
assert(a == y && b == z && c == x);
printf("El valor de x es: %d\n", a);
printf("El valor de y es: %d\n", b);
printf("El valor de z es: %d\n", c);
}

int main(void)
{
printf("Ingrese el valor de x: ");
scanf("%d",&x);
printf("Ingrese el valor de y: ");
scanf ("%d", &y);
printf("Ingrese el valor de z: ");
scanf ("%d", &z);

printf("El minimo es: %d\n", minimo(x, y));
printf("El valor absoluto de x es: %d\n", valor_Absoluto(x));
intercambio(x, y, z);
}