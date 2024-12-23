#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int num=10, *punt;

    punt = &num;

    printf("a) Direccion de la variable: %p\n", &num);
    printf("b) Direccion del puntero: %p\n", &punt);
    printf("c) Contenido de la variable: %d\n", num);
    printf("d) Contenido de la variable accediendo mediante el puntero: %d\n", *punt);
    printf("e) Contenido del puntero: %p\n", punt);

    return 0;
}
