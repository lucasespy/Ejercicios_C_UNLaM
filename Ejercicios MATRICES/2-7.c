#include<stdio.h>
#include<stdlib.h>
#define TAM 2
                        ///     **** FALTA TERMINAR EL PUNTO DE MENOR RECAUDACION POR TRIMESTRE  ****
int Buscar(int[], int, int);
void CargaCodigosYPrecios(int[], float[], int);
void MostrarListadoProductos(int[], float[], int);
int IngresaCodigoProducto(int[], int);
int IngresarFecha(char[], int, int);
void MostrarVentas(int[], int[][12], int, int);
void MayorRecaudacion(float[], int[], int);
int main()
{
    int CodProductos[TAM], cod, poscod, dia, mes, cant, Ventas[TAM][12]={{0}};
    float Precios[TAM], Recaudacion[TAM];

    CargaCodigosYPrecios(CodProductos, Precios, TAM);
    MostrarListadoProductos(CodProductos, Precios, TAM);
    printf("\n---CARGA DE VENTAS\n\n");
    cod = IngresaCodigoProducto(CodProductos,TAM);
    while(cod != 0)
    {
        poscod = Buscar(CodProductos, cod, TAM);
        mes = IngresarFecha("MES", 1, 12);
        dia = IngresarFecha("DIA", 1, 31);
        do{
            printf("Ingrese la cantidad de unidades vendidas: ");
            scanf("%d", &cant);
            if(cant<0)
                printf("\nERROR, ingrese un valor mayor a cero.\n\n");
        }while(cant<0);
        Ventas[poscod][mes-1] += cant;
        Recaudacion[poscod] = Precios[poscod]*cant;
        cod = IngresaCodigoProducto(CodProductos,TAM);
    }
    MostrarVentas(CodProductos, Ventas, TAM, 12);
    MayorRecaudacion(Recaudacion, CodProductos, TAM);

    return 0;
}
int Buscar(int vec[], int buscado, int cant)
{
    int i=0, pos=-1;
    while(i<cant && pos==-1)
    {
        if(vec[i] == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}
void CargaCodigosYPrecios(int veccod[], float vecprecios[], int cant)
{
    int i, codigo, pos;
    float precio;

    for(i=0; i<cant; i++)
    {
        do{
            printf("Ingrese el codigo del producto %d: ", i+1);
            scanf("%d", &codigo);
            pos = Buscar(veccod, codigo, i);
            if((codigo>99 && codigo<1000) && pos==-1)
            {
                do{
                    printf("Ingrese el precio del producto %d ($): ", i+1);
                    scanf("%f", &precio);
                    if(precio<0)
                        printf("\nERROR, ingrese un precio valido (mayor a 0)\n\n");
                }while(precio<0);
                veccod[i] = codigo;
                vecprecios[i] = precio;
            }
            else if(pos!=-1)
                printf("\nERROR, el codigo ya se encuentra registrado, ingrese un codigo diferente\n\n");
            else
                printf("\nERROR, ingrese un codigo valido de 3 digitos.\n\n");
        }while(codigo<100 || codigo>999 || pos!=-1);
    }
}
void MostrarListadoProductos(int vecprod[], float vecprecios[], int cant)
{
    int i;
    printf("---LISTADO DE PRODUCTOS---\n");
    printf("%10s%10s\n","CODIGO","PRECIO");
    for(i=0; i<cant; i++)
        printf("%10d%12.2f\n",vecprod[i],vecprecios[i]);
}
int IngresaCodigoProducto(int vecprod[], int cant)
{
    int i, pos, cod;

    do{
        printf("Ingrese el codigo del producto (0 para finalizar): ");
        scanf("%d", &cod);
        pos = Buscar(vecprod, cod, cant);
        if(pos==-1 && cod!=0)
            printf("ERROR, el codigo de producto no existe, ingrese otro de la lista.\n\n");
    }while(pos==-1 && cod!=0);

    return cod;
}
int IngresarFecha(char tipo[], int liminf, int limsup)
{
    int fecha;
    do{
        printf("Ingrese el %s de la venta (%d a %d): ",tipo, liminf, limsup);
        scanf("%d", &fecha);
        if(fecha<liminf || fecha>limsup)
            printf("\nERROR, ingrese un %s valido.\n\n",tipo);
    }while(fecha<liminf || fecha>limsup);
    return fecha;
}
void MostrarVentas(int veccod[], int vecvent[][12], int cfil, int ccol) ///Punto a)
{
    int i,j;
    printf("\nCod/Mes\t%5s%5s%5s%5s%5s%5s%5s%5s%5s%5s%5s%5s\n", "ene","feb","mar","abr","may","jun","jul","ago","sep","oct","nov","dic");

    for(i=0; i<cfil; i++)
    {
        printf("%5d\t",veccod[i]);
        for(j=0; j<ccol; j++)
        {
            printf("%5d",vecvent[i][j]);
        }
        printf("\n");
    }
}
void MayorRecaudacion(float vecrec[], int veccod[], int cant)
{
    int i, mayorcod;
    float mayorrec = vecrec[0];
    for(i=0; i<cant; i++)
    {
        if(vecrec[i] > mayorrec)
        {
            mayorrec = vecrec[i];
            mayorcod = veccod[i];
        }
    }
    printf("\nEl producto con codigo %d tiene la mayor recaudacion con $%.2f.",mayorcod, mayorrec);
}
