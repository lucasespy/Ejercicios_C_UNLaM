#include<stdio.h>
#include<time.h>
void CargaAleatoriaVector(int[], int, int);
void MostrarVector(int[], int);
void MostrarMenor(int[], int);
void MostrarMayor(int[],int);
int main()
{
    int vec[20];

    CargaAleatoriaVector(vec, 1000, 20);

    MostrarVector(vec, 20);

    MostrarMenor(vec, 20);

    MostrarMayor(vec, 20);

    return 0;
}
void CargaAleatoriaVector(int vec[], int max, int cant) //Carga el vector con numeros pseudo-aleatorios
{
    int i;
    srand(time(NULL));
    for(i = 0; i < cant; i++)
    {
        do{
            vec[i] = rand() % max;
        }while(vec[i] < 100);
    }
}

void MostrarVector(int vec[], int cant) //Muestra lo que hay en cada posicion del vector
{
    int i;
    for(i = 0; i<cant; i++)
        printf("%d. %d\n",i + 1, vec[i]);
}

void MostrarMenor(int vec[], int cant) //Punto a)Mostrar el menor valor e indicar cuantas veces se repite
{
    int i, menor = vec[0], repite = 0;

    for(i = 0; i < cant; i++) //Busca el menor valor y lo copia en la variable menor
        if(vec[i] < menor)
            menor = vec[i];

    for(i = 0; i < cant; i++) //Cuenta la cantidad de veces que se repite en el vector
        if(vec[i] == menor)
            repite++;

    printf("El menor valor es '%d' y se repite %d vez/veces.\n",menor,repite);
}

void MostrarMayor(int vec[], int cant) //Punto b)Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
{
    int i, mayor = vec[0], pos;

    for(i = 0; i < cant; i++) //Busca el mayor valor y lo copia en la variable mayor
        if(vec[i] > mayor)
            mayor = vec[i];

    printf("El mayor valor es '%d' y se encuentra en las siguientes posiciones dentro del vector: ",mayor);
    for(i = 0; i < cant; i++) //Imprime por pantalla todas las pociones donde se encuentra el mayor dentro del vector
        if(vec[i] == mayor)
            printf("%d ",i+1);
}
