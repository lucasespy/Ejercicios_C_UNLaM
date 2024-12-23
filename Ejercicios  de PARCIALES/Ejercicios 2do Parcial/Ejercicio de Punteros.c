/*a) Si tiene la siguiente función de nombre inter, que cambios realizaría en la misma para que intercambie los valores de x e y?.
Ejemplo, recibe x= 8 e y= 1 y debe retornar x=1 e y = 8
void inter(int x, int y )
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

b) Que imprime el siguiente segmento de programa?
int main ()
{
    float n = 3.6;
    float *ptr = &n;
    n = 2.8;
    printf(“El valor de ptr es %f\n”, *ptr);
    return 0;
}

a) Que imprime el siguiente segmento de programa?
int main()
{
    int a,b, c, *p1, *p2;
    p1 = &a; *p1 = 1;
    p2 = &b; *p2 = 2;
    p1 = p2; *p1 = 0;
    p2 = &c; *p2 = 3;
    printf("%d %d %d\n", a, b, c);
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    float n = 3.6;
    float *ptr = &n;
    n = 2.8;
    printf("El valor de ptr es: %f\n", *ptr);

    int a, b, c, *p1, *p2;
    p1 = &a; *p1 = 1;
    p2 = &b; *p2 = 2;
    p1 = p2; *p1 = 0;
    p2 = &c; *p2 = 3;
    printf("%d %d %d\n", a, b, c);

    return 0;
}
