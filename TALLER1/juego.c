// juego.c
#include <stdio.h>
#include "jugador.h"
#include "ranking.h"

int main(void) {
    Ranking ranking;
    Jugador jugadorActual;
    int opcion;
    
    inicializarRanking(&ranking);
    
    do {
        printf("\n--- GTA VI RANKING SYSTEM ---\n");
        printf("\n");
        printf("1) Registrar nuevo puntaje\n");
        printf("2) Ver Top 3\n");
        printf("0) Salir\n");
        printf("\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                ingresarJugador(&jugadorActual);
                actualizarRanking(&ranking, jugadorActual);
                break;
                
            case 2:
                mostrarRanking(ranking);
                break;
                
            case 0:
                printf("Saliendo del sistema...\n");
                break;
                
            default:
                printf("¿Tú no lees we? !DEL 0 AL 2 SON LAS OPCIONES!\n");
                printf("Se vale pensar we\n");
                break;
        }
    } while (opcion != 0);
    
    return 0;
}
