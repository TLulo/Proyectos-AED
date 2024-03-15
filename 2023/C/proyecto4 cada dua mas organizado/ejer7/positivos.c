#include <stdio.h>
#include <stdbool.h>

int n,res;

void imprimeBooleano(bool x){
    if (x){
        printf("El resultado de la funcion es True\n");
    }
    else{
        printf("El resultado de la funcion es False\n");
    }
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

bool existe_positivo(int a[],int tam){
    int i;
    i = 0;
    while (i < tam){
        if (a[i]>=0){
            return 1;
        }
        else{
            i=i+1;
        }
    }    
    return 0;
}

bool todos_positivos(int a[],int tam){
    int i;
    i = 0;
    while (i<tam){
        if (a[i]<0){
            return 0;
        }else{
            i = i+1;
        }
    }
    return 1;
}

void menu(int a[],int tam){
    int i;
    i = 1;
    while (i !=0){
        printf("**********************************************************************************\n");
        printf("Ingrese 1 si desea utilizar la funcion existe positivo.\nIngrese 2 si desea utilizar la funcion todos positivos.\nIngrese 0 si desea cerrar el menu\n");
        printf("**********************************************************************************\n");
        i = pedirEntero('i');
        if (i == 1){
            res = existe_positivo(a,tam);
            imprimeBooleano(res);
        }else if( i == 2){
            res = todos_positivos(a,tam);
            imprimeBooleano(res);
        }else if(i == 0){
            printf("Termina el programa\n");
        }else{
            printf("Ingrese un valor valido\n");
        }
    }
}

int main(void){
    n = pedirEntero('n');
    int a[n];
    pedirArreglo(a,n);
    menu(a,n);
}


//-------------------------------------FLACO TENES UNA ADICCION A LOS MENUS DEJA DE METER MENU HASTA EN LA SOPA------------------------------

#include <stdio.h>
#include<stdbool.h>

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

bool existe_positivo(int a[], int tam) {
    int i;
    i = 0;
    while (i < tam) {
        if (a[i] >= 0) {
            return 1;
        } else{
            i=i+1;
        }
    }
    return 0;
}

bool todos_positivos(int a[], int tam) {
    int i;
    i = 0;
    while (i < tam) {
        if (a[i] > 0) {
            i = i + 1;
        } else{
            return 0;
        }
    }
}

int main (void) {
    int n,sum,bool1,bool2,menu;
    n = pedirLargo();
    int a[n];
    pedirArreglo(a,n);
    imprimeArreglo(a,n);
    bool1 = existe_positivo(a,n);
    bool2 = todos_positivos(a,n);
    printf("%s", bool1? "True":"False\n");
    printf("%s", bool2? "True":"False\n");
    menu = 1;
    while (menu != 0) {
        printf("Ingrese 1 si desea ver si todos los elementos del arreglo que introdujo son positivos\nIngrese 2 si desea ver si algun elemento del arreglo es positivo\nIngrese 0 si desea cerrar el menu\n");
        menu = pedirEntero();
    if (menu == 1) {
        printf("El arreglo contiene todos numeros positivos (True si es asi, False si no es asi): %s\n", bool2?"True":"False");
    }else if (menu == 2) {
        printf("El arreglo contiene almenos un elemento positivo (True si es asi, False si no es asi): %s\n", bool1?"True":"False");
    }else if (menu == 0) {
        printf("El programa finalizo\n");
    } else {
        printf("Ingrese un valor valido\n");
    } 
}
}
