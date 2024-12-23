#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];
}sProducto;
void MostrarProductos(sProducto);
int main()
{
    sProducto producto;
    FILE *arch;
    float incremento;
    arch = fopen("PRECIOS.dat", "r+b");
    if(arch == NULL)
    {
        printf("\nERROR en la apertura del archivo.\n");
        exit(1);
    }

    MostrarProductos(producto);
    printf("\nIngrese el porcentaje de incremento: %");
    scanf("%f", &incremento);

    fread(&producto, sizeof(sProducto),1 , arch);
    while(!feof(arch))
    {
        producto.precio += (producto.precio*incremento)/100;
        fseek(arch, sizeof(sProducto)*-1, SEEK_CUR);
        fwrite(&producto, sizeof(sProducto),1 ,arch);
        fseek(arch, 0, SEEK_CUR);
        fread(&producto, sizeof(sProducto), 1, arch);
    }
    fclose(arch);
    MostrarProductos(producto);
    return 0;
}
void MostrarProductos(sProducto prod)
{
    FILE *pf;
    pf = fopen("PRECIOS.dat", "rb");
    if(pf==NULL)
    {
        printf("\nERROR en la apertura del archivo.\n");
        exit(1);
    }
    printf("=====PRECIOS=====\n%-20s%-35s%s\n\n","CODIGO", "DESCRIPCION", "PRECIO");
    fread(&prod, sizeof(sProducto),1, pf);
    while(!feof(pf))
    {
        printf("%-10d\t%-35s\t$%.2f\n", prod.codigo, prod.descripcion, prod.precio);
        fread(&prod, sizeof(sProducto), 1, pf);
    }
    fclose(pf);
}
