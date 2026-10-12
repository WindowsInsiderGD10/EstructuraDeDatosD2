#ifndef PLAYER_H
#define PLAYER_H

#define MAX_CHAR_NAME 15
#define MIN_CHAR_NAME 4

typedef struct {
  int id;
  char nick[MAX_CHAR_NAME];
  float score;
} Player;

void inputPlayer(Player *player);
void printPlayer(const Player *player);

#endif