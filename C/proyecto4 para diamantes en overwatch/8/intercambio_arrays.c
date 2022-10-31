#include <stdio.h>

void pedirArray(int a[], int n_max){
int i;
i = 0;
while (i<n_max){
printf("En la posicion %d introduzca el valor del array: \n", i);
scanf("%d", &a[i]);
i++;
}}
void imprimeArray(int a[], int n_max){
int i;
i = 0;
while(i<n_max){
printf("El valor del array en la posicion %d es: %d\n", i, a[i]);
i++;
}}

void intercambiar(int a[], int tam, int i, int j){
if (tam>i && tam>j){
int res;
res = a[i];
a[i] = a[j];
a[j] = res;
}
}

int main(void){
int size, x, y;
printf("Introduzca el tamaño del array:");
scanf("%d", &size);
int a[size];
x = size + 1;
y = size + 1;
pedirArray(a, size);
while(x > size || y > size){
printf("Introduzca posiciones validas.\n");
printf("Posicion i:\n");
scanf("%d", &x);
printf("Posicion j:\n");
scanf("%d", &y);
}

intercambiar(a, size, x, y);
imprimeArray(a, size);
}