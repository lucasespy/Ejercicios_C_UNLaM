#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int num1, num2, *p1, *p2;

    printf("Ingrese num1: ");
    scanf("%d", &num1);
    printf("Ingrese num2: ");
    scanf("%d", &num2);

    p1 = &num1;
    p2 = &num2;

    printf("La suma entre %d y %d es: %d", *p1, *p2, *p1+*p2);

    return 0;
}
