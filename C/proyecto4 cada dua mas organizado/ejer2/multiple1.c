#include <stdio.h>

int x,y;

void imprimeEntero(int x,char let){
    printf("El valor de %c es: %d\n",let,x);
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

int main(void){
    x = pedirEntero('x');
    y = pedirEntero('y');

    y = y + x;
    x = x+1;

    imprimeEntero(x,'x');
    imprimeEntero(y,'y');
}