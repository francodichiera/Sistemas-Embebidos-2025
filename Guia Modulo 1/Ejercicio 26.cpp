#include <stdio.h>
//EJ 26 M1

#define maximo 10

int main() 
{
    struct Contenedor
    {
    int id;        // Identificaci�n del contenedor
    float peso;    // Peso del contenedor en kg
    int puerto;    // Puerto de arribo (1, 2 o 3)
    };
    
    struct Contenedor contenedores[maximo];
    
    // Variables para los c�lculos
    float peso_total = 0;
    float max_peso = 0;
    int id_max_peso = 0;
    int conteo_puertos[3] = {0, 0, 0};  // Contar contenedores por puerto
    
    for (int i = 0; i < maximo; i++) 
    {
        
        printf("Ingrese ID del contenedor %d: ", i + 1);
        scanf("%d",  &contenedores[i].id);
        
        printf("Ingrese el peso del contendor %d: ", i + 1);
        scanf("%f", &contenedores[i].peso);
        
        printf("Ingrese puerto de arribo %d (1-3): ", i + 1);
        scanf("%d", &contenedores[i].puerto);
        
        // Sumar el peso total
        peso_total += contenedores[i].peso;

        // Encontrar el contenedor con el mayor peso
        if (contenedores[i].peso > max_peso) {
            max_peso = contenedores[i].peso;
            id_max_peso = contenedores[i].id;
        }

        // Contabilizar los contenedores por puerto
        if (contenedores[i].puerto >= 1 && contenedores[i].puerto <= 3) {
            conteo_puertos[contenedores[i].puerto - 1]++;
        }
    }

    
    printf("\nResultados:\n");
    printf("1) Peso total a trasladar: %.2f kg\n", peso_total);
    printf("2) Contenedor de mayor peso: %d\n", id_max_peso);
    printf("3) Contenedores por puerto:\n");
    printf("Puerto 1: %d\n", conteo_puertos[0]);
    printf("Puerto 2: %d\n", conteo_puertos[1]);
    printf("Puerto 3: %d\n", conteo_puertos[2]);

    return 0;
}
 