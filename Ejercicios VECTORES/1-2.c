#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Buscar(int [], int, int);
int IngresarYValidar(int, int, int);
void IngresaCodigos(int[], int);
void MostrarCodigos(int[], int);
void CargaPedidos(int[], int[], int);
void ListadoVenta(int[], int[], int);
void MayorUnidades(int[], int[], int);
void MenorUnidades(int[], int[], int);
int main()
{
    int produ[10], cantprod[10]={0}, cod, cant;

    IngresaCodigos(produ, 10);
    MostrarCodigos(produ, 10);
    CargaPedidos(produ, cantprod, 10);
    ListadoVenta(produ, cantprod, 10);
    MayorUnidades(produ, cantprod, 10);

    return 0;
}
int Buscar(int vec[], int buscado, int cant)
{
    int pos = -1, i = 0;

    while(i < cant && pos == -1)
    {
        if(vec[i] == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}
int IngresarYValidar(int liminf, int limsup, int dif)
{
    int num, error;
    do{
        error = 0;
        scanf("%d", &num);
        if((num < liminf || num > limsup) && num != dif)
        {
            error = 1;
            printf("\nError, codigo incorrecto. Vuelva a ingresar.\n\n");
        }
    }while(error);
    return num;
}
void IngresaCodigos(int vec[], int cant) // Solamente carga el vector con codigos
{
    int i, pos;
    for(i = 0; i < cant; i++)
    {
        do{
            printf("Ingrese el codigo para el producto %d: ", i+1);
            vec[i] = IngresarYValidar(1000, 9999, 0);
            pos = Buscar(vec, vec[i], i);
            if(pos != -1)
            {
                printf("\nCodigo duplicado, vuelva a ingresar.\n\n");
            }
            else if(vec[i] == 0)
            {
                printf("El codigo de un producto no puede ser cargado con cero (0), vuelva a ingresar.\n\n");
            }
        }while(vec[i] < 1000 || vec[i] > 9999 || vec[i] == 0 || pos != -1);
    }
}
void MostrarCodigos(int vec[], int cant)
{
    int i;
    printf("\n---Codigos---\n\n");
    for(i = 0; i < cant; i++)
        printf("%d.\t%d\n",i+1, vec[i]);
}
void CargaPedidos(int prod[], int cantprod[], int cant)
{
    int i, pos, cod, unidades;

    do{
        printf("Ingrese el codigo de producto (0 para finalizar): ");
        scanf("%d", &cod);
        pos = Buscar(prod, cod, cant);
        if(pos == -1)
            printf("\nEl codigo no se encuentra cargado, ingrese otro.\n\n");
    }while(pos == -1 && cod != 0);

    while(cod != 0)
    {
        printf("Ingrese la cantidad de unidades para el producto %d: ", prod[pos]);
        scanf("%d", &unidades);
        cantprod[pos] += unidades;
            do{
                printf("Ingrese el codigo de producto (0 para finalizar): ");
                scanf("%d", &cod);
                pos = Buscar(prod, cod, cant);
                if(pos == -1)
                    printf("\nEl codigo no se encuentra cargado, ingrese otro.\n\n");
            }while(pos == -1 && cod != 0);
    }
    printf("\n---CARGA FINALIZADA---\n");
}
void ListadoVenta(int vecprod[], int veccant[], int cant) //Punto a)
{
    int i;
    printf("---LISTADO---\n\n");
    printf("%s%10s\n", "PRODUCTO", "CANTIDAD");
    for(i = 0; i < cant; i++)
        if(veccant[i] != 0)
            printf("%5d%10d\n",vecprod[i],veccant[i]);
}
void MayorUnidades(int vecprod[], int veccant[], int cant)
{
    int i, mayor = veccant[0];

    for(i = 0; i < cant; i++)
        if(veccant[i] > mayor)
            mayor = veccant[i];
    printf("El / los productos con mayor cantidad de unidades son: \n");
    for(i = 0; i < cant; i++)
        if(veccant[i] == mayor)
            printf("Producto: %d con %d unidades\n", vecprod[i], veccant[i]);

}
void MenorUnidades(int vecprod[], int veccant[], int cant)
{
    int i, menor = veccant[0];

    for(i = 0; i < cant; i++)
        if(veccant[i] < menor)
            menor = veccant[i];

    printf("El / los productos con menor cantidad de unidades son: \n");
    for(i = 0; i < cant; i++)
        if(veccant[i] == menor)
            printf("Producto: %d con %d unidades\n", vecprod[i], veccant[i]);

}
