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
    sProducto prod;
    FILE *orig, *cop;
    int codaborrar;
    orig = fopen("PRODUCTOS.dat", "rb");
    cop = fopen("PRODUCTOS.temp", "wb");
    if(orig==NULL || cop==NULL)
    {
        printf("\nERROR en la apertura de archivos.\n");
        exit(1);
    }

    printf("===========LISTA DE PRODUCTOS===========\n\n");
    MostrarProductos(prod);

    printf("\nIngrese el codigo del producto a eliminar: ");
    scanf("%d", &codaborrar);
    //prod = Buscar(codaborrar, orig);
    fread(&prod, sizeof(sProducto), 1, orig);
    while(!feof(orig) && prod.codigo!=-1)
    {
        if(prod.codigo!=codaborrar)
            fwrite(&prod, sizeof(sProducto),1 , cop);
        fread(&prod, sizeof(sProducto), 1, orig);
    }
    fclose(orig);
    fclose(cop);
    remove("PRODUCTOS.dat");
    rename("PRODUCTOS.temp", "PRODUCTOS.dat");

    printf("\n\n===========LISTA DE PRODUCTOS ACTUALIZADOS===========\n\n");
    MostrarProductos(prod);
    return 0;
}
void MostrarProductos(sProducto prod)
{
    FILE *pf;
    pf = fopen("PRODUCTOS.dat", "rb");
    if(pf==NULL)
    {
        printf("\nERROR en la apertura del archivo.\n");
        exit(1);
    }
    printf("%-20s%-35s%s\n\n","CODIGO", "DESCRIPCION", "PRECIO");
    fread(&prod, sizeof(sProducto),1, pf);
    while(!feof(pf))
    {
        printf("%-10d\t%-35s\t$%.2f\n", prod.codigo, prod.descripcion, prod.precio);
        fread(&prod, sizeof(sProducto), 1, pf);
    }
    fclose(pf);
}
