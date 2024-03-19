#include <stdio.h>
#include <math.h>

// Função para calcular a altura máxima do nó raiz em uma árvore estritamente binária com N nós
int alturaMaxima(int N) {
    return log2(N + 1) - 1;
}

int main() {
    int N;
    printf("Digite o número de nós na árvore estritamente binária: ");
    scanf("%d", &N);

    int altura = alturaMaxima(N);

    printf("Altura máxima do nó raiz: %d\n", altura);

    return 0;
}
