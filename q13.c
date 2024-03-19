(a) Somas sucessivas para calcular o produto de dois números:
#include <stdio.h>

// Função recursiva para calcular o produto de dois números usando somas sucessivas
int produto(int a, int b) {
    if (b == 0) {
        return 0;
    } else {
        return a + produto(a, b - 1);
    }
}

int main() {
    int a = 5;
    int b = 3;
    printf("Produto de %d e %d = %d\n", a, b, produto(a, b));
    return 0;
}

(b) Divisão inteira entre dois números através de subtrações sucessivas:
#include <stdio.h>

// Função recursiva para calcular a divisão inteira usando subtrações sucessivas
int divisao(int dividendo, int divisor) {
    if (dividendo < divisor) {
        return 0;
    } else {
        return 1 + divisao(dividendo - divisor, divisor);
    }
}

int main() {
    int dividendo = 20;
    int divisor = 4;
    printf("Divisão de %d por %d = %d\n", dividendo, divisor, divisao(dividendo, divisor));
    return 0;
}

(c) Verificação se uma palavra é um palíndromo:
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Função recursiva para verificar se uma string é um palíndromo
bool palindromo(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return true;
    }
    if (str[inicio] != str[fim]) {
        return false;
    }
    return palindromo(str, inicio + 1, fim - 1);
}

int main() {
    char palavra[] = "radar";
    int inicio = 0;
    int fim = strlen(palavra) - 1;
    if (palindromo(palavra, inicio, fim)) {
        printf("%s é um palíndromo.\n", palavra);
    } else {
        printf("%s não é um palíndromo.\n", palavra);
    }
    return 0;
}

(d) Inversão de uma string:
#include <stdio.h>
#include <string.h>

// Função recursiva para inverter uma string
void inverter_string(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inverter_string(str, inicio + 1, fim - 1);
}

int main() {
    char str[] = "hello";
    int inicio = 0;
    int fim = strlen(str) - 1;
    inverter_string(str, inicio, fim);
    printf("String invertida: %s\n", str);
    return 0;
}

(e) Geração de todos os números da megasena (6 números entre 1 e 60):
#include <stdio.h>

// Função recursiva para gerar combinações de números da megasena
void megasena(int numeros[], int posicao) {
    if (posicao == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", numeros[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= 60; i++) {
        numeros[posicao] = i;
        megasena(numeros, posicao + 1);
    }
}

int main() {
    int numeros[6];
    megasena(numeros, 0);
    return 0;
}
