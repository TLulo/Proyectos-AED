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
int main(void){
int size;
printf("Introduzca el tamaño del array:");
scanf("%d", &size);
int a[size];

pedirArray(a, size);
imprimeArray(a, size);
}