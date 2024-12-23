#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int LeerYValidar(int, int, int);
void MenorVotos(int[][15], int, int);
void SumaxFila(int[][15], int, int);
void SumaxColumna(int[][15], int, int);
void Lista11(int[][15], int, int);
int main()
{
    int mat[23][15]={{0}}, prov, lista, cant=0;

    printf("---Ingreso de PROVINCIA (0 para finalizar)---\n");
    prov = LeerYValidar(1,23,0);

    while(prov!=0)
    {
        printf("---Ingreso de LISTA---\n");
        lista = LeerYValidar(1,15,1);
        do{
            printf("Ingrese la cantidad de votos: ");
            scanf("%d", &cant);
            if(cant<0)
                printf("\nERROR, la cantidad debe ser mayor o igual a cero.\n\n");
        }while(cant<0);

        mat[prov-1][lista-1] += cant;
        printf("---Ingreso de PROVINCIA (0 para finalizar)---\n");
        prov = LeerYValidar(1,23,0);
    }
    MenorVotos(mat, 23, 15);
    SumaxFila(mat, 23, 15);
    SumaxColumna(mat, 23, 15);
    Lista11(mat, 23, 15);

    return 0;
}
int LeerYValidar(int liminf, int limsup, int dif)
{
    int num;
    do{
        printf("Ingrese entre %d y %d: ", liminf, limsup);
        scanf("%d", &num);
        if((num<liminf || num>limsup) && num!=dif)
            printf("\nERROR, vuelva a ingresar.\n\n");
    }while((num<liminf || num>limsup) && num!=dif);
    return num;
}
void MenorVotos(int mat[][15], int cfil, int ccol) ///Punto a)
{
    int i=0, j=0, menor=999999999, bandera=0;

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
            {
                if(mat[i][j] < menor && mat[i][j]!=0)
                    menor = mat[i][j];
            }
    }
    printf("\nLa menor cantidad de votos es %d.\n", menor);
    printf("Las Provincias y listas con la misma cantidad de votos son: \n");

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
            if(mat[i][j] == menor && mat[i][j]!=0)
            {
                printf("Provincia %d, Lista %d.\n", i+1, j+1);
                bandera++;
            }
    }
    if(bandera==0)
        printf("*Ninguna provincia y numero de lista tuvieron la misma cantidad de votos al menor*\n\n");
}
void SumaxFila(int mat[][15], int cfil, int ccol)///Punto b) Suma por fila para sumar votos por provincia.
{
    int i, j, provincias[23]={0};

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
            provincias[i] += mat[i][j];
    }

    printf("%s\t%s\n","PROVINCIA", "VOTOS");
    for(i=0; i<cfil; i++)
        printf("%3d\t\t%3d\n",i+1, provincias[i]);
}
void SumaxColumna(int mat[][15], int cfil, int ccol) ///Punto c)
{
    int i,j, votosxlista[15]={0}, mayor, ganador;

    for(i=0; i<ccol; i++)
    {
        for(j=0; j<cfil; j++)
            votosxlista[i] += mat[i][j];
    }

    mayor = votosxlista[0];
    for(i=0; i<ccol; i++)
    {
        if(votosxlista[i] > mayor)
        {
            mayor = votosxlista[i];
            ganador = i+1;
        }
    }
    printf("\nEl numero de lista ganadora es %d.\n", ganador);
}
void Lista11(int mat[][15], int cfil, int ccol)
{
    int i, j, votoslista11[23]={0}, provincias[23], aux;

    for(i=0; i<cfil; i++)
    {
        votoslista11[i] += mat[i][10];
        provincias[i] = i;
    }

    ///Ordeno

    for(i=0; i<cfil-1; i++)
    {
        for(j=0; j<cfil-1-i; j++)
        {
            if(votoslista11[j] < votoslista11[j+1])
            {
                aux = votoslista11[j];
                votoslista11[j] = votoslista11[j+1];
                votoslista11[j+1] = aux;

                aux = provincias[j];
                provincias[j] = provincias[j+1];
                provincias[j+1] = aux;
            }
        }
    }
    printf("\tLista Numero 11\nPROVINCIA\tCantidad de Votos\n");
    for(i=0; i<cfil; i++)
        printf("%d\t\t%6d\n",provincias[i], votoslista11[i]);
}
