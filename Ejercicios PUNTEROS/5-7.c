#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int codigo;
    char descripcion[31];
    float precio;
}sProductos;
int main()
{
    sProductos productos, *p, *q;
    p = &productos;
    q = &productos;

    printf("Ingrese el codigo del producto: ");
    scanf("%d", &(*p).codigo);
    printf("Ingrese la descripcion del producto: ");
    fflush(stdin);
    gets((*p).descripcion);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &(*p).precio);

    printf("Codigo: %d\n", (*p).codigo);
    printf("Descripcion: %s\n", (*p).descripcion);
    printf("Precio: %.2f\n", (*p).precio);

    /*=======================OTRA FORMA=======================*/

    printf("Ingrese el codigo del producto: ");
    scanf("%d", &q->codigo);
    printf("Ingrese la descripcion del producto: ");
    fflush(stdin);
    gets(q->descripcion);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &q->precio);

    printf("Codigo: %d\n", q->codigo);
    printf("Descripcion: %s\n", q->descripcion);
    printf("Precio: %.2f\n", q->precio);

    return 0;
}
