#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <ctype.h>


/* Digitar lista, entra com arquivo, aleatóriamente, gerar lista a partir de trechos da matriz*/

// Protótipos de funções
void digitarMatriz();
void menuSegundario();
int buscarPalavras(char[32], char[32][32], int, int);
void lerArquivo(char [32][32]);
void gerarMatrizAleatoria(char [32][32]);
void imprime_matriz(char [32][32], int, int);
void escreveArquivo(char [32][32], int, int);




int main() {

    FILE * pFile;

    int opcao;
    char matriz[32][32];
    srand(time(0));

    do
    {

        printf("Escolha uma das opções abaixo\n\n");
        printf("0 - Ajuda de utilização\n");
        printf("1 - Digitar matriz\n");
        printf("2 - Gerar matriz aleatóriamente\n");
        printf("3 - Gerar matriz a partir de um arquivo\n");
        printf("4 - Sair\n");
        scanf("%d",&opcao);

        getchar ();
        switch (opcao)
        {
            case 0:
                break;
            case 1:
                digitarMatriz();
                break;
            case 2:
                gerarMatrizAleatoria(matriz);
                break;
            case 3:
                lerArquivo(matriz);
                break;
            case 4: printf("Encerrando aplicação, até breve...\n");
                break;
            default: printf("Opção inválida !\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}


void digitarMatriz() {

    int linhas, colunas;
    char matriz[32][32];

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);


    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna < colunas; ++coluna) {

            printf("Digite o caractere: ");
            getchar ();
            scanf("%c", &matriz[linha][coluna]);

        }

    }

    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna <= colunas; ++coluna) {

            if (coluna == colunas) {

                printf("\n");
            } else {

                //printf("%.2d, %.2d \t", linha, coluna);
                printf("%c ", matriz[linha][coluna]);
            }

        }
    }
    escreveArquivo(matriz, linhas, colunas);

}

void gerarMatrizAleatoria(char matriz[32][32]) {

    char opcao;
    int linhas, colunas;
    printf("Deseja escolher o número de linhas e colunas ? [N/s]: ");
    scanf("%c", &opcao);

    switch (opcao){

        case 'N':
            printf("Não\n");
            linhas = 5 + rand() % (32 - 5);
            colunas = 5 + rand() % (32 - 5);
            break;
        case 's':
            printf("Sim\n");

            printf("Digite o número de linhas: ");
            scanf("%d", &linhas);

            printf("Digite o número de colunas: ");
            scanf("%d", &colunas);
            break;
        default:
            printf("Não\n");
            linhas = 5 + rand() % (32 - 5);
            colunas = 5 + rand() % (32 - 5);
    }

    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna < colunas; ++coluna) {

            matriz[linha][coluna] = 'A' + (rand() % 26);
        }
    }

    escreveArquivo(matriz, linhas, colunas);
    imprime_matriz(matriz, linhas, colunas);
    //buscarPalavras("BALA", matriz, linhas, colunas);

}

void imprime_matriz(char matriz[32][32], int linhas, int colunas) {

    //printf("%c", matriz[0][0]);
    //escreveArquivo(matriz, linhas, colunas);
    //buscarPalavras("BALA", matriz, linhas, colunas);
    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna <= colunas; ++coluna) {

            if (coluna == colunas) {

                printf("\n");
            } else {

                //printf("%.2d, %.2d \t", linha, coluna);
                printf("%c ", matriz[linha][coluna]);
            }

        }
    }

    buscarPalavras("BALA", matriz, linhas, colunas);
    menuSegundario();
}

void lerArquivo(char matriz[32][32]) {

    FILE *arquivo;
    int linhas, colunas;
    char buffer [100];
    char origemArquivo[64];
    printf("Digite o caminho ou nome no arquivo: ");
    //getchar ();
    //scanf("%s", origemArquivo);

    arquivo = fopen ("temporario.txt" , "r+t");
    printf("%s\n", origemArquivo);
    if (arquivo == NULL) perror ("Erro ao abrir o arquivo, verifique o caminho ou nome");

    else {
        printf("czcz\n");

        fscanf(arquivo, "%d", &linhas);
        printf("%d\n", linhas);
        fscanf(arquivo, "%d", &colunas);
        printf("%d", colunas);

        for (int linha = 0; linha < linhas; linha++) {
            for (int coluna = 0; coluna < colunas; coluna++) {


                fscanf(arquivo, " %c", &matriz[linha][coluna]);

                //printf("%c*", matriz[linha][coluna]);
            }
        }
//        while (EOF != fscanf(arquivo, "%[^\n]\n", buffer))
//        {
//
//            // sprintf(palavras[i].palavra, "%s", buffer);2                                    temporario.txt
//            // printf("> %s\n", buffer);
//            // insere_palava(buffer, matriz, controle, 3);
//            // //imprime_matriz(matriz);
//            // i++;
//            // printf("%s", palavras[i-1].palavra);
//        }
        fclose(arquivo);

    }
    printf("\n");
       imprime_matriz(matriz, linhas, colunas);

    // imprime_matriz(matriz);
    // imprime_controle(controle);
}


void escreveArquivo(char matriz[32][32], int linhas,int colunas) {

    FILE *arquivo;

    arquivo = fopen ("temporario.txt" , "w");

    fprintf(arquivo, "%d\n%d\n", linhas, colunas);
    fflush(arquivo);
    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna <= colunas; ++coluna) {

            if (coluna == colunas) {

                fprintf(arquivo, "\n");
                fflush(arquivo);
            } else {

                //printf("%.2d, %.2d \t", linha, coluna);
                fprintf(arquivo, "%c", matriz[linha][coluna]);
                fflush(arquivo);
            }

        }
    }
    fclose(arquivo);
    printf("\n");
    // imprime_matriz(matriz);
    // imprime_controle(controle);
}

void menuSegundario() {

/* Digitar lista, entra com arquivo, aleatóriamente, gerar lista a partir de trechos da matriz*/
    int opcao;
    do
    {

        printf("Escolha uma das opções abaixo\n\n");
        printf("0 - Ajuda de utilização\n");
        printf("1 - Digitar lista\n");
        printf("2 - Entrar com arquivo\n");
        printf("3 - Aleatóriamente\n");
        printf("4 - Gerar lista a partir de trechos da matriz\n");
        printf("5 - Voltar ao menu anterior\n");
        printf("6 - Sair\n");
        scanf("%d",&opcao);

        getchar ();
        switch (opcao)
        {
            case 0:
                break;
            case 1:
                //digitarMatriz();
                break;
            case 2:
                //gerarMatrizAleatoria(matriz);
                break;
            case 3:
                //lerArquivo(pFile);
                break;
            case 4:
                //lerArquivo(pFile);
                break;
            case 5:
                //lerArquivo(pFile);
                break;
            case 6: printf("Encerrando aplicação, até breve...\n");
                exit(0);
                break;
            default: printf("Opção inválida !\n");
                break;
        }

    } while (opcao != 4);
}


int buscarPalavras(char palavra[32], char matriz[32][32], int linhas, int colunas) {

    int direcao = 0;
    int tamanhoPalavra = strlen(palavra);

    for (int linha = 0; linha < linhas; ++linha) {
        for (int coluna = 0; coluna <= colunas; ++coluna) {

            if (matriz[linha][coluna] == palavra[0]) {

                //printf("Letra igual em (%d, %d)\n", linha, coluna);

                if (matriz[linha][coluna + 1] == palavra[1] && coluna + tamanhoPalavra <= colunas) { // -->

                    direcao = 1;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);


                }  if (matriz[linha + 1][coluna] == palavra[1] && linha + tamanhoPalavra <= linhas){ // .|


                    direcao = 2;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);

                }  if (matriz[linha][coluna - 1] == palavra[1] && coluna - tamanhoPalavra  >= -1){ // <--


                    direcao = 3;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);

                }  if (matriz[linha - 1][coluna] == palavra[1] && linha - tamanhoPalavra  >= -1){ // ^


                    direcao = 4;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);

                }  if (matriz[linha - 1][coluna + 1] == palavra[1] && linha - tamanhoPalavra  >= -1 && coluna + tamanhoPalavra <= colunas){ // /^


                    direcao = 5;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);

                } if (matriz[linha - 1][coluna - 1] == palavra[1] && coluna - tamanhoPalavra  >= -1 && linha - tamanhoPalavra  >= -1){ // ^\


                    direcao = 6;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);

                }  if (matriz[linha + 1][coluna - 1] == palavra[1] && linha + tamanhoPalavra <= linhas && coluna - tamanhoPalavra  >= -1){ // ./


                    direcao = 7;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);

                }  if (matriz[linha + 1][coluna + 1] == palavra[1] && coluna + tamanhoPalavra <= colunas && linha + tamanhoPalavra <= linhas){ // \.


                    direcao = 8;
                    printf("%d - Letra igual em (%d, %d)\n", direcao, linha, coluna);

                }
            }

        }
    }
    return direcao;

}

//int encontra(char busca[32], ){
//
//
//}
