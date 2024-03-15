#include <stdio.h>

int pedirEntero(void){
    int a;
    printf("Ingrese un entero:");
    scanf("%d",&a);
    return a;
}

int es_primo(int x){
	int res,i;
    i=2;
    res = 1;
	while (i < x && res)
    {
        res = res && ((x % i) != 0);
        i = i + 1;
    }
    return res;
}

int nesimo_primo(int N){
    int num,contador;
    contador=2;
    num=3;
    if(N==1){
        return 2;
    }
    while(contador<N){
        num = num + 2;
        if(es_primo(num)){
            contador = contador + 1;
        }
    }
    return num;
}

int main(void) {
    int n,res;
    n = pedirEntero();
    while(n<0){
            printf("Error, ingrese un entero positivo\n");
            n = pedirEntero();
        }
    res = nesimo_primo(n);
    printf("El primo n°%d es:%d",n,res);
}