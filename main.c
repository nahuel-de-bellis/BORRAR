#include <stdio.h>
#include <stdlib.h>


int main()
{
    int codCliente[10], cod, venta, cant;
    int ventaMensual[10];
    int cantTotal[10];
    int mayores500[10];
    int i, c = 0;

    for(i = 0; i < 10;i++)
    {
        scanf("%d", &codCliente[i]);
        scanf("%d", &ventaMensual[i]);
        scanf("%d", &cantTotal[i]);

        if(cantTotal[i] > 500)
        {
            mayores500[c] = codCliente[i];
            c++;
        }


    }

    if(c)
    {
        printf("Los codigos de los que vendieron mas de 500 son: \n");
        for(i = 0; i < c; i++)          printf("%d \n", mayores500[i]);
    }
    else{
        printf("Nadie vendio mas de 500 articulos");
    }
    ///ORDENAMIENTO
    int k = 1, aux;
    while(k)
    {
        k = 0;
        for(i = 0; i < 10; i++)
        {
            if(codCliente[i+1] < codCliente[i])
            {
                aux = codCliente[i+1];
                codCliente[i+1] = codCliente[i];
                codCliente[i] = aux;//Para que subo este proyecto Dios 

                aux = ventaMensual[i+1];
                ventaMensual[i+1] = ventaMensual[i];
                ventaMensual[i] = aux;

                aux = cantTotal[i+1];
                cantTotal[i+1] = cantTotal[i];
                cantTotal[i] = aux;

                k = 1;
            }

        }
    }
    printf("\t \t \t \t LUEGO DEL ORDENAMIENTO \n");
    for(i = 0; i < 10; i ++)
    {
        printf("%d ",codCliente[i]);
        printf("%d ", ventaMensual[i]);
        printf("%d \n", cantTotal[i]);
    }


    scanf("%d", &cod);
     while(cod != 0){
            scanf("%d", &venta);
            scanf("%d", &cant);

            /**BUSQUEDA BINARIA*/
            int inicio = 0, fin = 10;
            int medio = 0;

            while(fin-inicio >= 1)
            {
                medio = (inicio+fin)/2;

                if(codCliente[medio] < cod)
                {
                    inicio = medio;
                }

                else if(codCliente[medio] > cod)
                {
                    fin = medio;
                }

                else if(codCliente[medio] == cod)
                {
                    ventaMensual[medio] = venta;
                    cantTotal[medio] = cant;
                    break;
                }
                else {printf("NO SE ENCUENTRA");    break;}
            }
            printf("\t \t \t \tACTUALIZADO \n");
            printf("codigo: %d mensual: %d, cantidad Total: %d",codCliente[medio], ventaMensual[medio], cantTotal[medio]);

            scanf("%d", &cod);

        }
    return 0;
}
