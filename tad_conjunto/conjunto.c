#include "conjunto.h"

#include <stdio.h>
#include <string.h>

void inicializa(t_conjunto A) {
    memset(A, 0, sizeof(t_conjunto));
}


void uniao(t_conjunto A, t_conjunto B, t_conjunto C) {
    for (int i = 0; i < max; i++) {
        C[i] = A[i] || B[i];
    }
}
void interseccao(t_conjunto A, t_conjunto B, t_conjunto C){
    for (int i = 0; i < max; i++) {
        C[i] = A[i] && B[i];
    }
}

int pertence(t_elemento e, t_conjunto A) {
    
    if (e < 0 || e >= max) {
        printf("Posição/elemento inválido.\n");
        return -1;
    }
    
    return A[e];
}

void insercao(t_elemento e, t_conjunto A) {
    
    if (e < 0 || e >= max) {
        printf("Posição/elemento inválido.\n");
        return;
    }
    
    if (pertence(e, A)) 
        printf("Elemento já foi inserido.\n");
        
    A[e] = 1;
    
}

void remocao(t_elemento e, t_conjunto A){
    
    if (e < 0 || e >= max) {
        printf("Posição/elemento inválido.\n");
        return;
    }
    
    if (!pertence(e, A)) 
        printf("Elemento não estava no conjunto.\n");
        
    A[e] = 0;
    
}

void imprime_conjunto(t_conjunto A) {
    printf("{");
    for (int i = 0; i < max; i++)
        if (pertence(i, A))
            printf("%d,", i);
    printf("}\n");
}
