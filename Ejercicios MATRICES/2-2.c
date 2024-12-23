#include<stdio.h>
#include<stdlib.h>
void IngresarMatriz(int[][4], int, int);
void MostrarMatriz(int[][4], int, int);
void SumaxFila(int[][4], int, int);
void SumaxColumna(int[][4], int, int);
int main()
{
    int mat[5][4];

    IngresarMatriz(mat, 5, 4);
    MostrarMatriz(mat, 5, 4);
    SumaxFila(mat, 5, 4);
    SumaxColumna(mat, 5, 4);

    return 0;
}
void IngresarMatriz(int mat[][4], int cfil, int ccol)
{
    int i,j;
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            printf("Ingrese un valor para la posicion %dx%d de la matriz: ",i+1,j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}
void MostrarMatriz(int mat[][4], int cfil, int ccol)
{
    int i,j;
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
}
void SumaxFila(int mat[][4], int cfil, int ccol)
{
    int i,j, vecfil[5]={0};
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
            vecfil[i] += mat[i][j];
    }
    printf("La suma por cada fila es: \n");
    for(i=0; i<cfil; i++)
        printf("Fila %d: %d\n",i+1,vecfil[i]);
}
void SumaxColumna(int mat[][4], int cfil, int ccol)
{
    int i, j, veccol[4]={0};
    for(i=0; i<ccol; i++)
    {
        for(j=0; j<cfil; j++)
            veccol[i] += mat[j][i];
    }
    printf("La suma por cada columna es: \n");
    for(i=0; i<ccol; i++)
        printf("Columna %d: %d\n", i+1, veccol[i]);
}
