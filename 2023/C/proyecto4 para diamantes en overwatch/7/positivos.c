#include <stdio.h>
#include <stdbool.h>

void pedirArray(int a[], int n_max){
int i;
i = 0;
while (i<n_max){
printf("En la posicion %d introduzca el valor del array: \n", i);
scanf("%d", &a[i]);
i++;
}}

bool  existe_positivo(int a[], int tam){
int i;
bool rst;
i = 0;
rst = false;
while(i< tam){
rst = (a[i] > 0) || rst; 
i++;
}
if (rst == true){printf("Si existe un positivo.\n");}
else{printf("No existe un positivo.\n");}
return rst;
}

bool todos_positivos(int a[], int tam){
int i;
bool rst;
i = 0;
rst = true;
while(i< tam){
rst = (a[i] >= 0) && rst; 
i++;
}
if (rst == true){printf("Todos son positivos.\n");}
else{printf("No todos son positivos.\n");}
return rst;
}

int main(void){
int size, x;
printf("Introduzca el tamaño del array:\n");
scanf("%d", &size);
int a[size];
pedirArray(a, size);
x = 5;
while ((x /= 1) && (x /= 2)){
printf("Limite sus respuestas a 1 o 2\n");
printf("Para ver si un elemento del array es positivo escriba 1.\nPara ver si todos los elementos del array son positivos escriba 2.\n");
scanf("%d", &x);
if (x == 1){
existe_positivo(a, size);
return 0;}
else if(x == 2){
todos_positivos(a, size);
return 0;}
}
}
