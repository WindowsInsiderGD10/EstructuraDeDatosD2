#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* Inserción al final de la lista doblemente enlazada */
void inserirContêiner(Nodo **cab, Contêiner novoDado) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));

    novo->dato = novoDado;
    novo->sig = NULL;
    novo->ant = NULL;

    if (*cab == NULL) {
        *cab = novo;
    } else {
        Nodo *atual = *cab;
        while (atual->sig != NULL) {
            atual = atual->sig;
        }
        atual->sig = novo;
        novo->ant = atual;
    }
    printf(">> Contenedor registrado exitosamente con ID: %d\n", novoDado.id);
}

/* Búsqueda secuencial de un contenedor por su ID */
Nodo* buscarContêiner(Nodo *cab, int id) {
    Nodo *atual = cab;
    while (atual != NULL) {
        if (atual->dato.id == id) {
            return atual;
        }
        atual = atual->sig;
    }
    return NULL;
}

/* Modificación de la información numérica de un contenedor */
int atualizarContêiner(Nodo *cab, int id, float novaTara, float novoPesoCarga, float novoCusto) {
    Nodo *nodo = buscarContêiner(cab, id);
    if (nodo == NULL) {
        return 0; // No encontrado
    }

    nodo->dato.tara = novaTara;
    nodo->dato.pesoCarga = novoPesoCarga;
    nodo->dato.pesoTotal = novaTara + novoPesoCarga;
    nodo->dato.custo = novoCusto;
    return 1; // Actualizado con éxito
}

/* Eliminación de un contenedor de la lista doblemente enlazada */
int removerContêiner(Nodo **cab, int id) {
    Nodo *atual = buscarContêiner(*cab, id);
    if (atual == NULL) {
        return 0; // No encontrado
    }

    // Actualizar el enlace del nodo anterior
    if (atual->ant != NULL) {
        atual->ant->sig = atual->sig;
    } else {
        // El nodo a eliminar es la cabeza de la lista
        *cab = atual->sig;
    }

    // Actualizar el enlace del nodo siguiente
    if (atual->sig != NULL) {
        atual->sig->ant = atual->ant;
    }

    // Liberación de la memoria asignada
    free(atual);
    return 1;
}

/* Recorrido hacia adelante: de cabeza al último nodo */
void percorrerParaFrente(Nodo *cab) {
    if (cab == NULL) {
        printf("\nEl patio de contenedores esta vacio.\n");
        return;
    }

    printf("\n=== RECORRIDO HACIA ADELANTE (INICIO A FIN) ===\n");
    Nodo *atual = cab;
    while (atual != NULL) {
        showContêiner(&(atual->dato));
        atual = atual->sig;
    }
}

/* Recorrido hacia atrás: del último nodo a la cabeza */
void percorrerParaTras(Nodo *cab) {
    if (cab == NULL) {
        printf("\nEl patio de contenedores esta vacio.\n");
        return;
    }

    // Ubicamos el último nodo de la lista
    Nodo *atual = cab;
    while (atual->sig != NULL) {
        atual = atual->sig;
    }

    printf("\n=== RECORRIDO HACIA ATRAS (FIN A INICIO) ===\n");
    // Recorremos hacia atrás usando el puntero 'ant'
    while (atual != NULL) {
        showContêiner(&(atual->dato));
        atual = atual->ant;
    }
}

/* Liberar todos los nodos de la lista para evitar fugas de memoria */
void liberarLista(Nodo **cab) {
    Nodo *atual = *cab;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->sig;
        free(temp);
    }
    *cab = NULL;
}
