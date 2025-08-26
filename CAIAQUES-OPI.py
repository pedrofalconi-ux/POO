n = int(input())
weights = list(map(int, input().split()))
weights.sort()

min_instability = float('inf')

# Testar todas as combinações possíveis de 2 elementos para os caiaques individuais
for i in range(len(weights)):
    for j in range(i + 1, len(weights)):
        instability = weights[i] + weights[j]  # Instabilidade dos individuais
        
        remaining = []
        for k in range(len(weights)):
            if k != i and k != j:
                remaining.append(weights[k])
        
        # Parear os elementos restantes sequencialmente
        for k in range(0, len(remaining), 2):
            if k + 1 < len(remaining):
                instability += remaining[k + 1] - remaining[k]
        
        if instability < min_instability:
            min_instability = instability

print(min_instability)