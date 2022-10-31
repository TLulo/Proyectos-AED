#include <stdio.h>
#include <limits.h>

void pedirArray(float a[], int n_max){
int i;
i = 0;
while (i<n_max){
printf("En la posicion %d introduzca el valor del array: \n", i);
scanf("%f", &a[i]);
i++;
}}


struct datos_t {
float maximo;
float minimo;
float promedio;
};

struct datos_t stats(float a[], int tam){
int i;
float res;
res = 0; 
i = 0;
struct datos_t n; 
n.maximo = INT_MIN;
n.minimo = INT_MAX;
n.promedio = 0; 
while(i < tam){
if (a[i] < n.minimo){n.minimo = a[i];}
else{n.maximo = a[i];}
res = a[i] + res;
i++;
}
n.promedio = res / tam;
return n;
}
void print_stats(struct datos_t n){
printf("Maximo: %f\nMinimo: %f\nPromedio: %f\n", n.maximo, n.minimo, n.promedio);
}

int main(void){
int size;
printf("Introduzca el tamaño del array:");
scanf("%d", &size);
float a[size];
pedirArray(a, size);
print_stats(stats(a, size));

}