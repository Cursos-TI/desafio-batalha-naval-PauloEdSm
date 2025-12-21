#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define NAVIOS 5

int tamanhos[NAVIOS] = {5, 4, 3, 3, 2};

/* Inicializa o tabuleiro com água */
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

/* Exibe o tabuleiro
   ocultar = 1 → não mostra navios
   ocultar = 0 → mostra tudo */
void mostrarTabuleiro(int tabuleiro[TAM][TAM], int ocultar) {
    printf("  ");
    for (int i = 0; i < TAM; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            if (ocultar && tabuleiro[i][j] == 1)
                printf("~ ");
            else if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 1)
                printf("N ");
            else if (tabuleiro[i][j] == 2)
                printf("O ");
            else if (tabuleiro[i][j] == 3)
                printf("X ");
        }
        printf("\n");
    }
}

/* Verifica se um navio pode ser colocado */
int podeColocar(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, int horizontal) {
    if (horizontal) {
        if (coluna + tamanho > TAM) return 0;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha][coluna + i] != 0) return 0;
    } else {
        if (linha + tamanho > TAM) return 0;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    return 1;
}

/* Coloca um navio no tabuleiro */
void colocarNavio(int tabuleiro[TAM][TAM], int tamanho) {
    int linha, coluna, horizontal;

    do {
        linha = rand() % TAM;
        coluna = rand() % TAM;
        horizontal = rand() % 2;
    } while (!podeColocar(tabuleiro, linha, coluna, tamanho, horizontal));

    for (int i = 0; i < tamanho; i++) {
        if (horizontal)
            tabuleiro[linha][coluna + i] = 1;
        else
            tabuleiro[linha + i][coluna] = 1;
    }
}

/* Posiciona todos os navios automaticamente */
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < NAVIOS; i++) {
        colocarNavio(tabuleiro, tamanhos[i]);
    }
}

/* Executa um tiro no tabuleiro */
int atirar(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == 1) {
        tabuleiro[linha][coluna] = 3;
        return 1;
    } else if (tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = 2;
    }
    return 0;
}

/* Conta quantas partes de navios ainda existem */
int naviosRestantes(int tabuleiro[TAM][TAM]) {
    int count = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (tabuleiro[i][j] == 1)
                count++;
    return count;
}

/* Turno do jogador */
void turnoJogador(int inimigo[TAM][TAM]) {
    int linha, coluna;
    printf("\nSeu turno!\n");
    do {
        printf("Linha: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
    } while (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM);

    if (atirar(inimigo, linha, coluna))
        printf("Acertou um navio!\n");
    else
        printf("Errou!\n");
}

/* Turno do computador */
void turnoComputador(int jogador[TAM][TAM]) {
    int linha, coluna;
    do {
        linha = rand() % TAM;
        coluna = rand() % TAM;
    } while (jogador[linha][coluna] == 2 || jogador[linha][coluna] == 3);

    printf("\nComputador atirou em %d %d\n", linha, coluna);
    atirar(jogador, linha, coluna);
}

int main() {
    int jogador[TAM][TAM];
    int computador[TAM][TAM];

    srand(time(NULL));

    inicializarTabuleiro(jogador);
    inicializarTabuleiro(computador);

    posicionarNavios(jogador);
    posicionarNavios(computador);

    while (1) {
        printf("\n=== SEU TABULEIRO ===\n");
        mostrarTabuleiro(jogador, 0);

        printf("\n=== TABULEIRO INIMIGO ===\n");
        mostrarTabuleiro(computador, 1);

        turnoJogador(computador);
        if (naviosRestantes(computador) == 0) {
            printf("\nVOCÊ VENCEU!\n");
            break;
        }

        turnoComputador(jogador);
        if (naviosRestantes(jogador) == 0) {
            printf("\nVOCÊ PERDEU!\n");
            break;
        }
    }

    return 0;
}
