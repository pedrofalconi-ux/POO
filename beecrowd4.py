import sys
from math import ceil

def minimo_tabuas(C, F, tabuas):
    freq = {}
    for t in tabuas:
        freq[t] = freq.get(t, 0) + 1

    usadas = 0
    faixas = F

    # Usa tábuas de comprimento exato
    exatas = min(freq.get(C, 0), faixas)
    usadas += exatas
    faixas -= exatas
    if C in freq:
        freq[C] -= exatas

    # Tenta formar pares
    pares = 0
    for x in list(freq.keys()):
        if freq[x] == 0:
            continue
        y = C - x
        if y < x:  # evitar duplicar pares
            continue
        if y not in freq or freq[y] == 0:
            continue

        if x == y:
            p = freq[x] // 2
        else:
            p = min(freq[x], freq[y])

        usar = min(p, faixas)
        pares += usar
        faixas -= usar
        freq[x] -= usar
        freq[y] -= usar

        if faixas == 0:
            break

    if faixas > 0:
        return None  # impossível
    return usadas + 2 * pares


def resolve(M, N, L, tabuas):
    largura = L / 100.0
    melhor = None

    # Orientação A
    if (N / largura).is_integer():
        F = int(N / largura)
        res = minimo_tabuas(M, F, tabuas)
        if res is not None:
            melhor = res if melhor is None else min(melhor, res)

    # Orientação B
    if (M / largura).is_integer():
        F = int(M / largura)
        res = minimo_tabuas(N, F, tabuas)
        if res is not None:
            melhor = res if melhor is None else min(melhor, res)

    return melhor


for linha in sys.stdin:
    M, N = map(int, linha.split())
    if M == 0 and N == 0:
        break
    L = int(sys.stdin.readline())
    K = int(sys.stdin.readline())
    tabuas = list(map(int, sys.stdin.readline().split()))
    res = resolve(M, N, L, tabuas)
    print(res if res is not None else "impossivel")
