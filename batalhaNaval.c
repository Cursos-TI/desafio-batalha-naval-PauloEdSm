#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#define TAMANHO 9
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    //Logica do tabuleiro batalha naval:
        //--Primeiro elemento: 
            //--Armazena a coordenada "X" do tabuleiro

        //--Segundo elemento: 
            //--Armazena a coordenada "Y" do tabuleiro

                //--Armazena o estado da posição no tabuleiro sendo eles:

                    //--0 :
                        //Condiz ao estado vazio e ausente de "bombas" da posição dada no tabuleiro
        

                    //--1 :
                        //Condiz ao estado em que já há um navio presente naquela posição


                    //--2 :
                        //Condiz ao estado vazio porém com uma "bomba" posicionada da posição dada no tabuleiro

    int tabuleiro [10][10];
    
    int coordenadaY;
    int coordenadaX;

    srand(time(NULL));


void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    
    // 1. Imprime os indices das COLUNAS (Cabecalho)
    printf("\n   "); // Espaco para alinhar com o indice da linha
    for (int i = 0; i < TAMANHO; i++) {
        printf(" %d ", i);
    }
    printf("\n");

    // Loop para as LINHAS (Y)
    for (int contadorY = 0; contadorY < TAMANHO; contadorY++) {
        
        // Imprime a l9inha divisoria (antes do conteudo de cada linha, exceto o topo)
        printf("  +");
        for (int i = 0; i < TAMANHO; i++) {
            printf("---");
        }
        printf("+\n");

        // Imprime o indice da LINHA (Y)
        printf("%d ", contadorY); 

        // Loop para as COLUNAS (X) e os dados
        for (int contadorX = 0; contadorX < TAMANHO; contadorX++) {
            
            // Imprime o divisor vertical e o valor
            printf("|%2d", tabuleiro[contadorY][contadorX]); // Usando %2d para garantir espacamento uniforme
        }
        
        // Fecha a linha com divisor vertical e quebra de linha
        printf("|\n");
    }
    
    // Imprime a linha divisoria final
    printf("  +");
    for (int i = 0; i < TAMANHO; i++) {
        printf("---");
    }
    printf("+\n");
}



    //Definir status do jogador caso ele perca
    bool status = true;




    return 0;
}
