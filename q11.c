A:

#include <stdio.h>

// Função auxiliar com cauda para calcular fatorial
int fatorial_aux(int n, int acc) {
    if (n == 0) {
        return acc;
    } else {
        return fatorial_aux(n - 1, acc * n);
    }
}

// Função para calcular fatorial com cauda
int fatorial(int n) {
    return fatorial_aux(n, 1);
}

int main() {
    int n = 5;
    printf("fatorial de %d = %d\n", n, fatorial(n));
    return 0;
}

B:

#include <stdio.h>

// Função auxiliar com cauda para calcular f(n)
int f_aux(int n, int a, int b) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        return f_aux(n - 1, b, 2*b + 3*a);
    }
}

// Função para calcular f com cauda
int f(int n) {
    return f_aux(n, 1, 2);
}

int main() {
    int n = 5;
    printf("f(%d) = %d\n", n, f(n));
    return 0;
}

C:

#include <stdio.h>

// Função auxiliar com cauda para calcular a soma de k
int soma_k_aux(int n, int acc) {
    if (n == 0) {
        return acc;
    } else {
        return soma_k_aux(n - 1, acc + n);
    }
}

// Função auxiliar com cauda para calcular f(x, n)
float f_aux(float x, int n, float acc) {
    if (n == 0) {
        return x / acc;
    } else {
        return f_aux(x, n - 1, acc + n);
    }
}

// Função para calcular f com cauda
float f(float x, int n) {
    return f_aux(x, n, 0);
}

int main() {
    float x = 10.0;
    int n = 5;
    printf("f(%f, %d) = %f\n", x, n, f(x, n));
    return 0;
}
