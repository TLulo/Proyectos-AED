#include <stdio.h>
#include <stdbool.h>

typedef char clave_t;
typedef int valor_t;

struct asoc{
    clave_t clave;
    valor_t valor;
};


bool asoc_existe(struct asoc a[],int tam,clave_t c){
    int i;
    i= 0;
    while (i<tam){
        if (a[i].clave == c){
            return 1;
        }else{
            i = i+1;
        }
    }
    return 0;
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void pedir_areglo_struc(struct asoc a[],int tam){
    int i;
    i=0;
    while (i<tam){
        printf("Ingrese la clave del arreglo en la posicion %d: ",i);
        scanf(" %c",&a[i].clave);
        printf("Ingrese el valor del arreglo en la posicion %d: ",i);
        scanf("%d",&a[i].valor);
        i = i+1;
    }
};

int main(void){
    int res,n;
    clave_t c;
    n = pedirEntero('n');
    printf("Ingrese la clave a corroborar: ");
    scanf(" %c",&c);
    struct asoc a[n];
    pedir_areglo_struc(a,n);
    res = asoc_existe(a,n,c);
    if (res){
        printf("La clave existe en el arreglo");
    }else{
        printf("La clave NO existe en el arreglo");
    }
}