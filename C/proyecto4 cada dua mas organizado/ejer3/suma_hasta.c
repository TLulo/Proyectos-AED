#include <stdio.h>
#include <assert.h>

int N,res;

void imprimeEntero(int a,char let){
    printf("El valor de %c es: %d\n",let,a);
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

int suma_hasta(int n){
    int sumatoria = (n*(n+1))/2;

    return sumatoria;
}

int main(void){

    N = pedirEntero('x');

    assert(N>=0);

    res = suma_hasta(N);
    printf("La sumatoria es:\n");
    imprimeEntero(res,'S');
}