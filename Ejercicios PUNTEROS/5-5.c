#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void CargarVector(int *, int);
void MostrarVector(int *, int);
int *Buscar(int*, int, int);
int main()
{
    int vec[10]={0}, num, *pos;

    CargarVector(vec,10);
    MostrarVector(vec,10);

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &num);
    while(num>0)
    {
        pos = Buscar(vec, num, 10);
        if(pos!=NULL)
            printf("Su posicion en el vector es: %d\n", *pos+1);
        else
            printf("No se encuentra en el vector.\n");
        printf("Ingrese el numero a buscar: ");
        scanf("%d", &num);
    }

    return 0;
}
void CargarVector(int *vec, int cant)
{
    int *puntero;
    for(puntero=vec; puntero<vec+cant; puntero++)
    {
        printf("Ingrese un valor para la posicion %d: ", puntero-vec+1);
        scanf("%d", puntero);
    }
}
void MostrarVector(int *vec, int cant)
{
    int *puntero;
    printf("--------------------\n");
    for(puntero=vec; puntero<vec+cant; puntero++)
        printf("Posicion %d: %d\n", puntero-vec+1, *puntero);
}
int *Buscar(int *vec, int buscado, int cant)
{
    int i=0, *pos=NULL, *puntero;
    puntero = vec;
    while(puntero<vec+cant && pos==NULL)
    {
        if(buscado == puntero-vec)
            pos = puntero;
        else
            puntero++;
    }
    return pos;
}
