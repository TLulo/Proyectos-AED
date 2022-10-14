#include <stdio.h>
#include <stdbool.h>

bool res;
int i,menu,x,y;

void funh(int i)
{
    while (i!=0){
        i = i-1;
    }
    printf("El valor final de i es: %d\n",i);
}

void funi(int i){
    while (i!=0){
        i = 0;
    }
    printf("El valor final de i es: %d\n",i);
}

void funb1(int x, int y){
    i= 0;
    while (x >= y){
        x = x - y;
        i = i + 1;
    }
    printf("El estado final de x es: %d\n",x);
    printf("El estado final de y es: %d\n",y);
    printf("El numero final de iteraciones es: %d\n",i);
}

void funb2(int x){
    i = 2;
    res = true;
    while(i < x && res){
        res = res && (x % i) != 0;
        i = i+1;
    }
    printf("El estado final de x es: %d\n",x);
    printf("El resto es: %d\n",res);
    printf("El numero final de iteraciones es: %d\n",i);
}


int main(void)
{
    printf("Introduzca el valor de i: ");
    scanf("%d",&i);
    printf("Introduzca el valor de x: ");
    scanf("%d",&x);
    printf("Introduzca el valor de y: ");
    scanf("%d",&y);


    printf("Bienvenido al menu\n*Ingrese 1 si desea usar la funcion 'h'.*\n*Ingrese 2 si desea usar la funcion 'i'.*\n*Ingrese 3 si desea usar la funcion '1' del ejercicio 5b.*\n*Ingrese 4 si desea usar la funcion '2' del ejercicio 5b.*\n*Ingrese otro valor para cerrar*\nIngrese el valor elejido: ");
    scanf("%d",&menu);
    if (menu == 1){
        funh(i);
    }
    else if (menu == 2){
        funi(i);
    }
    else if (menu == 3){
        funb1(x,y);
    }
    else if (menu == 4){
        funb2(x);
    }
    else{
        printf("finalizando programa.\n");
    }  
}
/*
la funcion b.1) devuelve la divison de x e y de forma a = b*q + r
    donde:
        a = estado inicial de x
        b = y
        q = estado final de i/numero de iteraciones
        r = estado final de x
*/