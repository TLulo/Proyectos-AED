#include <stdio.h>

int x;

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void imprimeEntero(int x,char let){
    printf("El valor de %c es: %d\n",let,x);
}

int main(void){
    x = pedirEntero('x');
    imprimeEntero(x,'x');
}