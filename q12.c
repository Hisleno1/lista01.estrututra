#include <stdio.h>
#include <math.h>

// Função para calcular a tangente
double tan(double x) {
    return sin(x) / cos(x);
}

// Função para calcular o cosseno
double cos(double x) {
    return 1 - (sin(x) * sin(x));
}

// Função para calcular o seno usando a fórmula de recorrência fornecida
double sin(double x) {
    if (x < 0.0001) {
        return x - (x*x*x)/6.0;
    } else {
        double temp = sin(x/3);
        return 3 * temp - 4 * pow(temp, 3);
    }
}

int main() {
    double x = 80.0 * M_PI / 180.0; // Convertendo para radianos
    printf("sin(80) = %.6f\n", sin(x));
    return 0;
}
