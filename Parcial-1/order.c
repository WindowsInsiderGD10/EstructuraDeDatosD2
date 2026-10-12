#include "order.h"
#include "player.h"
#include <stdio.h>
#include <unistd.h> // usleep

#define STEP_DELAY 500000 // 0.5 segundos entre pasos

// Imprime el estado actual de la tabla con número de paso
static void printStep(const Player *table, int n, int paso) {
  printf("\n--- [Paso %d] ---\n", paso);
  for (int i = 0; i < n; i++) {
    printPlayer(&table[i]);
  }
  usleep(STEP_DELAY);
}

void swapPlayers(Player *a, Player *b) {
  Player temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(Player *table, int n, int asc) {
  int paso = 1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (asc ? (table[j].score > table[j + 1].score)
              : (table[j].score < table[j + 1].score)) {
        swapPlayers(&table[j], &table[j + 1]);
        printStep(table, n, paso++);
      }
    }
  }
}

void selectionSort(Player *table, int n, int asc) {
  int paso = 1;
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (asc ? (table[j].score < table[min_idx].score)
              : (table[j].score > table[min_idx].score)) {
        min_idx = j;
      }
    }
    swapPlayers(&table[min_idx], &table[i]);
    printStep(table, n, paso++); // Un paso por cada posición fijada
  }
}

void insertionSort(Player *table, int n, int asc) {
  int paso = 1;
  for (int i = 1; i < n; i++) {
    Player key = table[i];
    int j = i - 1;

    while (j >= 0 && (asc ? (table[j].score > key.score)
                          : (table[j].score < key.score))) {
      table[j + 1] = table[j];
      j = j - 1;
    }
    table[j + 1] = key;
    printStep(table, n, paso++); // Un paso por cada elemento insertado
  }
}

