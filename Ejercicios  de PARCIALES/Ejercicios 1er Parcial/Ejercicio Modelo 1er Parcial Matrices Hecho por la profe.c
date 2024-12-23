#include <stdio.h>

#define cantlista 15
#define cantprov 23

int validar(int,int);
void ordenar(int[],int[],int);

int main(){
    int m_votos[cantprov][cantlista]={{0}}, prov, vot_prov[cantprov]={0},vot_lista[cantprov]={0}, lista, votos,i,j,min,ganador, aux, vot12_pro[cantprov]={0},vot12_total[cantprov]={0};
    int max=0;
    int band=0;

    printf("Ingrese numero de provincia: ");
    prov=validar(0,23);

    while(prov!=0){
        printf("Ingrese numero de lista: ");
        lista = validar(1,15);

        printf("Ingrese cantidad de votos: ");
        do{
            scanf("%d", &votos);
        }while(votos<0);
        m_votos[prov-1][lista-1]+=votos;
        vot_prov[prov-1]+=votos;
        vot_lista[lista-1]+=votos;
        printf("Ingrese numero de provincia: ");
        prov=validar(0,23);
    }

    for(i=0;i<cantprov;i++){
        for(j=0;j<cantlista;j++){

            if(((i==0 && j==0) || m_votos[i][j]<min) && (m_votos[i][j]!=0))
                {band=1;
                min=m_votos[i][j];
                }


                  }
    }
    if (band==1)
        {printf("La menor cantidad de votos fue: %d\nProv\tLista\n", min);

    for(i=0;i<cantprov;i++){
        for(j=0;j<cantlista;j++){
                if(m_votos[i][j]==min){
                        printf("%-4d\t%-5d\n",i+1,j+1);
                }
        }
    }
        }
        else
            printf ("No se ingresaron votos\n");

    printf("Votos por provincia\n");
    for(i=0;i<cantprov;i++){
        printf("Prov\tVotos\n%-4d\t%-5d\n",i+1,vot_prov[i]);
    }

    band=0;

    for(i=0;i<cantlista;i++){

        if ((i==0 || vot_lista[i]>max) && (vot_lista[i]!=0)){
           band=1;
            ganador=i+1;
            max=vot_lista[i];
        }
    }
    if (band==1)
        printf("La lista ganadora fue %d! con %d\n",ganador,max);
    else
        printf("\nNo se registraron datos\n");


    for(j=0;j<cantprov;j++)
            {vot12_pro[j]=j+1;
             vot12_total[j]=m_votos[j][11];
            }
       ordenar(vot12_pro,vot12_total,cantprov);



return 1;}

int validar(int min, int max){
    int n;
    scanf("%d", &n);
    while(n<min || n>max){
        printf("Valor invalido\nIngrese otro: ");
        scanf("%d", &n);
    }

    return n;
}

void ordenar(int prov [],int votos [],int cant)
{

int i,j,aux,aux2;



 for (i=0;i<cant-1;i++)
 {
    for(j=0;j<(cant-1)-i;j++)
        {
            if(votos[j]<votos[j+1]){

                aux=votos[j];
                votos[j]=votos[j+1];
                votos[j+1]=aux;
                aux2=prov[j];
                prov[j]=prov[j+1];
                prov[j+1]=aux2;

            }
        }
    }
printf("Lista Numero 12 \nProv\t Votos\n");
for(j=0;j<cant;j++)
{
     printf("%d \t %d \n",prov[j],votos[j]);
    }

}-
