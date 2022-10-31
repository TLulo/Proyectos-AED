#include <stdio.h>
#define N 5

void pedirArreglo(int a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el valor del arreglo en la posicion %d: ",i+1);
        scanf("%d",&a[i]);
        i=i+1;
    }
}
int suma_cuadrados_pares(int a[], int tam){
    int i,res;
    i = 0;
    res = 0;
    while (i<tam){
        if (a[i] % 2 == 0){
            res = res+a[i]*a[i];
            i = i+1;
        }else{
            i = i+1;
        }
    }
    return res;
}
void imprimeEntero(int x,char let){
    printf("El valor de %c es: %d\n",let,x);
}
int main(void){
    int r;
    int a[N];
    pedirArreglo(a,N);
    r = suma_cuadrados_pares(a,N);
    imprimeEntero(r,'S');
}