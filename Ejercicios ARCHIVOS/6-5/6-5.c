#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];
}sProducto;
void MostrarProductos(sProducto);
void toExcel(sProducto);
sProducto Buscar(int, FILE *);
int main()
{
    sProducto prod;
    FILE *pf;
    int cod;
    float precio;
    char exp;

    pf = fopen("PRODUCTOS.dat", "r+b");
    if(pf==NULL)
    {
        printf("\nERROR en la apertura del archivo.\n");
        exit(1);
    }
    printf("===========ACTUALIZACION DE PRECIOS===========\n\n");
    MostrarProductos(prod);
    printf("Ingrese el codigo del producto (de la lista) que desea modificar (0 para finalizar): ");
    scanf("%d", &cod);
    while(cod!=0)
    {
        prod = Buscar(cod, pf);
        if(prod.codigo!=-1)
        {
            printf("Ingrese el nuevo precio del producto %s: $", prod.descripcion);
            scanf("%f", &precio);
            prod.precio = precio;
            fseek(pf, sizeof(sProducto)*-1, SEEK_CUR);
            fwrite(&prod, sizeof(sProducto), 1, pf);
        }
        else
            printf("\nERROR, el codigo no se encuentra en el archivo.\n\n");

        printf("Ingrese el codigo del producto (de la lista) que desea modificar (0 para finalizar): ");
        scanf("%d", &cod);
    }
    fclose(pf);

    printf("\n\n===========PRECIOS ACTUALIZADOS===========\n\n");
    MostrarProductos(prod);

    printf("Desea exportar la lista de productos a planilla de archivos? oprima 'S' o 'N' para no: ");
    fflush(stdin);
    scanf("%c", &exp);
    if(toupper(exp) == 'S')
    {
        toExcel(prod);
        printf("\n**Archivos exportados exitosamente**\n");
    }
    else
        printf("\nNo se exportaron archivos.\n");

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
    printf("=====PRECIOS=====\n%-20s%-35s%s\n\n","CODIGO", "DESCRIPCION", "PRECIO");
    fread(&prod, sizeof(sProducto),1, pf);
    while(!feof(pf))
    {
        printf("%-10d\t%-35s\t$%.2f\n", prod.codigo, prod.descripcion, prod.precio);
        fread(&prod, sizeof(sProducto), 1, pf);
    }
    fclose(pf);
}
void toExcel(sProducto prod)
{
    FILE *pf, *excelfile;
    pf = fopen("PRODUCTOS.dat", "rb");
    excelfile = fopen("PRODUCTOS.csv", "wt");
    if(pf==NULL || excelfile==NULL)
    {
        printf("\nERROR en la apertura del archivo.\n");
        exit(1);
    }
    fprintf(excelfile, "CODIGO;DESCRIPCION;PRECIO\n");
    fread(&prod, sizeof(sProducto),1, pf);
    while(!feof(pf))
    {
        fprintf(excelfile, "%d;%s;%.2f\n", prod.codigo, prod.descripcion, prod.precio);
        fread(&prod, sizeof(sProducto), 1, pf);
    }
    fclose(pf);
    fclose(excelfile);
}
sProducto Buscar(int buscado, FILE *pf)
{
    sProducto regProd;
    int encontrado=0; ///Bandera
    rewind(pf); ///Vuelve al archivo desde el principio
    fread(&regProd, sizeof(sProducto), 1, pf);
    while(!feof(pf) && !encontrado)
    {
        if(regProd.codigo == buscado)
            encontrado=1;
        else
            fread(&regProd, sizeof(sProducto), 1, pf);
    }
    if(!encontrado)
        regProd.codigo = -1;

    return regProd;
}
