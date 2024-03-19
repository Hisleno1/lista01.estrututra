def fibonacci(n, count, m):
    if n <= 1:
        return n
    else:
        count[0] += 1  # Incrementa o contador de chamadas de fibonacci(n)
        return fibonacci(n - 1, count, m) + fibonacci(n - 2, count, m)

def fibonacci_count_between_n_and_m(n, m):
    count = [0]  # Lista para armazenar o contador de chamadas
    fibonacci_result = fibonacci(m, count, n)
    return count[0]

n = int(input("Digite o valor de n para calcular o Fibonacci (n < m): "))
m = int(input("Digite o valor de m para calcular o Fibonacci (m > n): "))

if m <= n:
    print("Por favor, digite um número m maior que n.")
else:
    fibonacci_count = fibonacci_count_between_n_and_m(n, m)
    print("Número de vezes que fibonacci(n) foi calculado para encontrar fibonacci(m):", fibonacci_count)
