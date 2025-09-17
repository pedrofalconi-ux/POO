def bit_shock(p):
    steps = 0
    while p != 1:
        if p & 1:  # tem constante
            p = ((p << 1) ^ p) ^ 1
        else:      # sem constante
            p >>= 1
        steps += 1
    return steps

print(bit_shock(0b1001))  # x^3 + 1
