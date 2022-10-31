#include <stdio.h>
#include <limits.h>

typedef struct _persona{
    char *nombre;
    int edad;
    float altura;
    float peso;
}persona_t;

float peso_promedio(persona_t arr[],unsigned int longitud){
    unsigned int i = 0;
    float peso,prom;
    peso = 0;
    while (i<longitud){
        peso = peso + arr[i].peso;
        i = i +1;
    }
    prom = peso / longitud;
    return prom;
}

persona_t persona_de_mayor_edad(persona_t arr[], unsigned int longitud){
    int i_max_edad,edad_max;
    unsigned int i = 0;
    edad_max = INT_MIN;
    while (i < longitud){
        if (arr[i].edad > edad_max){
            edad_max = arr[i].edad;
            i_max_edad = i;
            i = i+1;
        }else{
            i = i+1;
        }
    }
    return arr[i_max_edad];
}

persona_t persona_de_menor_altura(persona_t arr[], unsigned int longitud){
    int i_men_alt;
    float men_alt;
    unsigned int i = 0;
    men_alt = INT_MAX;
    while (i<longitud){
        if (arr[i].altura < men_alt){
            men_alt = arr[i].altura;
            i_men_alt = i;
            i = i+1;
        }else{
            i = i+1;
        }
    }
    return arr[i_men_alt];
}

int main(void){
    persona_t p1 = {"Paola", 21, 1.85, 75};
    persona_t p2 = {"Luis", 54, 1.75, 69};
    persona_t p3 = {"Julio", 40, 1.70, 80};
    unsigned int longitud = 3;
    persona_t arr[] ={p1,p2,p3};
    printf("El peso promedio es %f\n",peso_promedio(arr,longitud));
    persona_t p = persona_de_mayor_edad(arr,longitud);
    printf("El nombre de la persona con mayor edad es %s\n",p.nombre);
    p = persona_de_menor_altura(arr,longitud);
    printf("El nombre de la persona con menor altura es %s\n",p.nombre);
    return 0;
}