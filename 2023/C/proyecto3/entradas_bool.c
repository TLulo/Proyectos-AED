#include <stdio.h>
#include <stdbool.h>

int reserva;
bool x;

bool pedirBooleano(void){
    printf("Ingrese el valor de verdad de x: ");
    scanf("%d",&reserva);
    x = reserva;
    return x;
}

void imprimeBooleano(bool x){
    if (x){
        printf("El valor ingresado es True\n");
    }
    else{
        printf("el valor ingresado es False\n");
    }
}

int main(void){
    x = pedirBooleano();
    imprimeBooleano(x);
}