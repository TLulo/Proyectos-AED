#include <stdio.h>

int x;

int pedirEntero(void){
    printf("Ingrese el parametro a imprimir: ");
    scanf("%d",&x);
    return x;
}

void imprimeEntero(int x){
    printf("El valor de x es: %d\n",x);
}

int main(void){
    x = pedirEntero();
    imprimeEntero(x);
}