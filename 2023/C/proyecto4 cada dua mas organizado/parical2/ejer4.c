#include <stdio.h>
#define N 3

struct producto_t {
int precio;
int peso_en_kilos;
};

struct total_t {
int precio_total;
int peso_total;
};

struct total_t calcular_montos(struct producto_t a[], int tam){
    int i;
    i=0;
    struct total_t res;
    res.precio_total = 0;
    res.peso_total = 0;
    while (i<tam){
        res.precio_total = a[i].precio + res.precio_total;
        res.peso_total = a[i].peso_en_kilos + res.peso_total;
        i= i+1;
    }
    return res;
}

void pedirArreglo(struct producto_t a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el precio en la posicion %d: ",i+1);
        scanf("%d",&a[i].precio);
        printf("Ingrese el peso en la posicion %d: ",i+1);
        scanf("%d",&a[i].peso_en_kilos);
        i=i+1;
    }
}

void imprimeEnteros(struct total_t p){
    printf("El Peso total en kg es: %d\nEl precio total es: %d\n",p.peso_total,p.precio_total);
}

int main(void){
    struct total_t s;
    struct producto_t a[N];
    pedirArreglo(a,N);
    s = calcular_montos(a,N);
    imprimeEnteros(s);
}