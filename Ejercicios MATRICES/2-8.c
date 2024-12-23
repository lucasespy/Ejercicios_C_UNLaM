#include<stdio.h>
#include<stdlib.h>
void EstablecerEdificio(char[][15], int, int);
void MostrarCobranzas(char[][15], int, int);
int LeerYValidar(int, int, int, char[20]);
int main()
{
    char edificio[5][15];
    int piso, depto;
    float cobro = 1000, cobro_total=0;

    EstablecerEdificio(edificio, 5, 15);
    MostrarCobranzas(edificio, 5, 15);
    printf("---Ingreso de piso (99 para finalizar)---\n");
    piso = LeerYValidar(1,5,99, "piso");
    while(piso != 99)
    {
        printf("---Ingreso de departamento---\n");
        depto = LeerYValidar(1, 15, 1, "departamento");
        edificio[piso-1][depto-1] = ' ';
        cobro_total += cobro;
        system("cls");
        MostrarCobranzas(edificio, 5, 15);
        printf("---Ingreso de piso (99 para finalizar)---\n");
        piso = LeerYValidar(1,5,99, "piso");
    }
    printf("Total recaudado: $%.2f",cobro_total);

    return 0;
}
void EstablecerEdificio(char edif[][15], int cfil, int ccol)
{
    int i,j;
    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
        {
            edif[i][j] = 'X';
        }
    }
}
void MostrarCobranzas(char edif[][15], int cfil, int ccol)
{
    int i,j;
    printf("\t\tTOTAL RECAUDADO\n\t    DEPARTAMENTOS DEUDORES\n");
    printf(" PISO\t");
    for(i=0; i<ccol; i++)
        printf("%s %d\t","DPTO",i+1);
    printf("\n");
    for(i=0; i<cfil; i++)
    {
        printf("Piso %d\t",i+1);
        for(j=0; j<ccol; j++)
        {
            printf("%3c\t",edif[i][j]);
        }
        printf("\n");
    }
}
int LeerYValidar(int liminf, int limsup, int dif, char word[20])
{
    int num,error;
    do{
        error = 0;
        printf("Ingrese %s (entre %d y %d): ",word, liminf, limsup);
        scanf("%d", &num);
        if((num<liminf || num>limsup) && num!=dif)
        {
            error = 1;
            printf("\nERROR, ingrese un numero de %s valido\n\n",word);
        }
    }while(error);
    return num;
}
