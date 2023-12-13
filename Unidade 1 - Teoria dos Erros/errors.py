x = float(input("Digite o numero exato: "))
x_ = float(input("Digite o numero aproximado: "))

err_abs = abs(x - x_)
err_rel = err_abs / x_

print(f"Erro Absoluto: {err_abs}\nErro Relativo: {err_rel}")