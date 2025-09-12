def funcao():
    numeros = []
    maior = None
    
    for i in range(3):
        n = int(input(f"Digite o {i+1}º número: "))
        numeros.append(n)
        
        if i == 0 or n > maior:
            maior = n

    print(f"Maior número: {maior}")
    return maior


def main():
    funcao()


if __name__ == "__main__":
    main()
