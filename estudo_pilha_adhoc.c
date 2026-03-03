#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Estrutura de pilha
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

// Funções da pilha
void inicializa(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, char c) {
    if (p->topo < MAX - 1)
        p->itens[++p->topo] = c;
}

char pop(Pilha *p) {
    if (!vazia(p))
        return p->itens[p->topo--];
    return '\0';
}

int combina(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

// Função principal que verifica o balanceamento
int balanceada(const char *s) {
    Pilha p;
    inicializa(&p);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (vazia(&p) || !combina(pop(&p), c))
                return 0; // Não balanceada
        }
    }

    return vazia(&p); // Balanceada se pilha estiver vazia
}

int main() {
    char expressao[MAX];

    printf("Digite a expressao: ");
    scanf("%s", expressao);

    if (balanceada(expressao))
        printf("Balanceada\n");
    else
        printf("Nao balanceada\n");

    return 0;
}
