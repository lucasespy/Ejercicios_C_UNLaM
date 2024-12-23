#include<stdio.h>
#include<stdlib.h>

int main()
{
    int mat[3][3], num, i,j;
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Ingrese un numero para la posicion %dx%d de la matriz: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%5d",mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            mat[i][j] = num * mat[i][j];
        }
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%5d",mat[i][j]);
        printf("\n");
    }
    return 0;
}
