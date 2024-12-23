#include<stdio.h>

#define cantMax 5


struct art {
int codigo;
float precio;
char des[51];
};


int buscar(struct art [], int, int);
void listar(struct art [], int);

void main()
{
    struct art articulos[cantMax];
    int pos=-1, i=0;
    int cant, codigo;
    int band=0,band2=0;
    int cont=0,cont2=0;

     printf("Ingrese codigo de articulo:");
     scanf("%d", &codigo);

    while (codigo !=0 && i<cantMax)
        {band=0;
         band2=0;
        do{
            if (band2==1)
             {printf("Codigo existente.");
             printf("\nIngrese codigo de articulo:");
             scanf("%d", &codigo);}
             band2=1;

            pos=buscar(articulos,codigo,i);
            }
            while(pos!=-1);

        articulos[i].codigo=codigo;

        do{if (band==1)
            printf("Error en el ingreso de precio. Vuelva a intentar\n");
        band=1;
        printf("Ingrese Precio:");
        scanf("%f",&articulos[i].precio);
        }while(articulos[i].precio<0);

        printf("Ingrese descripcion:");
        fflush(stdin);
        gets(articulos[i].des);
        i++;

        if(i<cantMax)
       {
        printf("Ingrese codigo de articulo:");
        scanf("%d", &codigo);

       }



    }
    cant=i;

    printf("Ingrese codigo a buscar para modificar (Presione 0 para finalizar):");
    scanf("%d",&codigo);

    while (codigo!=0)
    {
         band=0;
         band2=0;
         cont2++;
         pos=-1;
        do{

        if (band2==1)
        {printf("Codigo inexistente.\n");
        cont++; cont2++;
        printf("Ingrese codigo a buscar para modificar (Presione 0 para finalizar):");;
        scanf("%d",&codigo);
        }
        else
        band2=1;
            pos=buscar(articulos,codigo,cant);

    }
        while(pos==-1);
        i=pos;
       band=0;
       do{if (band==1)
           printf("Error en el ingreso de precio. Vuelva a intentar\n");


            printf("Ingrese Precio del codigo:");
            scanf("%f",&articulos[i].precio);
            band=1;
            }while(articulos[i].precio<0);

        printf("ingrese descripcion:");
        fflush(stdin);
        gets(articulos[i].des);

        printf("Ingrese codigo de articulo:");
        scanf("%d", &codigo);

       }

    if (cont2!=0)
    printf("\n El porcentaje de codigos rechazados es: %3.2f",(float)cont/cont2);

    listar(articulos,cant);

return 0;
}



int buscar(struct art articulo [], int codigo, int cant)
{
    int i=0,pos=-1;

    while(i<cant && pos==-1)
    {
        if (articulo[i].codigo==codigo)
             pos=i;
        else
            i++;
    }
    return pos;
}


void listar(struct art articulo[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("\n Codigo:%4d descripcion:%s  precio: %4.2f ",articulo[i].codigo,articulo[i].des,articulo[i].precio);
    }
}
