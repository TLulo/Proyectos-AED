#include <stdio.h>
int N, res;
res = 0;
int suma_hasta(int a)
{
while(a>0)
{
res = a + res;
a--;
}
return res;
}

int main(void)
{
printf("Ingrese el valor de N:\n");
scanf("%d",&N);
while (N<0){printf("Error :: el valor de N tiene que ser natural");
printf("Ingrese el valor de N:\n");
scanf("%d",&N);}
printf("Resultado: %d", suma_hasta(N));
}