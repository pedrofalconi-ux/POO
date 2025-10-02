#include <stdio.h>

int josephus(int n, int m) {
    int pos = 0;  // posição do sobrevivente (base 0)
    for (int i = 2; i <= n; i++) {
        pos = (pos + m) % i;
    }
    return pos + 1; // converte para base 1
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        int m = 1;
        while (1) {
            if (josephus(N - 1, m) == 12) { 
                // 12 porque eliminamos a região 1 primeiro,
                // então queremos que "13" seja a última → índice relativo = 12
                printf("%d\n", m);
                break;
            }
            m++;
        }
    }
    return 0;
}
