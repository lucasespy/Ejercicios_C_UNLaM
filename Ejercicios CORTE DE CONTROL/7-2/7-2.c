#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ///estructura de un archivo con las ventas del mes de cada una de las sucursales de la empresa
{
    char sucursal[16];
    int codproducto, cantidad;
}sVentas;

typedef struct ///estructura de un archivo con productos que vende la empresa y el estado del stock al mes pasado
{
    int codproducto, stock, puntodepedido, cantidadparapedido;
    char descripcion[21];
    float precio;
}sProductos;

int main()
{
    sVentas ventas;
    sProductos product;
    FILE *pvent, *pprod, *ppedidos;

    char sucAnterior[16];
    float importeventa, total, importexsuc;
    int contadorventas=0;


    pvent = fopen("ventas.dat", "rb");
    pprod = fopen("productos.dat", "r+b");
    ppedidos = fopen("pedidos.dat", "wb");
    if(pvent==NULL || pprod==NULL || ppedidos==NULL)
    {
        printf("\nERROR en la apertura de los archivos.\n");
        exit(1);
    }
    fread(&ventas, sizeof(sVentas), 1, pvent);
    while(!feof(pvent))
    {
        importexsuc=0;
        contadorventas = 0;
        strcpy(sucAnterior, ventas.sucursal);
        while(!feof(pvent) && !(strcmpi(sucAnterior, ventas.sucursal)))
        {
            fseek(pprod, 0, SEEK_SET);
            fread(&product, sizeof(sProductos), 1, pprod);
            while(!feof(pprod))
            {
                if(product.codproducto==ventas.codproducto)
                    importexsuc += (product.precio*ventas.cantidad)*1.0;
                fread(&product, sizeof(sProductos), 1, pprod);
            }
            printf("Sucursal: %s\nImporte: %.2f\n---------------------------------\n", sucAnterior, importexsuc);
            fread(&ventas, sizeof(sVentas), 1, pvent);
        }
    }
    fclose(pprod);
    fclose(pvent);
    fclose(ppedidos);

    return 0;
}
