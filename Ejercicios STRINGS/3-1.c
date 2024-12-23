///Considerar que no se cuente como palabra si se ingresa un espacio solo, o solo espacios
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ContarPalabras(char[501]);
int main()
{
    char frase[501];
    int cont = 0;

    printf("Ingrese una frase de hasta 500 caracteres: ");
    fgets(frase, 501, stdin);

    if(frase[strlen(frase)-1] == '\n')
        frase[strlen(frase)-1] = '\0';

    printf("Cantidad de caracteres: %d\n", strlen(frase));

    ContarPalabras(frase);
    return 0;
}
void ContarPalabras(char frase[501])
{
    int i=0, cont=0;
    while(frase[i] != '\0')
    {
        if(frase[i] == ' ' && frase[i] != '-' && frase[i] != '.')
            if()
            cont++;
        i++;
    }
    printf("La cantidad de palabras es de %d.",cont);
}
