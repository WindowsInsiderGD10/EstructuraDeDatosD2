#include <stdio.h>
#include <stdlib.h>
#include "contêiner.h"
#include "list.h"

int main(void) {
    Nodo *lista = NULL;
    int proximoId = 1; // Generador automático de ID único
    int opcion;

    do {
        printf("\n==================================================\n");
        printf("   ADMINISTRACION DE CONTENEDORES - SPB\n");
        printf("==================================================\n");
        printf("1. Registrar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar informacion de contenedor\n");
        printf("4. Retirar contenedor\n");
        printf("5. Recorrer ubicaciones de los contenedores\n");
        printf("0. Salir del sistema\n");
        printf("--------------------------------------------------\n");
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("\n>> Opción inválida. Ingrese una opcion numérica valida.\n");
            continue;
        }

        switch (opcion) {
            case 1: {
                Contêiner c;
                c.id = proximoId++;

                printf("\n--- Registro de Nuevo Contenedor ---\n");
                printf("Se le asignará la ID %d al nuevo contenedor.\n", c.id);
                printf("Ingrese el peso vacio (Tara) en kg: ");
                scanf("%f", &c.tara);

                printf("Ingrese el peso de la carga en kg: ");
                scanf("%f", &c.pesoCarga);

                c.pesoTotal = c.tara + c.pesoCarga;
                printf("El peso total (calculado automáticamente) es de: %.2f kg.\n", c.pesoTotal);

                printf("Ingrese el precio o costo asociado: ");
                scanf("%f", &c.custo);

                inserirContêiner(&lista, c);
                break;
            }

            case 2: {
                int idBusqueda;
                printf("\n--- Búsqueda de Contenedor ---\n");
                printf("Ingrese el ID del contenedor a buscar: ");
                scanf("%d", &idBusqueda);

                Nodo *encontrado = buscarContêiner(lista, idBusqueda);
                if (encontrado != NULL) {
                    printf("\n>> Contenedor localizado con exito en la ubicación:\n");
                    showContêiner(&(encontrado->dato));
                } else {
                    printf(">> El ID %d no coincide con ningun contenedor registrado.\n", idBusqueda);
                }
                break;
            }

            case 3: {
                int idActualizar;
                printf("\n--- Actualizacion de Informacion ---\n");
                printf("Ingrese el ID del contenedor a actualizar: ");
                scanf("%d", &idActualizar);

                Nodo *encontrado = buscarContêiner(lista, idActualizar);
                if (encontrado == NULL) {
                    printf(">> El ID %d no coincide con ningun contenedor registrado.\n", idActualizar);
                } else {
                    printf("\nDatos actuales del contenedor:\n");
                    showContêiner(&(encontrado->dato));

                    float novaTara, novoPesoCarga, novoCusto;
                    printf("Ingrese la nueva tara: ");
                    scanf("%f", &novaTara);

                    printf("Ingrese el nuevo peso de carga: ");
                    scanf("%f", &novoPesoCarga);

                    printf("Ingrese el nuevo costo asociado: ");
                    scanf("%f", &novoCusto);

                    atualizarContêiner(lista, idActualizar, novaTara, novoPesoCarga, novoCusto);
                    printf(">> Información del contenedor con ID %d actualizada correctamente.\n", idActualizar);

                    printf("\nDatos actualizados:\n");
                    showContêiner(&(encontrado->dato));
                }
                break;
            }

            case 4: {
                int idEliminar;
                printf("\n--- Retiro / Eliminacion de Contenedor ---\n");
                printf("Ingrese el ID del contenedor que finaliza transito: ");
                scanf("%d", &idEliminar);

                if (removerContêiner(&lista, idEliminar)) {
                    printf(">> El contenedor con ID %d ha sido retirado y la memoria ha sido liberada exitosamente.\n", idEliminar);
                } else {
                    printf(">> No se pudo retirar: El contenedor con ID %d no fue encontrado o no existe.\n", idEliminar);
                }
                break;
            }

            case 5: {
                int sentido;
                printf("\n--- Recorrido de Contenedores ---\n");
                printf("1. Desde el principio\n");
                printf("2. Desde el final\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &sentido);

                switch (sentido) {
                    case 1:
                        percorrerParaFrente(lista);
                        break;
                    case 2:
                        percorrerParaTras(lista);
                        break;
                    default:
                        printf("Opcion de recorrido invalida.\n");
                        break;
                }
                break;
            }

            case 0:
                printf("\nLiberando recursos de memoria y saliendo del sistema...\n");
                liberarLista(&lista);
                printf("Programa finalizado exitosamente.\n");
                break;

            default:
                printf("Opción inválida. Por favor seleccione una opción del menú (0-5).\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}
