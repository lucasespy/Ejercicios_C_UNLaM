#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct
{
    int dni, nota1, nota2;
    char nomyape[81];
    float promedio;
}sAlumno;
void IngresaTexto(sAlumno *, int);
int LeerYValidar(int, int);
void CONDICION(sAlumno);
void LECTURA(sAlumno, FILE *, char[]);
int main()
{
    sAlumno alumno;
    FILE *file, *promo, *cursa, *repro;
    int dni;
    file = fopen("ALUMNOS.dat","wb");
    if(file==NULL)
    {
        getch();
        printf("\nERROR en la apertura del archivo.\n\n");
        exit(1);
    }
    printf("Ingrese DNI del alumno: ");
    scanf("%d", &dni);
    while(dni != 0)
    {
        alumno.dni = dni;
        printf("Ingrese el NOMBRE y APELLIDO: ");
        IngresaTexto(&alumno, 81);
        printf("Ingrese la nota 1 (1 a 10): ");
        alumno.nota1 = LeerYValidar(1,10);
        printf("Ingrese la nota 2 (1 a 10): ");
        alumno.nota2 = LeerYValidar(1,10);
        alumno.promedio = (alumno.nota1 + alumno.nota2) / 2.0;
        fwrite(&alumno, sizeof(sAlumno), 1, file);
        printf("Ingrese DNI del alumno: ");
        scanf("%d", &dni);
    }
    fclose(file);
    CONDICION(alumno);

    promo = fopen("PROMOCIONADOS.dat","rb");
    cursa = fopen("CURSADOS.dat","rb");
    repro = fopen("REPROBADOS.dat","rb");
    if(promo==NULL || cursa==NULL || repro==NULL)
    {
        getch();
        printf("\nERROR en la apertura del archivo.\n\n");
        exit(1);
    }
    LECTURA(alumno, promo, "PROMOCIONADOS");
    LECTURA(alumno, cursa, "CURSADOS");
    LECTURA(alumno, repro, "REPROBADOS");
    fclose(promo);
    fclose(cursa);
    fclose(repro);
    return 0;
}
int LeerYValidar(int liminf, int limsup)
{
    int num;
    do{
        scanf("%d", &num);
        if(num<liminf || num>limsup)
            printf("\nERROR, valor no valido. Vuelva a ingresar.\n\n");
    }while(num<liminf || num>limsup);
}
void IngresaTexto(sAlumno *alumno, int cant)
{
    int i;
    fflush(stdin);
    fgets(alumno->nomyape, cant, stdin);
    i=0;
    while(alumno->nomyape[i]!='\0')
    {
        if(alumno->nomyape[i]=='\n')
            alumno->nomyape[i]='\0';
        else
            i++;
    }
}
void CONDICION(sAlumno alumno)
{
    FILE *file, *promo, *cursa, *repro;
    file = fopen("ALUMNOS.dat","rb");
    promo = fopen("PROMOCIONADOS.dat","wb");
    cursa = fopen("CURSADOS.dat","wb");
    repro = fopen("REPROBADOS.dat","wb");
    if(file==NULL || promo==NULL || cursa==NULL || repro==NULL)
    {
        getch();
        printf("\nERROR en la apertura del archivo.\n\n");
        exit(1);
    }
    fread(&alumno, sizeof(sAlumno), 1, file);
    while(!feof(file))
    {
        if(alumno.nota1>=7 && alumno.nota2>=7)
            fwrite(&alumno, sizeof(sAlumno), 1, promo);
        else if(alumno.nota1>=4 && alumno.nota2>=4)
            fwrite(&alumno, sizeof(sAlumno), 1, cursa);
        else
            fwrite(&alumno, sizeof(sAlumno), 1, repro);

        fread(&alumno, sizeof(sAlumno), 1, file);
    }
    fclose(file);
    fclose(promo);
    fclose(cursa);
    fclose(repro);
}
void LECTURA(sAlumno alumno, FILE *arch, char string[20])
{
    printf("\n--Alumnos con la condicion de %s--\n",string);
    fread(&alumno, sizeof(sAlumno), 1, arch);
    while(!feof(arch))
    {
        printf("%s\n",alumno.nomyape);
        fread(&alumno, sizeof(sAlumno), 1, arch);
    }
}


        /*printf("DNI: %d\n", alumno.dni);
        printf("Nombre y Apellido: %s\n", alumno.nomyape);
        printf("Nota 1: %d\nNota2: %d\n", alumno.nota1, alumno.nota2);
        printf("Promedio: %.2f\n", alumno.promedio);
        fread(&alumno, sizeof(sAlumno), 1, file);*/
