#include <stdio.h>

// Função recursiva
double funcRecursiva(int n) {
    // Caso base
    if (n == 0) {
        return 1.0;
    }

    // Chamada recursiva
    double k = funcRecursiva(n - 1);

    // Retorna o resultado
    return k + 1.0 / k;
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Chamada da função
    double resultado = funcRecursiva(n);

    printf("Resultado: %.6f\n", resultado);

    return 0;
}
