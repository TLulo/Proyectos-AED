#include <stdio.h>

int n,sum;

int sumatoria(int a[],int tam){
    int i,res;
    i = 0;
    res = 0;
    while (i<tam){
        res=a[i] + res;
        i = i+1;
    }
    return res;
}

void imprimeEntero(int a,char let){
    printf("El valor de %c es: %d\n",let,a);
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void pedirArreglo(int a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el valor del arreglo en la posicion %d: ",i+1);
        scanf("%d",&a[i]);
        i=i+1;
    }
}

int main(void){
    n = pedirEntero('n');
    int a[n];
    pedirArreglo(a,n);
    sum = sumatoria(a,n);
    printf("La solucion es:");
    imprimeEntero(sum,'S');
}