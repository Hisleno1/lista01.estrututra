#include <stdio.h>

// Função para calcular p(x, n) sem cauda
int p_sem_cauda(int x, int n) {
    if (n == 0) {
        return x;
    } else {
        return (x - n) * p_sem_cauda(x, n - 1);
    }
}

int main() {
    int x = 5;
    int n = 3;
    printf("p(%d, %d) = %d\n", x, n, p_sem_cauda(x, n));
    return 0;
}

Implementação com cauda:


#include <stdio.h>

// Função auxiliar com cauda para calcular p(x, n)
int p_com_cauda_aux(int x, int n, int acc) {
    if (n == 0) {
        return acc;
    } else {
        return p_com_cauda_aux(x, n - 1, acc * (x - n));
    }
}

// Função para calcular p(x, n) com cauda
int p_com_cauda(int x, int n) {
    return p_com_cauda_aux(x, n, x);
}

int main() {
    int x = 5;
    int n = 3;
    printf("p(%d, %d) = %d\n", x, n, p_com_cauda(x, n));
    return 0;
}
