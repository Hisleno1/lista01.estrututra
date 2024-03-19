def fibonacci(n, count):
    if n <= 1:
        return n
    else:
        count[0] += 1  # Incrementa o contador de chamadas de fibonacci(4)
        return fibonacci(n - 1, count) + fibonacci(n - 2, count)

count = [0]  # Lista para armazenar o contador de chamadas
result = fibonacci(8, count)
print("Fibonacci de 8:", result)
print("Número de vezes que fibonacci(4) foi calculado:", count[0])
