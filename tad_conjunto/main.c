#include <stdio.h>
#include <string.h>

#include "conjunto.h"

int main() {
    
    t_conjunto A, B, C;
    
    inicializa(A);
    inicializa(B);
    inicializa(C);
    
    insercao(2,A);
    insercao(22,A);
    //insercao(222,A);
    
    remocao(2,A);
    
    insercao(10,A);
    insercao(20,A);
    insercao(30,A);
    insercao(40,A);
    
    insercao(50,B);
    insercao(60,B);
    insercao(70,B);
    insercao(80,B);
    
    imprime_conjunto(A);
    imprime_conjunto(B);
    
    uniao(A, B, C);
    imprime_conjunto(C);
    
    interseccao(A, B, C);
    imprime_conjunto(C);

    return 0;
}
