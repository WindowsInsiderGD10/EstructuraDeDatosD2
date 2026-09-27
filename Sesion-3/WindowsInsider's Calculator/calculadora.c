#include <stdio.h>
#include "aritmetica.h"

int main(void)
{
    double a, b;
    double resultado = 0;
    int opcion;


    do {
        printf("\n--- WindowsInsider's Calculator ---\n");
        printf("\n");
        printf("1) Suma\n2) Resta\n3) Multiplicación\n4) División\n");
        printf("5) Ver último resultado\n0) Salir del programa\n");
        printf("\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: case 2: case 3: case 4:
                printf("Ingrese el primer número: ");
                scanf("%lf", &a);
                printf("Ingrese el segundo número: ");
                scanf("%lf", &b);
                break;
        }

        switch (opcion) {
            case 1:
                resultado = sumar(a, b);
                printf("%g + %g = %g\n", a, b, resultado);
                break;

            case 2:
                resultado = restar(a, b);
                printf("%g - %g = %g\n", a, b, resultado);
                break;

            case 3:
                resultado = multiplicar(a, b);
                printf("%g x %g = %g\n", a, b, resultado);
                break;

            case 4:
                if (b == 0) {
                    printf("¿Cómo carajos se te ocurre dividir entre 0?\n");
                    printf("Ahora te toca empezar de nuevo XD");
                }

                else {
                    resultado = dividir(a, b);
                    printf("%g / %g = %g\n", a, b, resultado);
                }
                break;

            case 5:
                printf("Tu último resultado fue: %g\n", resultado);
                break;

            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("¿Tú no lees we? !DEL 1 AL 5 SON LAS OPCIONES!\n");
                printf("Se vale pensar we");
                break;
        }


    } while (opcion != 0);
    return 0;
}
