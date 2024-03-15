#include <stdio.h>
#include <stdbool.h>

int pedirEnterobucle(char let){
    int a;
    a= -1;
    while (a <0){
        printf("Ingrese un valor de %c no negativo:",let);
        scanf("%d",&a);
        if (a>=0){
            a = a;
        }else{
            printf("Error, introdujo un valor negativo\n");
        }
    }
    return a;
}

bool esprimo(int x){
    int i;
    i = 2;
    if (x == 1){
        return 0;
    }else{
        while (i<x){
            if (x % i == 0){
                return 0;
            }else{
                i= i+1;
            }
        }
        return 1;
    }
}

void nprimo(int x,int a[]){
    int i,j;
    i = 0;
    j = 0;
    while (j<=x){
        if (esprimo(i)){
            a[j]=i;
            j = j+1;
            i = i+1;
        }else{
            i = i+1;
        }
    }
}


int main(void){
    int n;
    n = pedirEnterobucle('n');
    int a[n];
    nprimo(n,a);
    printf("El %d-esimo primo es: %d\n",n,a[n]);
}