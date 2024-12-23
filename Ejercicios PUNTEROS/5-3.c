#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Ingresar(int *, float *, char *);
int main()
{
    int entero;
    float flotante;
    char caracter;

    Ingresar(&entero, &flotante, &caracter);

    printf("\nEntero: %d\nFlotante: %.2f\nCaracter: %c\n", entero, flotante, caracter);

    return 0;
}
void Ingresar(int *entero, float *flotante, char *caracter)
{
    printf("Ingrese Entero: ");
    scanf("%d", entero);
    printf("Ingrese Flotante: ");
    scanf("%f", flotante);
    printf("Ingrese Caracter: ");
    fflush(stdin);
    scanf("%c", caracter);
}
