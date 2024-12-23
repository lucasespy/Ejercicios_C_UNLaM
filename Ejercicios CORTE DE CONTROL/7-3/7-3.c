#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char sector[16];
    int duracion;
    int tipollamada;
}sLlamadas;

int main()
{
    sLlamadas llamadas;
    FILE *pfllamada;
    int cant;

    pfllamada = fopen("LLAMADAS.dat", "rb");
    if(pfllamada==NULL)
    {
        printf("\nERROR en la apertura del archivo.\n");
        exit(1);
    }
    fread(&llamadas, sizeof(sLlamadas), 1, pfllamada);
    while(!feof(pfllamada))
    {
        cant=0;

    }

    return 0;
}
