/*Una cadena de artículos del hogar necesita liquidar comisiones de sus casi 50 vendedores
y para ello se deben registrar y almacenar con la estructura adecuada:

Número de Vendedor (entero de 2 cifras no correlativo y sin repetidos)
Nombre Vendedor (string de 25 caracteres)
Sector (E – Electrodomésticos, M – Muebles, V – Vajillas, T – Telefonía)
Porcentaje de comisión (entero entre 5 y 15)
Comisión a cobrar (real)
La liquidación de comisiones termina con el ingreso de un número de vendedor igual a cero.

Luego, por cada vendedor se ingresarán las ventas que hizo por cada día (real mayor o igual que 0) en los 21 días del mes y
debe actualizar la comisión a cobrar. También finaliza con un número de vendedor igual a cero.

Se necesita determinar e informar:

1. Listado de comisiones cobradas por día y vendedor mostrando su nombre (resolver en una función).
2. El nombre del vendedor que cobra la menor comisión actualizada, en caso de ser más de uno mostrarlos a todos.
3. El importe total a pagar de comisiones por cada sector (resolver en una función).
Validar todos los datos que ingresan por teclado según lo indicado.
El código debe estar correctamente identado.    */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    int numero; ///2 cifras no correlativo y sin repetidos
    char nombre[26];
    char sector; ///E – Electrodomésticos, M – Muebles, V – Vajillas, T – Telefonía
    float comision;
}sVendedor;
int LeerYValidar(int, int, int);
void IngresaTexto(char[], int);
int Buscar(sVendedor[], int, int);
int CargarVector(sVendedor[], int);
void ComisionesPorDia(float[], int, int, char[][26]);
void MenorComision(sVendedor[], int);
void ComisionPorSector(sVendedor[], int);
void MostrarVendedores(sVendedor[], int);
int main()
{
    sVendedor vec[50];
    int num, porcencom, i, pos, dia;
    char sect, nombrecomxdia[21][26]={{0}};
    float venta, mes[21]={0};

    i = CargarVector(vec, 50);
    MostrarVendedores(vec, i);

    printf("--Ventas--\n");
    do{
        printf("Ingrese el numero de vendedor (0 para finalizar)\n");
        num = LeerYValidar(1,99,0);
        pos = Buscar(vec, num, i);
        if(pos==-1 && num!=0)
            printf("\nERROR, el numero de vendedor no existe, ingrese otro.\n\n");
    }while(pos==-1 && num!=0);

    while(num!=0)
    {
        printf("Ingrese el dia de la venta: ");
        dia = LeerYValidar(1,21,1);
        do{
            printf("Ingrese el sector (E - Electrodomesticos, M - Muebles, V - Vajillas, T - Telefonia): ");
            fflush(stdin);
            scanf("%c", &sect);
            sect = toupper(sect);
            if(sect!='E' && sect!='M' && sect!='V' && sect!='T')
                printf("\nERROR, sector no valido, vuelva a ingresar.\n\n");
        }while(sect!='E' && sect!='M' && sect!='V' && sect!='T');
        vec[pos].sector = sect;
        do{
            printf("Ingrese el monto de la venta: ");
            scanf("%f", &venta);
            if(venta<0)
                printf("\nERROR, el monto debe ser mayor a cero.\n\n");
        }while(venta<0);
        printf("Ingrese el porcentaje de la comision.\n");
        porcencom = LeerYValidar(5,15,5);
        vec[pos].comision += (venta*porcencom)/100;
        mes[dia-1] += (venta*porcencom)/100;                    ///PARTE DEL PUNTA a)
        strcpy(nombrecomxdia[dia-1], vec[pos].nombre);          ///PARTE DEL PUNTO a)
        do{
            printf("Ingrese el numero de vendedor (0 para finalizar)\n");
            num = LeerYValidar(1,99,0);
            pos = Buscar(vec, num, i);
            if(pos==-1 && num!=0)
                printf("\nERROR, el numero de vendedor no existe, ingrese otro.\n\n");
        }while(pos==-1 && num!=0);
    }
    ComisionesPorDia(mes, i, 21, nombrecomxdia);
    MenorComision(vec, i);
    ComisionPorSector(vec,i);

    return 0;
}
int LeerYValidar(int liminf, int limsup, int dif)
{
    int num;
    do{
        printf("Ingrese entre %d y %d: ",liminf, limsup);
        scanf("%d", &num);
        if((num<liminf || num>limsup) && num!=dif)
            printf("\nERROR, ingreso no valido, vuelva a ingresar.\n\n");
    }while((num<liminf || num>limsup) && num!=dif);
    return num;
}
void IngresaTexto(char string[], int cant)
{
    int i=0;
    fflush(stdin);
    fgets(string, cant, stdin);

    while(string[i] != '\0' && i<cant)
    {
        if(string[i] == '\n')
            string[i] = '\0';
        else i++;
    }
}
int Buscar(sVendedor vec[], int buscado, int cantmax)
{
    int i=0, pos=-1;

    while(i<cantmax && pos==-1)
    {
        if(vec[i].numero == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}
int CargarVector(sVendedor vec[], int cantmax)
{
    int i=0, numvend, pos;
    char nombrevend[26];

    printf("--Carga de vector--\n\n");
    do{
        printf("--Ingreso de NUMERO de vendedor (0 para finalizar carga)--\n");
        numvend = LeerYValidar(10,99,0);
        pos = Buscar(vec, numvend, i);
        if(pos!=-1)
            printf("\nERROR, el codigo de vendedor ya fue ingresado, vuelva a ingresar uno diferente.\n\n");
    }while(pos!=-1);

    while(numvend != 0 && i<cantmax)
    {
        vec[i].numero = numvend;
        printf("--Ingreso de NOMBRE de vendedor--\n");
        IngresaTexto(nombrevend, 26);
        strcpy(vec[i].nombre, nombrevend);
        vec[i].comision = 0;

        i++;

        do{
            printf("--Ingreso de NUMERO de vendedor (0 para finalizar carga)--\n");
            numvend = LeerYValidar(10,99,0);
            pos = Buscar(vec, numvend, i);
        if(pos!=-1)
            printf("\nERROR, el codigo de vendedor ya fue ingresado, vuelva a ingresar uno diferente.\n\n");
        else if(numvend == vec[i-1].numero-1 || numvend == vec[i-1].numero+1)
            printf("\nERROR, no se pueden ingresar numeros correlativos.\n\n");
        }while(pos!=-1 || numvend == vec[i-1].numero-1 || numvend == vec[i-1].numero+1);
    }

    return i;
}
void ComisionesPorDia(float dia[], int cant, int cant_dias, char nombre[][26]) ///Punto a)
{
    int i;

    printf("\t--LISTADO DE COMISIONES COBRADAS POR DIA---\n");
    printf("%s\t%s\t%s\n", "DIA", "COMISION", "VENDEDOR");
    for(i=0; i<cant_dias; i++)
        printf("%d\t%.2f\t\t%s\n", i+1, dia[i], nombre[i]);
}
void MenorComision(sVendedor vec[], int cant)///Punto b)
{
    int i, menor=vec[0].comision, pos_menor, bandera=0;

    for(i=0; i<cant; i++)
        if(vec[i].comision < menor)
        {
            menor = vec[i].comision;
            pos_menor = i;
        }

    printf("-El nombre del vendedor con la menor comision es %s, con %.2f de comision.\n", vec[pos_menor].nombre, vec[pos_menor].comision);
    printf("-Los vendedores que tienen la misma comision son: \n");
    for(i=0; i<cant; i++)
        if(vec[i].comision == menor && vec[i].numero != vec[pos_menor].numero)
        {
            printf("%s\n",vec[i].nombre);
            bandera++;
        }
    if(bandera==0)
        printf("*No hubo vendedores con la misma comision que %s.*", vec[pos_menor].nombre);
}
void ComisionPorSector(sVendedor vec[], int cant)///Punto c)
{
    int i;
    float sector_E=0, sector_M=0, sector_V=0, sector_T=0;

    for(i=0; i<cant; i++)
    {
        switch(vec[i].sector)
        {
            case 'E': sector_E += vec[i].comision; break;
            case 'M': sector_M += vec[i].comision; break;
            case 'V': sector_V += vec[i].comision; break;
            case 'T': sector_T += vec[i].comision; break;
        }
    }
    printf("\nTotal a pagar sector Electrodomesticos: $%.2f\n",sector_E);
    printf("Total a pagar sector Muebles: $%.2f\n",sector_M);
    printf("Total a pagar sector Valijas: $%.2f\n",sector_V);
    printf("Total a pagar sector Telefonia: $%.2f\n",sector_T);
}
void MostrarVendedores(sVendedor vec[], int cant)
{
    int i;
    printf("%s\t%s\n", "Nº VENDEDOR","NOMBRE");
    for(i=0; i<cant; i++)
        printf("%d\t\t%s\n",vec[i].numero, vec[i].nombre);
}
