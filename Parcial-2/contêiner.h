#ifndef CONTEINER_H
#define CONTEINER_H

/* Estructura para almacenar la información de un contenedor */
typedef struct {
    int id;             // Identificador interno único generado automáticamente
    float tara;         // Peso vacío del contenedor
    float pesoCarga;    // Peso de la carga
    float pesoTotal;    // Peso total (tara + pesoCarga)
    float custo;        // Precio o costo asociado
} Contêiner;

/* Función para imprimir los detalles de un contenedor */
void showContêiner(const Contêiner *c);

#endif
