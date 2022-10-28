#include <stdio.h>

struct comp_t{
    int menores;
    int iguales;
    int mayores;
};

struct comp_t cuantos(int a[],int tam,int elem){
    int i;
    i = 0;
    struct comp_t res;
    res.menores = 0;
    res.iguales = 0;
    res.mayores = 0;
    while (i<tam){
        if (a[i]<elem){
            res.menores = res.menores +1;
        }else if(a[i]==elem){
            res.iguales = res.iguales +1;
        }else{
            res.mayores = res.mayores +1;
        }
        i = i+1;
    }
    return res;
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void pedirArreglo(int a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el valor del arreglo en la posicion %d: ",i+1);
        scanf("%d",&a[i]);
        i=i+1;
    }
}

void imprime_res(struct comp_t p){
    printf("La cantidad de elementos.\nMenores: %d\nIguales: %d\nMayores: %d\n",p.menores,p.iguales,p.mayores);
}

int main(void){
    int n;
    int x;
    printf("Ingrese x como elemento a comparar y n como posiciones del arreglo\n");
    x = pedirEntero('x');
    n = pedirEntero('n');
    int a[n];
    pedirArreglo(a,n);
    imprime_res(cuantos(a,n,x));
}


//-------------------------------miscambios------------estoy de recontra mal humor--------------

#include <stdio.h>
#include<stdbool.h>
#include<limits.h>

int min;

int pedirLargo(void){
    int i;
    printf("Introduzca el largo del arreglo:\n");
    scanf("%d",&i);
    return i;
}

int pedirEntero(void){
    int i;
    printf("Introduzca un numero:\n");
    scanf("%d",&i);
    return i;
}

void pedirArreglo(int a[], int n_max) {
    int i;
    i = 0;
    while (i < n_max) {
        printf("Ingrese el valor del arreglo en la posicion %d:", i);
        scanf("%d",&a[i]);
        i=i+1;
    }
}

void imprimeArreglo(int a[], int n_max){
    int i;
    i=0;
    while(i < n_max) {
        printf("El numero %d esta en la posicion %d;\n", a[i],i);
        i = i+1;
    }
}

struct comp_t {
int menores;
int iguales;
int mayores;
};

struct comp_t cuantos(int a[], int tam, int elem) {
    int res1,res2,res3,i,j;
    struct comp_t res;
    i=0;
    res.menores = 0;
    res.iguales = 0;
    res.mayores = 0;
    while(i < tam){
        if (a[i] < elem) {
            res.menores = res.menores + 1;
        } else if (a[i] > elem) {
            res.mayores = res.mayores + 1;
        } else {
            res.iguales = res.iguales + 1;
        } 
        i = i + 1;
    }
    printf("Mayores: %d\n", res.mayores);
    printf("Menores: %d\n", res.menores);
    printf("Iguales: %d\n", res.iguales);
}


int main (void) {
    int n,x;
    n = pedirLargo();
    printf("Introduzca el valor para obtener cuantos valores minimos, maximos e iguales hay en el arreglo:\n");
    scanf("%d",&x);
    int a[n];
    pedirArreglo(a,n);
    imprimeArreglo(a,n);
    cuantos(a,n,x);
}
