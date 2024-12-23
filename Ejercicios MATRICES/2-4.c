/*  codigo de agencia (1 a 15)
    codigo de tour (1 a 10)
    cantidad de pasajes (0 a 20)
    finaliza con agencia = 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int LeerYValidar(int, int, int);
int IngresoAgencia(void);
int IngresoTour(void);
int IngresoPasajes(void);
void MostrarVentas(int[][10], int, int);
void MostrarMayorPasajes(int[][10], int, int);

int main()
{
    int ventas[15][10]={{0}}, cantpasajes, agencia, tour;

    agencia = IngresoAgencia();
    while(agencia != 0)
    {
        tour = IngresoTour();
        cantpasajes = IngresoPasajes();
        ventas[agencia-1][tour-1] += cantpasajes;
        agencia = IngresoAgencia();
    }
    printf("---CARGA FINALIZADA---\n\n");

    MostrarVentas(ventas,15,10);
    MostrarMayorPasajes(ventas,15,10);
    return 0;
}
int LeerYValidar(int liminf, int limsup, int dif)
{
    int num, error;
    do{
        error = 0;
        printf("Ingrese codigo entre %d y %d (%d para finalizar): ",liminf, limsup, dif);
        scanf("%d", &num);
        if((num < liminf || num > limsup) && num != dif)
        {
            error = 1;
            printf("\nERROR, codigo no valido, vuelva a ingresar\n\n");
        }
    }while(error);

    return num;
}
int IngresoAgencia(void)
{
    int cod;
    printf("---INGRESO DE AGENCIA---\n");
    cod = LeerYValidar(1,15,0);
    return cod;
}
int IngresoTour(void)
{
    int cod, error;
    printf("\n---INGRESO TOUR---\n");
    do{
        error = 0;
        printf("Ingrese codigo entre 1 y 15: ");
        scanf("%d", &cod);
        if(cod < 1 || cod > 15)
        {
            error = 1;
            printf("\nERROR, codigo no valido, vuelva a ingresar\n\n");
        }
    }while(error);

    return cod;
}
int IngresoPasajes(void)
{
    int cant;
    printf("\n---INGRESO CANTIDAD DE PASAJES---\n");
    do{
        printf("Ingrese la cantidad de pasajes (0 a 20): ");
        scanf("%d", &cant);
        if(cant < 0 || cant > 20)
            printf("\nERROR, cantidad no valida, vuelva a ingresar\n\n");
    }while(cant < 0 || cant > 20);

    return cant;
}
void MostrarVentas(int mat[][10], int cfil, int ccol)
{
    int i, j;
    printf("---TOTAL DE VENTAS POR AGENCIA---\n\n");
    printf("%s/%s\n","AGENCIA", "TOUR");
    for(i=0; i<ccol; i++)
        printf("\t%d", i+1);
    printf("\n");

    for(i=0; i<cfil; i++)
    {
        printf("%d", i+1);
        for(j=0; j<ccol; j++)
            printf("\t%d",mat[i][j]);
        printf("\n");
    }
}
void MostrarMayorPasajes(int mat[][10], int cfil, int ccol)
{
    int i, j, mayor = mat[0][0], maxagencia;
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            if(mat[i][j] > mayor)
            {
                mayor = mat[i][j];
                maxagencia = i+1;
            }
        }
    }
    printf("La agencia '%d' vendio mas cantidad con '%d' pasajes vendidos.\n\n",maxagencia, mayor);
    printf("Las agencias que obtuvieron la maxima cantidad de ventas son: \n");
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            if(mat[i][j] == mayor)
                printf("Agencia %d.\n",i+1);
        }
    }
}
