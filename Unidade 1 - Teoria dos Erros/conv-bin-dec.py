entrada = input("Digite um numero binario: ")

b = 0
for a in entrada:
    a = int(a)
    b = a + 2*b

print(f"Binario: {entrada}\nDecimal: {b}")