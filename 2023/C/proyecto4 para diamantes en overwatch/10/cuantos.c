#include <stdio.h> 
void pedirArray(int a[], int n_max){
int i;
i = 0;
while (i<n_max){
printf("En la posicion %d introduzca el valor del array: \n", i);
scanf("%d", &a[i]);
i++;
}}

struct comp_t {
int menores;
int iguales;
int mayores;
};

struct comp_t cuantos(int a[], int tam, int elem){
int i;
i = 0;
struct comp_t n;
n.menores = 0;
n.mayores = 0;
n.iguales = 0;
while (i < tam){
if (a[i]< elem){n.menores++;}
else if (a[i] > elem){n.mayores++;}
else {n.iguales++;}
i++;
}
return n;
};

void print_cuantos(struct comp_t n){
printf("Numero de elementos mayores: %d\nNumero de elementos menores: %d\nNumero de elementos iguales: %d\n", n.mayores, n.menores, n.iguales);
}

int main(void){
int size, n;
printf("Introduzca el tamaño del array:");
scanf("%d", &size);
int a[size];
pedirArray(a, size);
printf("Introduzca un entero:\n");
scanf("%d",&n);
print_cuantos(cuantos(a, size, n));
}