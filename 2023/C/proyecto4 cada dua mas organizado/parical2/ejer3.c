#include <stdio.h>
#include<limits.h>
#include <assert.h>
#define N 5

struct minmul_t{
int minimo;
int indice;
};

struct minmul_t multiplo_minimo(int a[], int tam, int k){
    struct minmul_t res;
    int i;
    res.minimo = INT_MAX;
    res.indice = -1;
    i = 0;
    while (i < tam){
        if (a[i] % k == 0 && a[i] < res.minimo){
            res.minimo = a[i];
            res.indice = i;
            i = i+1;
        }else{
            i = i+1;
        }
    }
    return res;
};

void pedirArreglo(int a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el valor del arreglo en la posicion %d: ",i);
        scanf("%d",&a[i]);
        i=i+1;
    }
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void imprimeEnteros(struct minmul_t p){
    printf("El multiplo minimo es: %d\nEl valor del indice es: %d\n",p.minimo,p.indice);
}

int main(void){
    int k;
    int a[N];
    struct minmul_t r;
    k = pedirEntero('k');
    assert(k!=0);
    pedirArreglo(a,N);
    r = multiplo_minimo(a,N,k);
    imprimeEnteros(r);
}