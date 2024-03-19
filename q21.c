int main() {
    int n = 10;
    int soma = 0;
    for (int i = 0; i < n; i++) {  // Loop externo
        for (int j = 0; j < n; j++) {  // Loop interno
            soma += i + j;  // Operação de soma
        }
    }
    return 0;
}
