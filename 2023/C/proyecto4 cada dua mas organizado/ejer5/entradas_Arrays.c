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

int main(void){
    n = pedirEntero('n');
    int a[n];
    pedirArreglo(a,n);
    imprimeArreglo(a,n);
}


//-----------------------------ASI S HACE BIEN DEA-------------------------------------------------

#include <stdio.h>

int pedirEntero(void){
    int i;
    printf("Introduzca un numero:\n");
    scanf("%d",&i);
    return i;
}

void pedirArreglo(int a[], int n_max) {
    int i;
    i = 0;
    while (i < n_max) {
        printf("Ingrese el valor del arreglo en la posicion %d:", i);
        scanf("%d",&a[i]);
        i=i+1;
    }
}

void imprimeArreglo(int a[], int n_max){
    int i;
    i=0;
    while(i < n_max) {
        printf("El numero %d esta en la posicion %d;\n", a[i],i);
        i = i+1;
    }
}

int main (void) {
    int n;
    n = pedirEntero();
    int a[n];
    pedirArreglo(a,n);
    imprimeArreglo(a,n);
}
