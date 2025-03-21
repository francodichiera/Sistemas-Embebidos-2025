#include <stdio.h>

#define maximo 5

int main()
{
	int a, suma=0, mayores100=0, sumamayores100=0, num[maximo];
	float prom;
	
	for(a=0; a<maximo; a++)
	{
		printf("Ingrese (numero %d):", a+1);
		scanf("%d", &num[a]);
		
			if (num[a]>100)
		{   
		    mayores100++;
		    sumamayores100+=num[a];
		    
		}
		if (num[a]<-10)
		{
		    suma+=num[a];
		}
	
	}
	
    prom=(float) sumamayores100/mayores100;	
	printf("El promedio de todos los numeros mayores a 100: %f\n", prom);
    printf("La suma de todos los numeros menores a -10: %d\n",suma);
    
	
    return 0;
}
