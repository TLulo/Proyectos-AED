#include <stdio.h>
int x, y, z, m;
int pedirEntero (void)
{
    printf("Ingrese el entero: \n");
    scanf("%d", &m);
    return m;
}

void imprimeEntero(int x)
{
printf("Entero: %d", x);
}
int e4 (int x, int y, int z)
{
if (x < y)
{
m = x;}
else 
{m = y;}
if (m < z)
{return m;}
else 
{m = z;}

return 0;
}


int main(void)
{

x = pedirEntero();
y = pedirEntero();
z = pedirEntero();

imprimeEntero(e4(x, y, z));

return 0;
}