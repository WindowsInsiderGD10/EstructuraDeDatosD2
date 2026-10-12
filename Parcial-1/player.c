#include "player.h"
#include <stdio.h>

void inputPlayer(Player *player) {
  printf("Ingrese ID: ");
  scanf("%d", &player->id);

  printf("Ingrese nickname (max %d caracteres): ", MAX_CHAR_NAME - 1);
  scanf("%14s", player->nick);

  printf("Ingrese puntaje: ");
  scanf("%f", &player->score);
}

void printPlayer(const Player *player) {
  printf("ID: %d | Nick: %s | Score: %.2f\n", player->id, player->nick,
         player->score);
}