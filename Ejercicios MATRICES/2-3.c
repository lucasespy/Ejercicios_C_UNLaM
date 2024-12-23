#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void MostrarMatriz(int[][8], int, int);
void MaximoValor(int[][8], int, int);
int main()
{
    int mat[5][8]={{0}}, i, j;
    srand(time(NULL));
    for(i=0; i<5; i++)
    {
        for(j=0; j<8; j++)
        {
            mat[i][j] = (rand() % 90) + 10;
        }
    }
    MostrarMatriz(mat, 5, 8);
    MaximoValor(mat, 5, 8);

    return 0;
}
void MostrarMatriz(int mat[][8], int cfil, int ccol)
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
void MaximoValor(int mat[][8], int cfil, int ccol)
{
    int i,j, max = mat[0][0], contmax=0;
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            if(mat[i][j] > max)
                max = mat[i][j];
        }
    }
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            if(mat[i][j] == max)
                contmax++;
        }
    }
    printf("El maximo valor es %d y se repite %d veces en las posiciones : ",max, contmax);
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            if(mat[i][j] == max)
                printf("%dx%d ",i+1, j+1);
        }
    }
}
