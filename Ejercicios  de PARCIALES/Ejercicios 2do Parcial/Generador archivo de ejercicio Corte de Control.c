#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int sucursal;
    int sector;
    int nroEmpleado;
    float sueldo;
}sBanco;

int main()
{
    sBanco p;
    FILE *fp;
    int i;

    fp=fopen("CASH.dat","wb");

    if (fp==NULL)
    {
        printf("Error en apertura del archivo");
        exit(1);
    }



    for(i=0;i<6;i++)
    {
        printf("Ingrese codigo sucursal:");
        scanf("%d",&p.sucursal);
        printf("Ingrese codigo sector:");
        scanf("%d",&p.sector);
        printf("Ingrese Empleado [1-10]:");
        scanf("%d",&p.nroEmpleado);
        printf("Sueldo:");
        scanf("%f",&p.sueldo);
        fwrite(&p, sizeof(sBanco),1,fp);
    }
    fclose(fp);
    return 0;
}

