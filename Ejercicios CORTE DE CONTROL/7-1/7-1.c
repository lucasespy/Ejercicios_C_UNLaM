#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int numcanal;
    char programa[36];
    float rating;
}sCanales;
typedef struct
{
    int numcanal;
    float promedio;
}sPromedio;

void VisualizarArchivo(sCanales);

int main()
{
    sCanales canal;
    sPromedio promedio;
    FILE *can, *prom;
    int contprogramas=0, cAnterior, masVisto, bandera1, bandera2;
    float mayorRating, sumaratingxcanal;


    VisualizarArchivo(canal);
    can = fopen("RATING.dat", "rb");
    prom = fopen("PROMEDIO.dat", "wb");
    if(can==NULL || prom==NULL)
    {
        printf("\nERROR en la apertura de los archivo\n");
        exit(1);
    }
    fread(&canal, sizeof(sCanales), 1,can);
    bandera1=0;
    bandera2=0;
    while(!feof(can))
    {
        cAnterior = canal.numcanal;
        contprogramas = 0;
        sumaratingxcanal = 0;
        while(!feof(can) && cAnterior==canal.numcanal)
        {
            contprogramas++;
            sumaratingxcanal+= canal.rating;
            fread(&canal, sizeof(sCanales), 1, can);
        }
        if(bandera1==0)
        {
            bandera1=1;
            printf("Canales con menos de 15 puntos de rating: \n");
        }
        if(sumaratingxcanal<15) ///Punto a)
            printf("- Canal %d con %.2f puntos de rating\n", cAnterior, sumaratingxcanal);

        if(bandera2==0 || mayorRating<sumaratingxcanal) ///Punto b)
        {
            bandera2=1;
            mayorRating = sumaratingxcanal;
            masVisto = cAnterior;
        }
        if(contprogramas!=0)
        {
            promedio.promedio = sumaratingxcanal/contprogramas;
            promedio.numcanal = cAnterior;
            fwrite(&promedio, sizeof(sPromedio), 1, prom);
        }
    }
    printf("\nEl canal mas visto es el canal %d con %.2f puntos de rating.\n", masVisto, mayorRating);
    fclose(can);
    fclose(prom);
    return 0;
}

void VisualizarArchivo(sCanales canales)
{
    FILE *pcanal;

    pcanal = fopen("RATING.dat", "rb");
    if(pcanal==NULL)
    {
        printf("\nERROR en la apertura del archivo\n");
        exit(1);
    }
    fread(&canales, sizeof(sCanales),1,pcanal);
    printf("%-15s%-25s%-15s\n\n", "CANAL", "PROGRAMA", "RATING");
    while(!feof(pcanal))
    {
        printf("%-15d%-25s%.2f\n",canales.numcanal, canales.programa, canales.rating);
        fread(&canales, sizeof(sCanales),1,pcanal);
    }
    fclose(pcanal);
}
