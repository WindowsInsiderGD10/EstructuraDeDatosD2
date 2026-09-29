// ranking.h
#ifndef RANKING_H
#define RANKING_H

#include "jugador.h"

#define MAX_RANKING 3

typedef struct {
    Jugador jugadores[MAX_RANKING];
    int cantidad;
} Ranking;

void inicializarRanking(Ranking *ranking);
void mostrarRanking(Ranking ranking);
void actualizarRanking(Ranking *ranking, Jugador nuevoJugador);

#endif
