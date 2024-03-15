#include <stdio.h>
#include <assert.h>
int x, m;
int pedirEntero (void)
{
    printf("Ingrese el entero: \n");
    scanf("%d", &m);
    return m;
}

void holaHasta(int x)
{
while (x > 0)
{
    printf("hola\n");
    --x;
} 
assert (x == 0);
}

int main(void)
{
x = pedirEntero();
holaHasta(x);
}