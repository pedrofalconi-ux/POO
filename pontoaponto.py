import math

class Ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def distancia(a: Ponto, b: Ponto) -> float:
    return math.sqrt((a.x - b.x)**2 + (a.y - b.y)**2)

def main():
    # Lê o ponto de referência
    x, y = map(float, input("Digite o ponto (x y): ").split())
    p = Ponto(x, y)

    # Lê a quantidade de pontos
    n = int(input("Digite a quantidade de pontos: "))

    # Lê a lista de pontos
    pontos = []
    for i in range(n):
        x, y = map(float, input(f"Digite o ponto {i+1} (x y): ").split())
        pontos.append(Ponto(x, y))

    # Inicializa com o primeiro ponto
    indiceMaisProximo = 0
    menorDistancia = distancia(p, pontos[0])

    # Compara com os demais
    for i in range(1, n):
        d = distancia(p, pontos[i])
        if d < menorDistancia:
            menorDistancia = d
            indiceMaisProximo = i

    print(f"Ponto mais perto é ({pontos[indiceMaisProximo].x:.0f}, {pontos[indiceMaisProximo].y:.0f})")

if __name__ == "__main__":
    main()
