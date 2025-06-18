#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int i;

    // Coordenadas dos navios (ajuste se quiser)
    int l1 = 2, c1 = 4; // horizontal
    int l2 = 5, c2 = 7; // vertical

    // Validação simples para não sair do tabuleiro
    if (c1 + NAVIO > TAM || l2 + NAVIO > TAM) {
        printf("Navio fora dos limites!\n");
        return 1;
    }

    // Posiciona navio horizontal
    for (i = 0; i < NAVIO; i++)
        tabuleiro[l1][c1 + i] = 3;

    // Posiciona navio vertical (verifica sobreposição)
    for (i = 0; i < NAVIO; i++) {
        if (tabuleiro[l2 + i][c2] == 3) {
            printf("Sobreposição de navios!\n");
            return 1;
        }
        tabuleiro[l2 + i][c2] = 3;
    }

    // Exibe o tabuleiro
    for (int l = 0; l < TAM; l++) {
        for (int c = 0; c < TAM; c++)
            printf("%d ", tabuleiro[l][c]);
        printf("\n");
    }
    return 0;
}