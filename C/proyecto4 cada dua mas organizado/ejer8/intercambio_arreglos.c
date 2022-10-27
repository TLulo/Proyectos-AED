#include <stdio.h>

int n;

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

void imprimeArreglo(int a[], int n_max){
    int i;
    i=0;
    while (i<n_max){
        printf("El valor en la posicion %d del arreglo es: %d\n",i+1,a[i]);
        i=i+1;
    }
}

void intercambiar(int a[],int tam,int i,int j){
    int iaux;
    iaux = a[i];
    a[i] = a[j];
    a[j] = iaux;
    imprimeArreglo(a,tam);
}


int main(void){
    int i,j;
    n = pedirEntero('n');   
    int a[n];
    printf("Ingrese las posiciones a intercambiar.\n");
    i = pedirEntero('i');
    j = pedirEntero('j');
    pedirArreglo(a,n);
    intercambiar(a,n,i-1,j-1);
}
