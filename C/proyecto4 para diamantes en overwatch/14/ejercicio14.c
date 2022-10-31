#include <stdio.h> 
#include <limits.h>
typedef struct _persona {
char *nombre;
int edad;
float altura;
float peso;
} persona_t;

float peso_promedio(persona_t a[], unsigned int longitud){
int p;
unsigned int i;
float rst;
i = 0;
p = 0; 
rst = 0;
while (i < longitud){
rst = rst + a[i].peso;
i++;
p++; 
}
rst = rst / p;
return rst;
}
persona_t persona_de_mayor_edad(persona_t a[], unsigned int longitud){
int rst;
unsigned int i;
persona_t p;
i = 0;
p = a[i];
rst = INT_MIN;
while (i < longitud){
if (a[i].edad > rst){
rst = a[i].edad;
p = a[i];
i++;
}
else{i++;}
}
return p;
}
persona_t persona_de_menor_altura(persona_t a[], unsigned int longitud){
unsigned int i;
float rst;
persona_t p;
i = 0;
p = a[i];
rst = INT_MAX;
while (i < longitud){
if (a[i].altura < rst){
rst = a[i].altura;
p = a[i];
i++;
}
else{i++;}
}
return p;
}


int main(void) {
persona_t p1 = {"Paola", 21, 1.85, 75};
persona_t p2 = {"Luis", 54, 1.75, 69};
persona_t p3 = {"Julio", 40, 1.70, 80};
unsigned int longitud = 3;
persona_t a[] = {p1, p2, p3};
printf("El peso promedio es %f\n", peso_promedio(a, longitud));
persona_t p = persona_de_mayor_edad(a, longitud);
printf("El nombre de la persona con mayor edad es %s\n", p.nombre);
p = persona_de_menor_altura(a, longitud);
printf("El nombre de la persona con menor altura es %s\n", p.nombre);
return 0;
}