#include <stdio.h>
#include<stdbool.h>
#include<sdtlib.h>
#include<time.h>
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

    //Definir status do jogador caso ele perca
    bool status = true;

    while(status == false) {

        printf("Digite a coordenada Y\n-> ");
        scanf("%d", &coordenadaY);

        printf("Digite a coordenada X \n->");
        scanf("%d", &coordenadaX);


        
    }


    //Método para exibição do tabuleiro
    void exibirTabuleiro(int tabuleiro [10][10]){

        for (int contadorY = 0; contadorY < 9; contadorY++){
                
                printf("\n--------------------\n");

                for(int contadorX = 0; contadorX < 9; contadorX++){
                
                    printf("%s%d%s",());

                }
                    }
                        }

            int gerar_frota[10][10] (int tabuleiro [10][10]) {
                
                return tabuleiro;

            }

            int
    return 0;
}
