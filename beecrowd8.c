#include <stdio.h>

int main() {
    double A, B, media;

    // Leitura das duas notas
    scanf("%lf", &A);
    scanf("%lf", &B);

    // Cálculo da média ponderada
    media = (A * 3.5 + B * 7.5) / 11.0;

    // Impressão com o formato exigido
    printf("MEDIA = %.5lf\n", media);

    return 0;
}
