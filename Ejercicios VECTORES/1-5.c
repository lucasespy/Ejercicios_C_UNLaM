#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int BusquedaSecuencial(int[], int, int);
int BusquedaBinaria(int[], int, int);
void BubbleSort(int[], int);
void CargaProductos(int[], int);
int LeerYValidar(int, int, int);
int IngresarCodigoProd(int[], int);
void MostrarListado(int[], int[], int);
void MostrarVendedores(int[], int[], int);
int main()
{
    int prod[15], cantprod[15]={0}, vendedor[5]={1001,1002,1003,1004,1005}, cant, codprod, posprod,codvendedor, posvendedor;
    int cantvendedor[5]={0};
    CargaProductos(prod,15);
    codvendedor = LeerYValidar(1001, 1005, 0);

    while(codvendedor!=0)
    {
        codprod = IngresarCodigoProd(prod,15);
        posprod = BusquedaSecuencial(prod, codprod, 15);
        do{
            printf("Ingrese la cantidad de elementos a vender para el producto %d: ",codprod);
            scanf("%d", &cant);
            if(cant<0)
                printf("\nERROR, la cantidad no puede ser menor a %d\n\n",0);
        }while(cant<0);

        cantprod[posprod]+= cant;
        posvendedor = BusquedaSecuencial(vendedor, codvendedor, 5);
        cantvendedor[posvendedor]++;

        codvendedor = LeerYValidar(1001, 1005, 0);
    }
    MostrarListado(prod, cantprod, 15);
    MostrarVendedores(vendedor, cantvendedor,5);
    return 0;
}
int BusquedaSecuencial(int vec[], int buscado, int cant)
{
    int pos=-1, i=0;
    while(i<cant && pos==-1)
    {
        if(vec[i] == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}
int BusquedaBinaria(int vec[], int buscado, int cant)
{
    int pos=-1, liminf=0, limsup=cant-1, med;
    while(liminf<=limsup && pos==-1)
    {
        med = (liminf+limsup)/2;
        if(vec[med] == buscado)
            pos = med;
        else if(buscado < vec[med])
            liminf = med+1;
            else
                limsup = med-1;
    }
    return pos;
}
void BubbleSort(int vec[], int cant)
{
    int i, j, aux, limite = cant-1;
    for(i=0; i<limite; i++)
    {
        for(j=0; j<limite-i; j++)
        {
            if(vec[j] < vec[j+1])
            {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
}
void CargaProductos(int vecprod[], int cant)
{
    int i, cod, pos;
    printf("---CARGA DE CODIGOS DE LOS %d PRODUCTOS---\n", cant);
    for(i=0; i<cant; i++)
    {
        do{
            printf("Ingrese el codigo de tres digitos para el producto %d: ",i+1);
            scanf("%d", &cod);
            pos = BusquedaSecuencial(vecprod, cod, i);
            if(cod<100 || cod>999)
                printf("\nERROR, el codigo debe tener 3 digitos.\n\n");
            else if(pos!=-1)
                printf("\nERROR, el codigo ya se encuentra en el sistema. Ingrese un codigo diferente.\n\n");
        }while(cod<100 || cod>999 || pos!=-1);
        vecprod[i] = cod;
    }
    BubbleSort(vecprod,cant);
    printf("---LISTADO DE PRODUCTOS---\n");
    for(i=0; i<cant; i++)
        printf("%14d\n",vecprod[i]);
}
int LeerYValidar(int liminf, int limsup, int dif)
{
    int cod, error;
    do{
        error = 0;
        printf("Ingrese el codigo de vendedor (%d - %d): ", liminf, limsup);
        scanf("%d", &cod);
        if((cod<liminf || cod>limsup) && cod!=dif)
        {
            error = 1;
            printf("\nERROR, codigo de vendedor no valido, vuelva a ingresar.\n\n");
        }
    }while(error);
    return cod;
}
int IngresarCodigoProd(int vec[], int cant)
{
    int cod, pos;
    do{
        printf("Ingrese codigo de producto a vender de la lista: ");
        scanf("%d", &cod);
        pos = BusquedaBinaria(vec, cod, cant);
        if(pos==-1)
            printf("\nERROR, el codigo no se encuentra en la lista, vuelva a ingresar.\n\n");
    }while(pos==-1);
    return cod;
}
void MostrarListado(int vecprod[], int veccant[], int cant) //a)
{
    int i;
    printf("%25s%20s\n", "CANT UNIDADES","CODIGO");
    for(i=0; i<cant; i++)
        printf("%20d%20d\n\t\t%s\n",veccant[i], vecprod[i], "==========================");
}
void MostrarVendedores(int vecvend[], int veccant[], int cant) //b)
{
    int i, j, menor=veccant[0];
    printf("\n%25s%20s\n", "VENDEDOR","CANTIDAD DE VENTAS");
    for(i=0; i<cant; i++)
        printf("%20d%20d\n",vecvend[i], veccant[i]);

    for(i=0; i<cant; i++)
        if(veccant[i] < menor)
            menor = veccant[i];

    printf("Los vendedores que realizaron menor cantidad de ventas son: \n");
    for(i=0; i<cant; i++)
        if(veccant[i]==menor)
            printf("Vendedor %d, con %d ventas.\n",vecvend[i],veccant[i]);
}
