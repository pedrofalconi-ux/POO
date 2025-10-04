#include <stdio.h>

int main() {
    double A, B, C, media;

    // Leitura das três notas
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    // Cálculo da média ponderada
    media = (A * 2.0 + B * 3.0 + C * 5.0) / 10.0;

    // Impressão com 1 casa decimal
    printf("MEDIA = %.1lf\n", media);

    return 0;
}
