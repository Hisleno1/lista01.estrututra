#include <stdio.h>
#include <math.h>

// Função para encontrar a altura da árvore completa com base no número de nós
int alturaArvoreCompleta(int N) {
    return ceil(log2(N + 1)) - 1;
}

// Função para calcular o número total de nós em uma árvore completa com base na altura
int totalNosArvoreCompleta(int altura) {
    return pow(2, altura + 1) - 1;
}

// Função para calcular o número de nós a serem removidos para tornar uma árvore cheia completa
int nosRemovidosParaCompleta(int N) {
    int alturaAtual = alturaArvoreCompleta(N);
    int totalNosCompleta = totalNosArvoreCompleta(alturaAtual);
    return totalNosCompleta - N;
}

int main() {
    int N;
    printf("Digite o número de nós na árvore cheia: ");
    scanf("%d", &N);

    int nosRemovidos = nosRemovidosParaCompleta(N);

    printf("Número de nós a serem removidos para tornar a árvore completa: %d\n", nosRemovidos);

    return 0;
}
