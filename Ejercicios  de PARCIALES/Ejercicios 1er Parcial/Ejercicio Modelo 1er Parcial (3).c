/*Una fabrica de empanadas necesita controlar la venta de sus casi 20 gustos de empanada y para eso deben
registrar y almacenar con la estructura adecuada:
        - Codigo de empanada (entero de 3 cifras no correlativo y sin repetidos)
        - Nombre Gusto (string de 25 caracteres)
        - Coccion (H - Horno, F - Fritas, S - Sin coccion)
        - Cantidad vendida (entero mayor a 0)
        - Precio (real mayor que 0)
La registracion de gustos termina con el ingreso de un codigo de empanada igual a cero. Luego por cada codigo de empanada
se ingresara la venta que hizo por cada dia de la semana (real mayor o igual que 0) en los 7 dias de la semana y debe actualizar
la cantidad vendida. La carga de las ventas finaliza con un codigo de empanada igual a cero.
Se necesita determinar e informar:
1. Listado de importe total vendido por dia y codigo de empanada mostrando su nombre (resolver en una funcion)
2. El nombre del gusto que tuvo la mayor venta, en caso de ser mas de uno mostrarlos a todos.
3. La cantidad total vendida por coccion (resolver en funcion).
Validar todos los datros que ingresan por teclado segun lo indicado.
El codigo debe estar correctamente identado.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    int codigo; ///Entero de 3 cifras no correlativo y sin repetidos
    char gusto[26];
    char coccion; ///H - Horno, F - Fritas, S - Sin coccion
    int cant_vendida;
    float precio;
}sEmpanada;
int LeerYValidar(int, int, int);
int Buscar(sEmpanada[], int, int);
void IngresaTexto(char[], int);
int CargarVector(sEmpanada[], int);
void MostrarListado(char[][100], float[], int);
void MayorVenta(sEmpanada[], int);
void CantidadxCoccion(sEmpanada[], int);
int main()
{
    sEmpanada vec[20];
    int i, cod, pos, dia, cant;
    float semana[7]={0};
    char empanadaxdia[7][100]={{0}}, coccion;

    i = CargarVector(vec,20);

    printf("\n--INGRESO DE VENTAS--\n\n");
    do{
        printf("Ingrese el CODIGO de empanadas (0 para finalizar): ");
        cod = LeerYValidar(100, 999, 0);
        pos = Buscar(vec, cod, i);
        if(pos==-1 && cod!=0)
            printf("\nERROR, el codigo de empanadas no se encuentra registrado, ingrese nuevamente.\n\n");
    }while(pos==-1 && cod!=0);

    while(cod!=0)
    {
        do{
            printf("Ingrese la CANTIDAD vendida del gusto %s: ",vec[pos].gusto);
            scanf("%d", &cant);
            if(cant<0)
                printf("\nERRROR, la cantidad debe ser mayor a cero.\n\n");
        }while(cant<0);
        vec[pos].cant_vendida += cant;
        printf("Ingrese el DIA de la venta: ");
        dia = LeerYValidar(1,7,1);
        semana[dia-1] += vec[pos].precio * cant;
        strcat(empanadaxdia[dia-1], vec[pos].gusto);
        strcat(empanadaxdia[dia-1], " ");
        do{
            printf("Ingrese la COCCION (H - Horno, F - Fritas, S - Sin coccion): ");
            fflush(stdin);
            scanf("%c", &coccion);
            coccion = toupper(coccion);
            if(coccion != 'H' && coccion!= 'F' && coccion!='S')
                printf("\nERROR, vuelva a ingresar.\n\n");
        }while(coccion != 'H' && coccion!= 'F' && coccion!='S');
        vec[pos].coccion = coccion;

        do{
            printf("Ingrese el CODIGO de empanadas (0 para finalizar): ");
            cod = LeerYValidar(100, 999, 0);
            pos = Buscar(vec, cod, i);
        if(pos==-1 && cod!=0)
            printf("\nERROR, el codigo de empanadas no se encuentra registrado, ingrese nuevamente.\n\n");
        }while(pos==-1 && cod!=0);
    }
    MostrarListado(empanadaxdia,semana,7);
    MayorVenta(vec,i);
    CantidadxCoccion(vec,i);
    return 0;
}
int LeerYValidar(int liminf, int limsup, int dif)
{
    int num;
    do{
        printf("Ingrese entre %d y %d: ", liminf, limsup);
        scanf("%d", &num);
        if((num<liminf || num>limsup) && num!=dif)
            printf("\nERROR, ingreso no valido, vuelva a ingresar.\n\n");
    }while((num<liminf || num>limsup) && num!=dif);
    return num;
}
int Buscar(sEmpanada vec[], int buscado, int cant)
{
    int i=0, pos=-1;
    while(i<cant && pos==-1)
    {
        if(vec[i].codigo == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
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
int CargarVector(sEmpanada vec[], int cantmax)
{
    int i=0, pos, cod;
    char gusto[26];
    float precio;
    printf("--REGISTRO DE DATOS--\n");
    printf("Ingrese el CODIGO de empanada (0 para finalizar carga). ");
    cod = LeerYValidar(100,999,0);
    while(cod!=0 && i<cantmax)
    {
        vec[i].codigo = cod;
        do{
            printf("Ingrese el GUSTO de empanada: ");
            IngresaTexto(gusto,26);
            if(!strcmpi(gusto, vec[i].gusto))
                printf("\nERROR, el gusto ya se encuentra registrado, ingrese otro.\n\n");
        }while(!strcmpi(gusto, vec[i].gusto));
        strcpy(vec[i].gusto, gusto);
        do{
            printf("Ingrese el PRECIO: ");
            scanf("%f", &precio);
            if(precio<0)
                printf("\nERROR, el precio debe ser mayor a 0.\n\n");
        }while(precio<0);
        vec[i].precio = precio;
        vec[i].cant_vendida = 0;

        i++;

        do{
            printf("Ingrese el CODIGO de empanada (0 para finalizar carga). ");
            cod = LeerYValidar(100,999,0);
            pos = Buscar(vec,cod,i);
            if(pos!=-1)
                printf("\nERROR, el codigo de vendedor ya fue ingresado, vuelva a ingresar uno diferente.\n\n");
            else if(pos!=-1 || cod==vec[i-1].codigo-1 || cod==vec[i-1].codigo+1)
                printf("\nERROR, no se pueden ingresar numeros correlativos.\n\n");
        }while(pos!=-1 || cod==vec[i-1].codigo-1 || cod==vec[i-1].codigo+1);
    }
    return i;
}
void MostrarListado(char string[][100], float semana[], int cant)///Punto 1)
{
    int i;
    printf("%s\t%s\t\t\t%s\n","DIA", "IMPORTE", "GUSTOS");
    for(i=0; i<cant; i++)
        printf("%d\t$%.2f\t\t%s\n", i+1, semana[i], string[i]);
}
void MayorVenta(sEmpanada vec[], int cant)///Punto 2)
{
    int i, mayor=vec[0].cant_vendida, pos, bandera;

    for(i=0; i<cant; i++)
    {
        if(vec[i].cant_vendida > mayor)
        {
            mayor = vec[i].cant_vendida;
            pos = i;
        }
    }
    printf("-El gusto con mayor ventas es %s con %d empanadas vendidas.\n-Los gustos que tuvieron la misma cantidad de ventas son: \n",vec[pos].gusto, mayor);
    for(i=0; i<cant; i++)
        if(vec[i].cant_vendida == mayor && vec[i].gusto!=vec[pos].gusto)
        {
            printf(".%s\n",vec[i].gusto);
            bandera++;
        }
    if(bandera==0)
        printf("*No hubo cantidad de ventas iguales a las empananadas de %s*", vec[pos].gusto);
}
void CantidadxCoccion(sEmpanada vec[], int cant)///Punto 3)
{
    int i;
    float horno=0, fritas=0, sin=0;
    for(i=0; i<cant; i++)
    {
        switch(vec[i].coccion)
        {
            case 'H': horno += vec[i].cant_vendida * vec[i].precio; break;
            case 'F': fritas += vec[i].cant_vendida * vec[i].precio; break;
            case 'S': fritas += vec[i].cant_vendida * vec[i].precio; break;
        }
    }
    printf("\nTotal ventas al HORNO: $%.2f", horno);
    printf("\nTotal ventas FRITAS: $%.2f", fritas);
    printf("\nTotal ventas Sin Coccion: $%.2f\n", sin);
}
