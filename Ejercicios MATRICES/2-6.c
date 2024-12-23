#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int LeerYValidar(int, int);
void InicializarButacas(char[][9], int, int);
void MostrarButacas(char[][9], int[], int, int);
int Buscar(int[], int, int);
void FilasVacias(char[][9], int, int);
void MayorEspectadoresxFila(char[][9], int, int);
void CantidadMismasButacas(char[][9], int, int);
void IngresoCantidadButacas(char[][9], int, int, int);
int main()
{
    char asientos[12][9];
    int numbutacas[9]={8,6,4,2,1,3,5,7,9}, posbutaca, fila, butaca, error, cantareservar=0;

    InicializarButacas(asientos, 12, 9);
    MostrarButacas(asientos,numbutacas, 12, 9);
    printf("\n---Ingreso de fila (numero negativo para finalizar carga)---\n");
    fila = LeerYValidar(-999999999, 12);
    while(fila > 0) //Punto a)
    {
        do{
            printf("\n---Ingreso de butacas---\n");
            butaca = LeerYValidar(1, 9);
            posbutaca = Buscar(numbutacas, butaca, 9);
            if(asientos[fila-1][posbutaca] == 'R')
            {
                printf("\nERROR, la butaca ya se encuentra reservada, ingrese otra.\n\n");
                printf("\n---Ingreso de fila (numero negativo para finalizar carga)---\n");
                fila = LeerYValidar(-999999999, 12);
            }
        }while(asientos[fila-1][posbutaca] == 'R');

        IngresoCantidadButacas(asientos, fila-1, posbutaca, 9);
        asientos[fila-1][posbutaca] = 'R';

        system("cls");
        MostrarButacas(asientos, numbutacas, 12, 9);
        printf("\n---Ingreso de fila (numero negativo para finalizar carga)---\n");
        fila = LeerYValidar(-999999999, 12);
    }
    FilasVacias(asientos, 12, 9);
    MayorEspectadoresxFila(asientos, 12, 9);
    CantidadMismasButacas(asientos, 12, 9);

    return 0;
}
int LeerYValidar(int liminf, int limsup)
{
    int num;
    do{
        printf("Ingrese numero entre 1 y %d: ", limsup);
        scanf("%d", &num);
        if(num < liminf || num > limsup)
            printf("\nERROR, ingreso no valido, vuelva a ingresar\n\n");
    }while(num < liminf || num > limsup);

    return num;
}
int Buscar(int vec[], int buscado, int cant) //busca el indice en la posicion del vector para posiconarlo en la columna (j) de la matriz
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
void InicializarButacas(char mat[][9], int cfil, int ccol)
{
    int i,j;
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            mat[i][j] = 'D';
        }
    }
}
void MostrarButacas(char mat[][9], int numbut[], int cfil, int ccol) // Punto a)
{
    int i,j;

    printf("Butacas\t");
    for(i=0; i<ccol; i++)
        printf("%5d", numbut[i]);
    printf("\n");
    for(i=0; i<cfil; i++)
    {
        printf("\n");
        printf("Fila %d\t",i+1);
        for(j=0; j<ccol; j++)
        {
            printf("%5c",mat[i][j]);
        }
    }
    printf("\n\n");
}
void FilasVacias(char mat[][9], int cfil, int ccol) //Punto b)
{
    int i,j, contfilas[12]={0};

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            if(mat[i][j] == 'R')
                contfilas[i]++;
        }
    }
    printf("Los numeros de filas que quedaron vacias son: \n");
    for(i=0; i<cfil; i++)
    {
        if(contfilas[i] == 0)
            printf("Fila %d.\n",i+1);
    }
}
void MayorEspectadoresxFila(char mat[][9], int cfil, int ccol) //Punto c)
{
    int i,j, contfilas[12]={0};

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            if(mat[i][j] == 'R')
                contfilas[i]++;
        }
    }
    printf("Los numeros de filas con mayor cantidad de espectadores son: \n");
    for(i=0; i<cfil; i++)
    {
        if(contfilas[i] != 0)
            printf("Fila %d. con %d espectador/es\n",i+1, contfilas[i]);
    }
}
void OrdenarVectores(int vec[], int vec2[], int cant)
{
    int i, j, aux;
    for(i=0; i<cant-1; i++)
    {
        for(j=0; j<cant-i-1; j++)
        {
            if(vec[j] < vec[j+1])
            {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;

                aux = vec2[j];
                vec2[j] = vec2[j+1];
                vec2[j+1] = aux;
            }
        }
    }

}
void CantidadMismasButacas(char mat[][9], int cfil, int ccol) // Punto d)
{
    int i,j, contbutacas[9]={0}, numbutacas[9]={8,6,4,2,1,3,5,7,9};
    for(i=0; i<ccol; i++)
    {
        for(j=0; j<cfil; j++)
        {
            if(mat[i][j] == 'R')
                contbutacas[j]++;
        }
    }
    OrdenarVectores(contbutacas, numbutacas, 9);
    printf("\n\n\t\t%s%15s\n","Butaca","Cantidad");
    for(i=0; i<ccol; i++)
        printf("\t\t%d\t\t%d\n",numbutacas[i],contbutacas[i]);

}
void IngresoCantidadButacas(char mat[][9], int fila, int columna, int ccol)
{
    int j, cant, contador;
    do{
        contador=0;
        printf("Ingrese la cantidad de butacas a reservar (consecutivas a la butaca ya reservada): ");
        scanf("%d", &cant);

        for(j=columna+1; j<=columna+cant && j<ccol; j++)
        {
            if(mat[fila][j] == 'D')
                contador++;
        }

        if(contador == cant)
        {
            for(j=columna+1; j<=columna+cant && j<ccol; j++)
                mat[fila][j] = 'R';
            printf("\nReserva de butacas exitosa!\n\n");
        }
        else
            printf("\nCantidad de butacas no disponible, ingrese otra.\n\n");
    }while(contador != cant);
}
