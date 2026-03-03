def to_num(word):
    if word == "um":
        return 0
    if word == "dois":
        return 1
    if word == "tres":
        return 2

def to_fig(word):
    if word.startswith("circul"):
        return 0
    if word.startswith("quadrad"):
        return 1
    if word.startswith("triangul"):
        return 2

while True:
    N = int(input())
    if N == 0:
        break

    count = [[0]*3 for _ in range(3)]

    for _ in range(N):
        num, fig = input().split()
        count[to_num(num)][to_fig(fig)] += 1

    # Representar tipos como lista linear 0..8
    cards = [(i, j) for i in range(3) for j in range(3)]
    freq = [count[i][j] for i in range(3) for j in range(3)]

    sets = 0

    # Primeiro: sets de 3 cartas iguais
    for f in freq:
        sets += f // 3

    # Depois: sets de 3 tipos diferentes
    for i in range(9):
        for j in range(i + 1, 9):
            for k in range(j + 1, 9):
                (a1, b1) = cards[i]
                (a2, b2) = cards[j]
                (a3, b3) = cards[k]
                if (a1 + a2 + a3) % 3 == 0 and (b1 + b2 + b3) % 3 == 0:
                    m = min(freq[i], freq[j], freq[k])
                    sets += m
                    freq[i] -= m
                    freq[j] -= m
                    freq[k] -= m

    print(sets)
