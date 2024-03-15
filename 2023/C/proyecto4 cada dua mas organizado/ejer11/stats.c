#include <stdio.h>
#include <limits.h>
#include <assert.h>

struct datos_t{
    float maximo;
    float minimo;
    float promedio;
};

struct datos_t stats(float a[],int tam){
    struct datos_t res;
    int i;
    float suma;
    res.maximo=INT_MIN;
    res.minimo=INT_MAX;
    i = 0;
    suma = 0;
    while (i<tam){
        suma = a[i] +suma;
        
        if (a[i]<res.minimo){
            res.minimo = a[i];
        }else{
            res.minimo = res.minimo;
        }

        if (a[i]>res.maximo){
            res.maximo = a[i];
        }else{
            res.maximo = res.maximo;
        }
        i = i+1;
    }
    res.promedio = suma/tam;
    return res;
};

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void pedirArreglo(float a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el valor del arreglo en la posicion %d: ",i+1);
        scanf("%f",&a[i]);
        i=i+1;
    }
}

void imprimeEnteros(struct datos_t p){
    printf("El valor Maximo: %f\nEl valor minimo es: %f\nEl promedio es: %f\n",p.maximo,p.minimo,p.promedio);
}

int main(void){
    int n;
    n = pedirEntero('n');
    assert(n>0);
    float a[n];
    pedirArreglo(a,n);
    imprimeEnteros(stats(a,n));
}


//-------------------------------COMIT------------------------------

// Online C compiler to run C program online
#include <stdio.h>
#include <limits.h>

struct datos_t {
float maximo;
float minimo;
float promedio;
};

struct datos_t stats(float a[], int tam){
    float min,max,sum,prom;
    int i;
    struct datos_t stats;
    stats.minimo = INT_MAX;
    stats.maximo = INT_MIN;
    sum=0;
    while(i < tam) {
        sum= a[i] + sum;
        if (a[i] < stats.minimo) {
            stats.minimo=a[i];
        } else if (a[i] > stats.maximo){
            stats.maximo=a[i];
        }
        i = i + 1;
        }
        stats.promedio = sum/tam;
    
    printf("Los stats son:\nMaximo:%f\nMinimo:%f\nPromedio:%f\n",stats.maximo,stats.minimo,stats.promedio);
}

void pedirArreglo(float a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el valor del arreglo en la posicion %d: ",i+1);
        scanf("%f",&a[i]);
        i=i+1;
    }
}

int pedirEntero(void){
    int a;
    printf("Ingrese un valor:");
    scanf("%d",&a);
    return a;
}
    

int main() {
    int n;
    n = pedirEntero();
    float a[n];
    pedirArreglo(a,n);
    stats(a,n);

    return 0;
}
