#include "contêiner.h"
#include <stdio.h>

void showContêiner(const Contêiner *c) {
    printf("----------------------------------------\n");
    printf("ID Contêiner        : %d\n", c->id);
    printf("Peso vazio (tara)         : %.2f kg\n", c->tara);
    printf("Peso da Carga       : %.2f kg\n", c->pesoCarga);
    printf("Peso Total          : %.2f kg\n", c->pesoTotal);
    printf("Custo Associado     : $%.2f\n", c->custo);
    printf("----------------------------------------\n");
}
