// ranking.c
#include <stdio.h>
#include "ranking.h"

void inicializarRanking(Ranking *ranking) {
    ranking->cantidad = 0;
}

void mostrarRanking(Ranking ranking) {
    printf("\n--- TOP 3 PUNTAJES ---\n");
    if (ranking.cantidad == 0) {
        printf("No hay puntajes registrados aún.\n");
    } else {
        for (int i = 0; i < ranking.cantidad; i++) {
            printf("%d) %s - %d puntos\n", i + 1, ranking.jugadores[i].nombre, ranking.jugadores[i].puntaje);
        }
    }
    printf("----------------------\n");
}

void actualizarRanking(Ranking *ranking, Jugador nuevoJugador) {
    // Si hay espacio en el ranking, agregar directamente
    if (ranking->cantidad < MAX_RANKING) {
        ranking->jugadores[ranking->cantidad] = nuevoJugador;
        ranking->cantidad++;
        
        // Ordenar de mayor a menor puntaje
        for (int i = 0; i < ranking->cantidad - 1; i++) {
            for (int j = i + 1; j < ranking->cantidad; j++) {
                if (ranking->jugadores[i].puntaje < ranking->jugadores[j].puntaje) {
                    Jugador temp = ranking->jugadores[i];
                    ranking->jugadores[i] = ranking->jugadores[j];
                    ranking->jugadores[j] = temp;
                }
            }
        }
    } else {
        // Si el ranking está lleno, verificar si el nuevo puntaje supera al más bajo
        int menorPuntaje = ranking->jugadores[MAX_RANKING - 1].puntaje;
        
        if (nuevoJugador.puntaje > menorPuntaje) {
            // Reemplazar el último y reordenar
            ranking->jugadores[MAX_RANKING - 1] = nuevoJugador;
            
            // Ordenar de mayor a menor puntaje
            for (int i = 0; i < MAX_RANKING - 1; i++) {
                for (int j = i + 1; j < MAX_RANKING; j++) {
                    if (ranking->jugadores[i].puntaje < ranking->jugadores[j].puntaje) {
                        Jugador temp = ranking->jugadores[i];
                        ranking->jugadores[i] = ranking->jugadores[j];
                        ranking->jugadores[j] = temp;
                    }
                }
            }
        } else {
            printf("Puntaje no suficiente para entrar al Top 3.\n");
        }
    }
}
