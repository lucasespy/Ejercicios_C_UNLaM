#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Buscar(int[], int, int);
int main()
{
    int grupos[5], i, pos;
    srand(time(NULL));

    for(i = 0; i < 5; i++)
    {
        do{
            grupos[i] = (rand() % 5) + 1;
            pos = Buscar(grupos, grupos[i], i);
        }while(pos != -1);
    }
    printf("---ORDEN DE EXPOSICION---\n");
    for(i = 0; i < 5; i++)
        printf("%d. Grupo %d\n",i+1, grupos[i]);

    return 0;
}
int Buscar(int vec[], int buscado, int cant)
{
    int i = 0, pos = -1;
    while(i < cant && pos == -1)
    {
        if(vec[i] == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}
