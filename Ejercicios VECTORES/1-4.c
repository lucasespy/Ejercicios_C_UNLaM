/*Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
*/
#include<stdio.h>
int IngresarDNI(int[],int);
int IngresarNota(int , int);
int Buscar(int [], int, int);
void OrdenarMayorMenor(int[], int[], int);
void MostrarListadoOrdenado(int[], int[], int);

int main()
{
    int DNI[60], Nota[60];
    int doc,calif,cant=0;
    int i=0;

    doc = IngresarDNI(DNI,i+1);
    while(doc>=0 && i<60)
    {
        DNI[i] = doc;
        calif = IngresarNota(1,10);
        Nota[i] = calif;
        i++;
        cant = i;
        doc = IngresarDNI(DNI,i+1);
    }
    MostrarListadoOrdenado(DNI, Nota, cant);

    return 0;
}
int IngresarDNI(int vecdni[],int cant)
{
    int dni,error,pos;
    do{
        error=0;
        printf("Ingrese el DNI del alumno: ");
        scanf("%d",&dni);
        pos = Buscar(vecdni, dni, cant);
        if(pos!=-1)
        {
            error=1;
            printf("\n*DNI DUPLICADO, vuelva a ingresar*\n\n");
        }
    }while(error);
    return dni;
}
int IngresarNota(int liminf, int limsup)
{
    int nota,error;
    do{
        error=0;
        printf("Ingrese la nota del alumno (1 a 10): ");
        scanf("%d",&nota);
        if(nota<liminf || nota>limsup)
        {
            error=1;
            printf("\n*Nota no valida, vuelva a ingresar*\n\n");
        }
    }while(error);
    return nota;
}
int Buscar(int vec[], int buscado, int cant)
{
    int i,pos=-1;
    while(i<cant && pos==-1)
    {
        if(vec[i]==buscado)
        {
            pos = i;
        }
        else
            i++;
    }
    return pos;
}
void OrdenarMayorMenor(int vecdni[], int vecnotas[], int cantalumnos)
{
    int i, j, aux;
    for(i = 0; i < cantalumnos-1; i++)
    {
        for(j = 0; j < cantalumnos-1-i; j++)
        {
            if(vecnotas[j] < vecnotas[j+1])
            {
                aux = vecnotas[j];
                vecnotas[j] = vecnotas[j+1];
                vecnotas[j+1] = aux;

                aux = vecdni[j];
                vecdni[j] = vecdni[j+1];
                vecdni[j+1] = aux;
            }
        }
    }
}
void MostrarListadoOrdenado(int vecdni[], int vecnotas[], int cant)
{
    int i;
    OrdenarMayorMenor(vecdni, vecnotas, cant);
    printf("\n%s%20s\n","DNI", "NOTAS");
    printf("-------------------------\n");
    for(i = 0; i < cant; i++)
        printf("%d%15d\n",vecdni[i], vecnotas[i]);
}
