#include <stdio.h>

int x,y,z,m,rese,bucle;

int funb1(int x, int y, int m,int z){
    if (x<y){
        m = x;
    }else{
        m = y;
    }
    if (m<z){
        m=m;
    }
    else{
        m = z;
    }
    return m;
}

int fune (int a,int b){
    if (a >= b){
        return 0;
    }
    if (a == b){
        return 2;
    }
    
    else{
        return 2;
    }
}

int main(void){

    printf("Ingrese el valor de x: ");
    scanf("%d",&x);

    printf("Ingrese el valor de y: ");
    scanf("%d",&y);

    printf("Ingrese el valor de z: ");
    scanf("%d",&z);

    printf("Ingrese el valor de m: ");
    scanf("%d",&m);
    
    printf("Bienvenido al menu\nIngrese 1 si desea usar la funcion 1 del ejercicio 4.\nIngrese 2 si desea usar la funcion 2 del ejercicio 4.\nIngrese 0 para cerrar\nIngrese el valor elejido: ");
    scanf("%d",&bucle);
    if (bucle == 1){
        rese = fune(x,y);
        printf("El resultado de la funcion 1 es: %d\n",rese);
    }
    else if (bucle == 2){
        m = funb1(x,y,m,z);


        printf("el estado final de m es: %d\n",m);
    }
    else if (bucle == 0){
        printf("finalizando programa.\n");
    }
    else{
        printf("Inserte un valor valido.\n");
    }        
}
/*
La funcion devuelve el menor entre x,y,z y lo almacena en m
*/
int main(void){
    int x,y;
    if (x >= y){
        x = 0;
    }
    else{
        x = 2;
    }
    printf("el valro finaol es : %d",x);
