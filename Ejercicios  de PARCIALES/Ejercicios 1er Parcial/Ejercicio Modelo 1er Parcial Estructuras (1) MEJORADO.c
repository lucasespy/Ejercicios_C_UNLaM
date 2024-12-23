/*Se desea realizar un programa en lenguaje C que permita actualizar el precio y/o modificar la descripción de un producto en forma individual.

 La empresa trabaja con 200 productos con la siguiente estructura:
Código (entero)
Precio (float)
Descripción (de hasta 50 caracteres)
Se solicita Ingresar dichos datos en un vector de estructuras.
Luego se ingresarán por teclado códigos de productos, de los cuales se quiere modificar algún dato o ambos hasta ingresar un código cero.
En caso de existir el código en el vector, se consultará que dato quiere modificar.  Si es el precio, se ingresará el nuevo importe
validando que sea mayor a cero, lo mismo si desea cambiar la descripción, se ingresará la nueva cadena validando que no supere los 50 caracteres.
Adicionalmente se solicita informar el porcentaje de códigos rechazados. Se lo considera rechazado cuando el código a buscar no existe en el vector.
 Para la búsqueda del código en el vector de estructuras, utilizar una función.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    int cod;
    float precio;
    char desc[51];
}sProducto;
void IngresaTexto(char[], int);
int Buscar(sProducto [], int, int);
int CargarVector(sProducto [], int);
void MostrarProductos(sProducto [], int);
int main()
{
    sProducto vec[200];
    int codigo, pos, error, cant_rechazados=0, i;
    float precio;
    char string[51], dato;

    i = CargarVector(vec,200);
    MostrarProductos(vec,i);

    printf("Ingrese el codigo del producto que desea modificar: ");
    scanf("%d", &codigo);
    pos = Buscar(vec, codigo, i);
    if(pos==-1)
        cant_rechazados++;

    while(codigo != 0 && pos!=-1)
    {
        printf("Que que dato desea modificar?\nIngrese 'P' para precio o 'D' para descripcion: ");
        fflush(stdin);
        scanf("%c", &dato);
        dato = toupper(dato);
        while((dato=='P' || dato=='D') && dato!='N')
        {
            if(dato=='P')
            {
                printf("--Selecciono modificar precio--\n");
                do{
                    printf("Ingrese el nuevo precio (mayor a cero): ");
                    scanf("%f", &precio);
                    if(precio<0)
                        printf("\nError, el precio debe ser mayor a cero\n");
                }while(precio<0);
                vec[pos].precio = precio;
            }
            else if(dato=='D')
            {
                printf("--Selecciono modificar Descripcion--\n");
                printf("Ingrese la nueva descripcion (max 50 caracteres): ");
                IngresaTexto(string, 50);
                strcpy(vec[pos].desc,string);
            }
                printf("Desea modificar otro dato?\nIngrese 'P' para precio o 'D' para descripcion o 'N' para no modificar mas datos: ");
                fflush(stdin);
                scanf("%c", &dato);
                dato = toupper(dato);
        }
        printf("Ingrese el codigo del producto que desea modificar: ");
        scanf("%d", &codigo);
        pos = Buscar(vec, codigo, i);
        if(pos==-1)
            cant_rechazados++;
    }
    MostrarProductos(vec,i);
    printf("La cantidad de codigos rechazados es: %d", cant_rechazados);

    return 0;
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
        else
            i++;
    }
}
int Buscar(sProducto vec[], int buscado, int cant)
{
    int i=0, pos=-1;
    while(i<cant && pos==-1)
    {
        if(vec[i].cod == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}
int CargarVector(sProducto vec[], int cantmax)
{
    int i=0, cod;
    float precio;
    char descripcion[51];

    printf("Ingrese el codigo para el producto %d: ", i+1);
    scanf("%d", &cod);

    while(cod!=0 && i<cantmax)
    {
        vec[i].cod = cod;
        printf("Ingrese la descripcion para el producto con codigo %d: ", cod);
        IngresaTexto(descripcion,51);
        strcpy(vec[i].desc,descripcion);
        do{
            printf("Ingrese el precio para el producto con codigo %d: ", cod);
            scanf("%f", &precio);
            if(precio<0)
                printf("\nERROR, el precio debe ser mayor a cero (0), vuelva a ingresar\n\n");
        }while(precio<0);
        vec[i].precio = precio;
        i++;
        printf("Ingrese el codigo para el producto %d: ", i+1);
        scanf("%d", &cod);
    }
    return i;
}
void MostrarProductos(sProducto vec[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
        printf("%d. Codigo: %d\n   Precio: $%.2f\n   Descripcion: %s\n\n",i+1, vec[i].cod, vec[i].precio, vec[i].desc);
}
