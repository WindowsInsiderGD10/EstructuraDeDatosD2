// jugador.c
#include <stdio.h>
#include <string.h>
#include "jugador.h"

void ingresarJugador(Jugador *jugador) {
    printf("Ingresa las 3 iniciales del jugador: ");
    scanf("%3s", jugador->nombre);
    
    printf("Ingresa el puntaje: ");
    scanf("%d", &jugador->puntaje);
}

void mostrarJugador(Jugador jugador) {
    printf("Jugador: %s | Puntaje: %d\n", jugador.nombre, jugador.puntaje);
}
