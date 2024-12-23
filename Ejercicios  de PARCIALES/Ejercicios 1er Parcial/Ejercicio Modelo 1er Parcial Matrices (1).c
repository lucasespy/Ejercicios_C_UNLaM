/*Como resultado de un proceso eleccionario, se cuenta con los resultados finales de cada una de las mesas que participaron en
las elecciones. Al finalizar el recuento de la cantidad de votos de cada mesa, se nos entrega una planilla con los siguientes datos:

              -        Numero de Provincia (de 1 a 23)

              -        Numero de Lista (de 1 a 15)

              -        Cantidad de Votos (int)

Dichos datos, se ingresarán por teclado en forma desordenada, almacenándose en una matriz, hasta la lectura de un número
de provincia 0 (cero). Los números de provincia y de lista, se deben validar en forma separada a través de una única función con parámetros.
Confeccionar la codificación en lenguaje “C” para:

a) Informar el/los Número/s de Provincia y Número/s de Lista que finalizaron con menor cantidad de
votos, distinto de cero. Mostrar la menor cantidad de votos en una oportunidad y todas las
combinaciones (prov/lista) que finalizaron con cantidades de votos iguales al mínimo.

b) Informar las cantidades totales de votos por provincia.

c) Informar el número de lista ganadora (el mayor es único)

d) Mostrar la cantidad de votos de la lista número 12 ordenados de mayor a menor. Se debe visualizar el número de provincia y la
cantidad de votos. Para el ordenamiento utilizar una función con parámetros.
Por ej. mostraría:

                                    Lista Numero 12

                              Provincia    Cantidad de votos

                                5               98531

                                21              67574

                                8               43891

                                ..               ….

                                20              7523
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int LeerYValidar(int, int, int);
void MostrarMenosVotos(int[][15], int, int);
void MostrarVotosTotProvincias(int[][15], int, int);
void MostrarListaGanadora(int[][15], int, int);
void OrdenarMayorMenorParalelos(int[], int[], int);
void ListaDoce(int[][15], int, int);
int main()
{
    int Votos[23][15]={{0}}, prov, lista, cant=0;

    printf("--Ingreso de Provincia (0 para finalizar)--\n");
    prov = LeerYValidar(1,23,0);

    while(prov!=0)
    {
        printf("--Ingreso de numero de lista--\n");
        lista = LeerYValidar(1,15,1);
        printf("Ingrese la cantidad de votos para la lista %d en la provincia %d: ", lista, prov);
        scanf("%d", &cant);
        Votos[prov-1][lista-1] += cant;

        printf("--Ingreso de Provincia (0 para finalizar)--\n");
        prov = LeerYValidar(1,23,0);
    }
    system("cls");
    MostrarMenosVotos(Votos,23,15);
    MostrarVotosTotProvincias(Votos,23,15);
    MostrarListaGanadora(Votos,23,15);
    ListaDoce(Votos,23,15);

    return 0;
}
int LeerYValidar(int liminf, int limsup, int dif)
{
    int num;
    do{
        printf("Ingrese un numero entre %d y %d: ", liminf, limsup);
        scanf("%d", &num);
        if((num<liminf || num>limsup) && num!=dif)
            printf("\nERROR, ingreso no valido, vuelva a ingresar.\n\n");
    }while((num<liminf || num>limsup) && num!=dif);
    return num;
}
void MostrarMenosVotos(int mat[][15], int cfil, int ccol) ///Punto a)
{
    int i,j, menor_vot=mat[0][0];

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
            if(mat[i][j] < menor_vot && mat[i][j]!=0)
                menor_vot = mat[i][j];
    }
    printf("La menor cantidad de votos es %d. Y las provincias y listas que tuvieron la misma cantidad son: \n", menor_vot);

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
            if(mat[i][j] == menor_vot && mat[i][j]!=0)
                printf("Provincia %d, Lista %d\n", i+1, j+1);
    }
}
void MostrarVotosTotProvincias(int mat[][15], int cfil, int ccol) ///Punto b)
{
    int i, j, prov[23]={0};

    for(i=0; i<cfil; i++)
    {
        for(j=0; j<ccol; j++)
            prov[i] += mat[i][j];
    }
    printf("Total de votos por cada provincia: \n");
    for(i=0; i<cfil; i++)
        printf("Provincia %d: %d votos.\n",i+1, prov[i]);
}
void MostrarListaGanadora(int mat[][15], int cfil, int ccol) ///Punto c)
{
    int f, c, mayor, ganador, sumaxcol[15]={0};

    for(c=0; c<ccol; c++) // tengo que hacer una suma por columnas y acumularla en un vector de 15 posiciones
        for(f=0; f<cfil; f++)
            sumaxcol[c] += mat[f][c];

    mayor = sumaxcol[0];

    for(c=0; c<ccol; c++)
        if(sumaxcol[c] > mayor)
        {
            mayor = sumaxcol[c];
            ganador = c+1;
        }

    printf("\nLa lista GANADORA es la LISTA %d con %d votos.\n", ganador, mayor);
}
void OrdenarMayorMenorParalelos(int votos[], int prov[], int cant)
{
    int i, j, aux;

    for(i=0; i<cant-1; i++)
    {
        for(j=0; j<cant-1-i; j++)
        {
            if(votos[j] < votos[j+1])
            {
                aux = votos[j];
                votos[j] = votos[j+1];
                votos[j+1] = aux;

                aux = prov[j];
                prov[j] = prov[j+1];
                prov[j+1] = aux;
            }
        }
    }
}
void ListaDoce(int mat[][15], int cfil, int ccol)
{
    int i, j, votos[23]={0}, prov[23]={0};

    printf("\n\n\tLista 12\n");
    for(i=0; i<ccol; i++)
    {
        for(j=0; j<ccol; j++)
        {
            votos[i] = mat[i][11]; ///11 porque solo me pide datos de la lista 12 (columna 11)
        }
    }

    for(i=0; i<cfil ;i++) ///Creo un vector paralelo con el numero de cada provincia nada mas
        prov[i] = i+1;

    OrdenarMayorMenorParalelos(votos, prov, 23);

    for(i=0; i<cfil; i++)
        printf("Provincia %d, votos %d\n", prov[i], votos[i]);
}
