#include <stdio.h>
#include <math.h>

#define MAXP 40000

int primos[MAXP];
int nprimos = 0;

void gera_primos() {
    int limite = 40000;
    int marc[40000] = {0};
    for (int i = 2; i < limite; i++) {
        if (!marc[i]) {
            primos[nprimos++] = i;
            for (int j = i * 2; j < limite; j += i)
                marc[j] = 1;
        }
    }
}

int main() {
    int n;
    gera_primos(); 

    while (scanf("%d", &n) && n != 0) {
        int pessoas[3501];
        for (int i = 0; i < n; i++) pessoas[i] = i + 1;

        int idx = 0;  // índice atual
        int tam = n;

        for (int i = 0; i < n - 1; i++) {
            int m = primos[i];  // i-ésimo primo
            idx = (idx + m - 1) % tam;
            // remove pessoa
            for (int j = idx; j < tam - 1; j++)
                pessoas[j] = pessoas[j + 1];
            tam--;
            // idx já está no próximo automaticamente
        }

        printf("%d\n", pessoas[0]);
    }

    return 0;
}
