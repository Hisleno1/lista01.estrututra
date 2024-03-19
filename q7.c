def bissexto(ano):
    if (ano % 4 == 0 and ano % 100 != 0) or (ano % 400 == 0):
        return True
    else:
        return False

ano = int(input("Digite o ano para verificar se é bissexto: "))
if bissexto(ano):
    print(ano, "é um ano bissexto.")
else:
    print(ano, "não é um ano bissexto.")
