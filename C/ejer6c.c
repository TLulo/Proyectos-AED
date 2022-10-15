#include <stdio.h>

int x,y,z,m,temp;

int pedirEntero(void){
    printf("Ingrese el parametro: ");
    scanf("%d",&temp);
    return temp;
}

void imprimeEntero(int x){
    printf("El parametro es: %d\n",x);
}
int ejer4(int x, int y, int z){
    if (x<y){
        m = x;
    }
    else{
        m = y;
    }
    if (m<z){
        m = m;
    }
    else{
        m = z;
    }
    return m;
}

int main(void){

    x = pedirEntero();
    y = pedirEntero();
    z = pedirEntero();

    m = ejer4(x,y,z);
    
    imprimeEntero(m);
}
