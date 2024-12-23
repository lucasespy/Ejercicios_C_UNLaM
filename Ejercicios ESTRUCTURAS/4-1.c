#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char cod[6];
    float precio;
    char desc[31];
    int cant_vent;
    float importe_total;
}sProd;
void IngresaTexto(char[], int);
int Carga(sProd[], int);
int Buscar(sProd[], char[], int);
void Mostrar(sProd[], int);
int main()
{
    sProd vecprod[51];
    int cantproductos, pos, cant;
    char cod[6];
    cantproductos = Carga(vecprod, 51);

    do{
        printf("Ingrese el codigo del producto de 5 caracteres: ");
        IngresaTexto(cod, 6);
        pos = Buscar(vecprod, cod, cantproductos);
        if(pos==-1)
            printf("\nEl producto no se encuentra registrado, ingrese otro.\n\n");
    }while(pos==-1);
    printf("Ingrese la cantidad a vender del producto (%s): ",cod);
    scanf("%d", &cant);
    while(cant != 0)
    {
        vecprod[pos].cant_vent += cant;
        vecprod[pos].importe_total += cant * vecprod[pos].precio;
        do{
            printf("Ingrese el codigo del producto de 5 caracteres: ");
            IngresaTexto(cod, 6);
            pos = Buscar(vecprod, cod, cantproductos);
            if(pos==-1)
                printf("\nEl producto no se encuentra registrado, ingrese otro.\n\n");
        }while(pos==-1);

        printf("Ingrese la cantidad a vender del producto (%s): ",cod);
        scanf("%d", &cant);
    }

    Mostrar(vecprod, cantproductos);
}
void IngresaTexto(char string[], int cant)
{
    int i=0;
    fflush(stdin);
    fgets(string, cant, stdin);
    while(string[i] != '\0')
    {
        if(string[i] == '\n')
            string[i] = '\0';
        else
            i++;
    }
}
int Carga(sProd vec[], int cant)
{
    int i=0;

    printf("Ingrese codigo de 5 digitos ('FIN' para finalizar): ");
    IngresaTexto(vec[i].cod, 6);

    while(strcmpi(vec[i].cod,"FIN") !=0 && i<cant)
    {
        printf("Ingrese el precio del producto (%s): ",vec[i].cod);
        scanf("%f", &vec[i].precio);
        printf("Ingrese la descripcion del producto (%s): ",vec[i].cod);
        IngresaTexto(vec[i].desc, 31);
        printf("Ingrese la cantidad de unidades vendidas del mes anterior: ");
        scanf("%d", &vec[i].cant_vent);
        printf("Ingrese el importe total vendido del mes anterior: ");
        scanf("%f", &vec[i].importe_total);
        i++;
        printf("Ingrese codigo de 5 digitos ('FIN' para finalizar): ");
        IngresaTexto(vec[i].cod, 6);
    }


    return i; /// i va a ser la cantidad de datos cargados.
}
int Buscar(sProd vec[], char buscado[], int cant)
{
    int i=0, pos=-1;
    while(i<cant && pos==-1)
    {
        if(strcmpi(vec[i].cod, buscado)==0)
            pos = i;
        else
            i++;
    }
    return pos;
}
void Mostrar(sProd vec[], int cant)
{
    int i;
    printf("%s\t%s\t%s\n", "DESCRIPCION", "CANTIDAD DE UNIDADES VENDIDAS", "IMPORTE TOTAL VENDIDO");
    for(i=0; i<cant; i++)
        printf("%s\t\t\t%d\t\t\t$%.2f\n",vec[i].desc, vec[i].cant_vent, vec[i].importe_total);
}
