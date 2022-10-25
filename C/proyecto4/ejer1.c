#include <stdio.h>
#include <assert.h>

int n;

int pedirEntero(void){
    int x;
    printf("Ingrese el numero de veces a imprimir: ");
    scanf("%d",&x);
    return x;
}

void holaHasta(int n){
    int i;
    i = 0;
    while (i < n){
        printf("Hola\n");
        i = i + 1;
    }
}

int main(void){
    n = pedirEntero();
    assert (n > 0);
    holaHasta(n);

}
