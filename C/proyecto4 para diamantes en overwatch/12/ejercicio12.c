#include <stdio.h>
#include <stdbool.h>

typedef char clave_t;
typedef int valor_t;

struct asoc {
clave_t clave;
valor_t valor;
};

bool asoc_existe(struct asoc a[], int tam, clave_t c){
int i;
i = 0; 
while (i < tam){
if((i+1 == tam) && a[i].clave != c){
printf("No existe la clave ingresada.");
i = i + tam;
}
else if (a[i].clave == c){
i = i + tam;
printf("La clave ingresada existe."); return 1;}

else {
i++;
}
}
return 0;
}

void pedirArray_struct(struct asoc a[], int n_max){
int i;
i = 0;
while (i<n_max){
printf("En la posicion %d introduzca la clave: \n", i);
scanf(" %c", &a[i].clave);
printf("En la posicion %d introduzca el valor: \n", i);
scanf("%d", &a[i].valor);
i++;
}}

int main(void){
int size;
clave_t c;
printf("Introduzca el tamaño del array:");
scanf("%d", &size);
printf("Introduzca una clave:\n");
scanf(" %c", &c);

struct asoc a[size];

pedirArray_struct(a, size);
asoc_existe(a, size, c);
}