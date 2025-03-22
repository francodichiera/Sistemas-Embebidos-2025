#include <stdio.h>

int main() {
    int A, B;

    // Solicitar los valores de A y B
    printf("Ingresa el valor de A: ");
    scanf("%d", &A);
    printf("Ingresa el valor de B: ");
    scanf("%d", &B);

    // Calcular y mostrar la suma, la resta y el producto
    printf("Suma: %d\n", A + B);
    printf("Resta: %d\n", A - B);
    printf("Producto: %d\n", A * B);

    return 0;
}
