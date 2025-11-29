def numero_que_falta_xor(v):
    n = len(v)
    xor_total = 0
    
    # XOR de todos números de 1 a n+1
    for i in range(1, n + 2):
        xor_total ^= i

    # XOR com os números da lista
    for num in v:
        xor_total ^= num

    return xor_total

# Exemplo
lista = [3, 1, 2, 5]
print("Número faltando (XOR):", numero_que_falta_xor(lista))