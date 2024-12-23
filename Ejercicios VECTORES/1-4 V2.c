#include<stdio.h>
#include<stdlib.h>
int Buscar(int[], int, int);
int IngresaDNI(int[], int);
int IngresoDatos(int[], int[], int);
void OrdenBurbujeoOptimizado(int[], int[], int);
void MostrarListadoOrdenado(int[], int[], int);
int main()
{
    int dni[60], notas[60], cantidad;

    cantidad = IngresoDatos(dni, notas, 60);
    MostrarListadoOrdenado(dni, notas, cantidad);

    return 0;
}
int Buscar(int vec[], int buscado, int cant)
{
    int i = 0, pos = -1;
    while(i<cant && pos==-1)
    {
        if(vec[i] == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}
int IngresaDNI(int vecdni[], int cant)
{
    int dni, pos;
    do{
        printf("Ingrese el DNI del alumno %d: ",cant+1);
        scanf("%d", &dni);
        pos = Buscar(vecdni, dni, cant);
        if(pos!=-1)
            printf("\nERROR, DNI ya cargado, ingrese otro.\n\n");
    }while(pos!=-1);
    return dni;
}
int IngresoDatos(int vecdni[], int vecnotas[], int cantmaxima)
{
    int i=0, dni, nota, pos;

    dni = IngresaDNI(vecdni, i);
    while(dni>=0 && i<cantmaxima)
    {
        vecdni[i] = dni;
        do{
            printf("Ingrese la nota del alumno con DNI -%d-: ", vecdni[i]);
            scanf("%d", &nota);
            if(nota<1 || nota>10)
                printf("\nERROR, ingrese una nota entre 1 y 10.\n\n");
        }while(nota<1 || nota>10);
        vecnotas[i] = nota;
        i++;
        dni = IngresaDNI(vecdni, i);
    }
    return i;
}
void OrdenBurbujeoOptimizado(int vecdni[], int vecnota[], int cant)
{
    int i, desordenado, aux1, aux2, limite = cant-1;
    do{
        desordenado = 0;
        for(i=0; i<limite; i++)
        {
            if(vecnota[i] < vecnota[i+1])
            {
                aux1 = vecnota[i];
                vecnota[i] = vecnota[i+1];
                vecnota[i+1] = aux1;

                aux2 = vecdni[i];
                vecdni[i] = vecdni[i+1];
                vecdni[i+1] = aux2;
            }
        }
        limite = desordenado;
    }while(desordenado);
}
void MostrarListadoOrdenado(int vecdni[], int vecnota[], int cant)
{
    int i;
    OrdenBurbujeoOptimizado(vecdni, vecnota, cant);
    printf("%s%20s\n--------------------------\n", "DNI","NOTA");
    for(i=0; i<cant; i++)
        printf("%d%15d\n",vecdni[i], vecnota[i]);
}
