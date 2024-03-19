
#include <stdio.h>

// Função recursiva
double funcRecursiva(int n, double *tempo) {
    // Tempo de chamada recursiva
    *tempo += 2.0;

    // Caso base
    if (n == 0) {
        return 1.0;
    }

    // Chamada recursiva e operações
    double resultado = funcRecursiva(n - 1, tempo) + 1.0 / funcRecursiva(n - 1, tempo);

    // Tempo de retorno da chamada recursiva
    *tempo += 1.0;

    return resultado;
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    double tempo = 0.0;

    // Chamada da função
    double resultado = funcRecursiva(n, &tempo);

    printf("Resultado: %.6f\n", resultado);
    printf("Tempo total de execução: %.2f ns\n", tempo);

    return 0;
}
