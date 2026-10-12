#include "order.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  printf("Ingrese la cantidad de jugadores: ");
  scanf("%d", &n);

  Player *table = (Player *)malloc(n * sizeof(Player));

  if (table == NULL) {
    printf("Error: Memoria insuficiente.\n");
    return 1;
  }

  int opt;
  do {
    printf("\n--- WindowsInsider's Ranking ---\n");
    printf("1. Ingresar jugadores\n");
    printf("2. Mostrar la tabla\n");
    printf("3. Ordenar tabla\n");
    printf("0. Salir\n");
    printf("Seleccione su opción:\n");
    scanf("%d", &opt);

    switch (opt) {
    case 1:
      for (int i = 0; i < n; i++) {
        printf("\n--- Jugador %d ---\n", i + 1);
        inputPlayer(&table[i]);
      }
      break;

    case 2:
      printf("\n--- Tabla Principal ---\n");
      for (int i = 0; i < n; i++) {
        printPlayer(&table[i]);
      }
      break;

    case 3:
      printf("\n--- Submenú - Ordenamiento ---\n");
      printf("\n¿Cómo desea ordenar su tabla? (Seleccione una opción)\n");
      printf("1. Bubble Sort\n");
      printf("2. Selection Sort\n");
      printf("3. Insertion Sort\n");

      int opt2;
      scanf("%d", &opt2);

      printf("1. Ascendente\n");
      printf("2. Descendente\n");
      printf("Seleccione el orden:\n");

      int order;
      scanf("%d", &order);

      printf("\n--- Antes del ordenamiento ---\n");
      for (int i = 0; i < n; i++)
        printPlayer(&table[i]);

      switch (opt2) {
      case 1:
        bubbleSort(table, n, order == 1);
        break;
      case 2:
        selectionSort(table, n, order == 1);
        break;
      case 3:
        insertionSort(table, n, order == 1);
        break;
      default:
        printf("Pero... Joder, ni pa que discutir contigo.\n");
        printf("¿Es tan dificil poner una opción DE LAS QUE YA ESTÁN AHÍ?\n");
        printf("Ahora hazlo de nuevo, PERO SELECCIONA BIEN.\n");
        break;
      }

      printf("\n--- Después del ordenamiento ---\n");
      for (int i = 0; i < n; i++)
        printPlayer(&table[i]);

      break;

    case 0:
      printf("Saliendo del programa...\n");
      break;

    default:
      printf("Pero... Joder, ni pa que discutir contigo.\n");
      printf("¿Es tan dificil poner una opción DE LAS QUE YA ESTÁN AHÍ?");
      printf("Ahora hazlo de nuevo, PERO SELECCIONA BIEN.\n");
    }
  } while (opt != 0);

  free(table);
  return 0;
}