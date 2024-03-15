#include <stdio.h>
#include <limits.h>
void pedirArray(int a[], int n_max){
int i;
i = 0;
while (i<n_max){
printf("En la posicion %d introduzca el valor del array: \n", i);
scanf("%d", &a[i]);
i++;
}}

int minimo_pares(int a[], int tam){
int i, min;
min = INT_MAX;
i = 0;
while(i < tam){
if ((a[i] % 2) == 0){
if (a[i] < min)
min = a[i]; 
} 
else{min = min;}
i++;
}
return min;
}

int minimo_impares(int a[], int tam){
int i, min;
min = INT_MAX;
i = 0;
while(i < tam){
if ((a[i] % 2) != 0){
if (a[i] < min)
min = a[i]; 
else{min = min;}
}
i++; 
}
return min;
}

int main(void){
int size;
printf("Introduzca el tamaño del array:");
scanf("%d", &size);
int a[size];
pedirArray(a, size);
printf("Minimo elemento Par del array: %d\n", minimo_pares(a, size));
printf("Minimo elemento Impar del array: %d\n", minimo_impares(a, size));

}
