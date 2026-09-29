// jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H

#define MAX_NOMBRE 4 // 3 letras + null terminator

typedef struct {
    char nombre[MAX_NOMBRE];
    int puntaje;
} Jugador;

void ingresarJugador(Jugador *jugador);
void mostrarJugador(Jugador jugador);

#endif
