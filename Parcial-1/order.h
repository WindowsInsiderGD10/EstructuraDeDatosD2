#ifndef ORDER_H
#define ORDER_H

#include "player.h"

void swapPlayers(Player *a, Player *b);

void bubbleSort(Player *table, int n, int asc);
void selectionSort(Player *table, int n, int asc);
void insertionSort(Player *table, int n, int asc);

#endif
