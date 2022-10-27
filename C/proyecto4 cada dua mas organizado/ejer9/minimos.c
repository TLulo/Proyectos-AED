#include <stdio.h>
#include <limits.h>
#include <assert.h>

int min;

int min_pares(int a[],int tam){
    int i;
    min = INT_MAX;
    i = 0;
    while (i < tam){
        if (a[i] % 2==0 && a[i]<min){
            min = a[i];
            i=i+1;
        }else{
            i = i+1;
        }
    }
    return min;
}

int min_impares(int a[],int tam){
    int i;
    min = INT_MAX;
    i = 0;
    while (i<tam){
        if (a[i]%2!=0 && a[i]<min){
            min = a[i];
            i = i+1;
        }else{
            i = i+1;
        }
    }
    return min;
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

void imprimeEntero(int x,char let){
    printf("El valor de %c es: %d\n",let,x);
}

void condicional_infinito(int x){
    if (x==2147483647){
        printf("El valor de S es: Infinito.\n");
    }else{
        imprimeEntero(x,'S');
    }
}

int main(void){
    int n,min_par,min_impar;
    n = pedirEntero('n');
    assert(n>=0);   
    if (n == 0){
        printf("El arreglo no tiene elementos.\n");
    }else{
        int a[n];
        pedirArreglo(a,n);
        min_par = min_pares(a,n);
        min_impar = min_impares(a,n);
        printf("El minimo valor par del arreglo es.\n");
        condicional_infinito(min_par);
        printf("El minimo valor impar del arreglo es.\n");
        condicional_infinito(min_impar);
    }
}