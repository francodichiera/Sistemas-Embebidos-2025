#include <stdio.h>

#define maximo 5

struct Infraccion
{
    int tipo, multa;
    char gravedad;
};

int main()
{
    int sumaL = 0, sumaM = 0, sumaG = 0;
    int cantL = 0, cantM = 0, cantG = 0;

  
    for (int i = 0; i < maximo; i++) {
        struct Infraccion inf
        
        printf("Ingrese tipo de infraccion %d (1-4): ", i + 1);
        scanf("%d", &inf.tipo);
        
        printf("Ingrese valor de la multa %d: ", i + 1);
        scanf("%d", &inf.multa);
        
        // Limpiar el buffer antes de leer un carácter
        getchar();
        
        printf("Ingrese gravedad de la infraccion %d (L, M, G): ", i + 1);
        scanf("%c", &inf.gravedad);
        
    
        if (infraccion.gravedad == 'L') 
        {
            sumaL += infraccion.multa;
            cantL++;
        } else if (infraccion.gravedad == 'M') 
        {
            sumaM += infraccion.multa;
            cantM++;
        } else if (infraccion.gravedad == 'G') 
        {
            sumaG += infraccion.multa;
            cantG++;
        }
    }
    
    printf("Total de multas con gravedad L: %d\n", sumaL);
    printf("Total de multas con gravedad M: %d\n", sumaM);
    printf("Total de multas con gravedad G: %d\n", sumaG);
    
    // Verificamos clausurar la fábrica
    if (cantG > 3) 
    {
        printf("Clausurar fabrica\n");
    }
    
    return 0;
}
