#include <stdio.h>
#include <stdbool.h>

int m;
int pedirBool(void)
{
    printf("Ingrese Bool: \n");
    scanf("%d", &m);
    return m;
}

void imprimeBool(bool x)
{
printf("Bool: %d", x);
}
int main(void)
{
m = pedirBool();
imprimeBool(m);
}