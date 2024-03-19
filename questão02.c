def fibonacci(n, count):
    if n <= 1:
        return n
    else:
        count[0] += 1  # Incrementa o contador de chamadas de fibonacci(4)
        return fibonacci(n - 1, count) + fibonacci(n - 2, count)

def fibonacci_with_count(n):
    count = [0]  # Lista para armazenar o contador de chamadas
    result = fibonacci(n, count)
    return result, count[0]

n = int(input("Digite o valor de n para calcular o Fibonacci (n > 4): "))
if n <= 4:
    print("Por favor, digite um número maior que 4.")
else:
    fibonacci_result, fibonacci_4_count = fibonacci_with_count(n)
    print("Fibonacci de", n, ":", fibonacci_result)
    print("Número de vezes que fibonacci(4) foi calculado:", fibonacci_4_count)
