def soma(x, y):
    return x + y

def subtrai(x, y):
    return x - y

def multiplica(x, y):
    return x * y    

def divide(x, y):
    if y == 0:
        return "Erro: Divisão por zero!"
    return x / y

while True:
    print("Selecione a operação:")
    print("1. Soma")
    print("2. Subtração")
    print("3. Multiplicação")
    print("4. Divisão")
    print("5. Sair")

    escolha = input("Digite sua escolha (1/2/3/4/5): ")

    if escolha in ['1', '2', '3', '4']:
        num1 = float(input("Digite o primeiro número: "))
        num2 = float(input("Digite o segundo número: "))

        if escolha == '1':
            print(f"{num1} + {num2} = {soma(num1, num2)}")

        elif escolha == '2':
            print(f"{num1} - {num2} = {subtrai(num1, num2)}")

        elif escolha == '3':
            print(f"{num1} * {num2} = {multiplica(num1, num2)}")

        elif escolha == '4':
            resultado = divide(num1, num2)
            print(f"{num1} / {num2} = {resultado}")

    elif escolha == '5':
        print("Saindo...")
        break

    else:
        print("Entrada inválida")