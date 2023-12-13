entrada = num = int(input("Digite um numero decimal: "))

saida = ""
while num > 0:
    resto = num % 2
    saida = str(resto) + saida
    num = num // 2

print(f"Decimal: {entrada}\nBinario: {saida}")
