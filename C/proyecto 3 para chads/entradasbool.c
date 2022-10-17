#include <stdio.h>
#include <stdbool.h>

bool m;
int temp; 
int pedirBool(void)
{
    printf("Ingrese Bool: \n");
    scanf("%d", &temp);
    m = temp;
    return temp;
}

void imprimeBool(bool x)
{
if (x)
{printf("true");}
else{printf("false");}
}
int main(void)
{;
imprimeBool(pedirBool());
}
