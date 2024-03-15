#include <stdio.h>
void pedirArray(int a[], int n_max){
int i;
i = 0;
while (i<n_max){
printf("En la posicion %d introduzca el valor del array: \n", i);
scanf("%d", &a[i]);
i++;
}}

int sumatoria(int a[], int tam){
int i, res;
i = 0;
res =0;
while (i < tam ){
res = a[i] + res;
i++;
}
printf("El resultado de la sumatoria: %d\n", res);
}

int main(void){
int size;
printf("Introduzca el tamaño del array:\n");
scanf("%d", &size);
int a[size];
pedirArray(a, size);
sumatoria(a, size);


}