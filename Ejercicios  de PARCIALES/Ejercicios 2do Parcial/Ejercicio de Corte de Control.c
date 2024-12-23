/*El banco CASH dispone de un archivo con la siguiente información:

.     Código de Sucursal
.     Código de Sector
.    Nro. Empleado,
.    Sueldo

Los datos están ordenados por: código de Sucursal,

Desarrollar un programa en lenguaje C pata informar:

La cantidad de empleados de cada sucursal, indicando sucursal y cantidad
El sueldo total de los empleados del banco
La sucursal con menor cantidad de empleados.
Generar un archivo con el promedio de sueldo de cada sucursal que incluya dos campos:
   • Código de Sucursal.
   • Promedio.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int codsucursal;
    int codsector;
    int numempleado;
    float sueldo;
}sBanco;

typedef struct
{
    int codsucursal;
    float promedio;
}sPromedio;

int main()
{
    sBanco banco;
    sPromedio prom;
    FILE *pfbank, *pfpromedio;
    int sucAnterior, cantempleados, bandera, menorcantempleados, menorsuc;
    float sueldosuc, sueldototal;

    pfbank = fopen("CASH.dat", "rb");
    pfpromedio = fopen("PROMEDIO.dat", "wb");
    if(pfbank==NULL || pfpromedio==NULL)
    {
        printf("\nERROR en la apertura de los archivos.\n");
        exit(1);
    }
    sueldototal=0;
    bandera=0;
    fread(&banco, sizeof(sBanco), 1, pfbank);
    while(!feof(pfbank))
    {
        sueldosuc = 0;
        cantempleados = 0; /// a)
        sucAnterior = banco.codsucursal;
        while(!feof(pfbank) && sucAnterior==banco.codsucursal)
        {
            cantempleados++; /// a)
            sueldosuc+= banco.sueldo; /// NO HACE FALTA HACER ESTO
            sueldototal += banco.sueldo; /// b)
            fread(&banco, sizeof(sBanco), 1, pfbank);
        }
        printf("Sucursal: %d\nCantidad de empleados: %d\n", sucAnterior, cantempleados);
        printf("Sueldo total en la sucursal: %.2f\n---------------------------------\n", sueldosuc);

        if(!bandera || cantempleados<menorcantempleados) /// c)
        {
            bandera=1;
            menorcantempleados = cantempleados;
            menorsuc = sucAnterior;
        }
        if(cantempleados>0)
        {
            prom.codsucursal = sucAnterior;
            prom.promedio = sueldosuc/cantempleados;
            fwrite(&prom, sizeof(sPromedio), 1, pfpromedio);
        }
    }
    printf("El sueldo total de los empleados del banco es: $%.2f\n", sueldototal);/// mostrar b)
    printf("La sucursal con menor cantidad de empleados es: %d\n", menorsuc); /// mostrar c)

    fclose(pfbank);
    fclose(pfpromedio);

    return 0;
}
