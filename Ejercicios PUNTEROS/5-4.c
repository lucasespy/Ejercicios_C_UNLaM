#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void CargarVector(int [], int);
void MostrarVector(int [], int);
void CargarVector2(int *, int);
void MostrarVector2(int *, int);
int main()
{
    int vec[5]={0};

    CargarVector(vec,5);
    MostrarVector(vec,5);

    return 0;
}
void CargarVector(int vec[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("Ingrese un valor para la posicion %d: ", i+1);
        scanf("%d", vec+i);
    }
}
void MostrarVector(int vec[], int cant)
{
    int i;
    printf("--------------------\n");
    for(i=0; i<cant; i++)
        printf("Posicion %d: %d\n", i+1, *(vec+i));
}

/*==================================================OTRA FORMA==================================================*/

void CargarVector2(int *vec, int cant)
{
    int *puntero;
    for(puntero=vec; puntero<vec+cant; puntero++)
    {
        printf("Ingrese un valor para la posicion %d: ", puntero-vec+1);
        scanf("%d", puntero);
    }
}
void MostrarVector2(int *vec, int cant)
{
    int *puntero;
    printf("--------------------\n");
    for(puntero=vec; puntero<vec+cant; puntero++)
        printf("Posicion %d: %d\n", puntero-vec+1, *puntero);
}
