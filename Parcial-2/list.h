#ifndef LIST_H
#define LIST_H

#include "contêiner.h"

/* Estructura del nodo para la lista doblemente enlazada */
typedef struct Nodo {
    Contêiner dato;
    struct Nodo *ant;
    struct Nodo *sig;
} Nodo;

/* Funciones requeridas para la gestión de la lista bidireccional */
void inserirContêiner(Nodo **cab, Contêiner novoDado);
Nodo* buscarContêiner(Nodo *cab, int id);
int atualizarContêiner(Nodo *cab, int id, float novaTara, float novoPesoCarga, float novoCusto);
int removerContêiner(Nodo **cab, int id);

/* Recorridos bidireccionales */
void percorrerParaFrente(Nodo *cab);
void percorrerParaTras(Nodo *cab);

/* Liberación de memoria */
void liberarLista(Nodo **cab);

#endif
